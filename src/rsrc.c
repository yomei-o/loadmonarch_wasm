#include "rsrc.h"

#include <stdio.h>
#include <string.h>

static unsigned rd16(const unsigned char *p) {
    return (unsigned)p[0] | ((unsigned)p[1] << 8);
}

static unsigned rd32(const unsigned char *p) {
    return (unsigned)p[0] | ((unsigned)p[1] << 8) | ((unsigned)p[2] << 16) |
           ((unsigned)p[3] << 24);
}

int peOpen(Pe *pe, const unsigned char *image, unsigned size) {
    memset(pe, 0, sizeof *pe);
    if (!image || size < 0x40) return 0;
    if (image[0] != 'M' || image[1] != 'Z') return 0;
    const unsigned at = rd32(image + 0x3c);
    if (at + 0x78 > size) return 0;
    if (memcmp(image + at, "PE\0\0", 4) != 0) return 0;
    const unsigned opt = rd16(image + at + 20);
    pe->image = image;
    pe->size = size;
    pe->sections = rd16(image + at + 6);
    pe->sectionAt = at + 24 + opt;
    pe->base = rd32(image + at + 24 + 28);
    if (pe->sectionAt + pe->sections * 40u > size) return 0;
    return 1;
}

// An RVA to a file offset, through the section table.
static unsigned peOffset(const Pe *pe, unsigned rva) {
    for (unsigned i = 0; i < pe->sections; i++) {
        const unsigned char *e = pe->image + pe->sectionAt + i * 40u;
        const unsigned va = rd32(e + 12), vsz = rd32(e + 8);
        const unsigned rsz = rd32(e + 16), ra = rd32(e + 20);
        const unsigned span = vsz > rsz ? vsz : rsz;
        if (rva >= va && rva < va + span) return ra + (rva - va);
    }
    return 0;
}

// The resource directory's root RVA, out of the optional header's table.
static unsigned rsrcRoot(const Pe *pe, unsigned *sizeOut) {
    const unsigned char *image = pe->image;
    const unsigned at = rd32(image + 0x3c);
    const unsigned magic = rd16(image + at + 24);
    // The data directory starts at 96 into a PE32 optional header and 112 into
    // a PE32+ one; this executable is PE32, and the other is here so a wrong
    // read is a wrong read rather than a crash.
    const unsigned dirs = at + 24 + (magic == 0x20b ? 112u : 96u);
    if (dirs + 16 > pe->size) return 0;
    const unsigned rva = rd32(image + dirs + 8 * 2);
    if (sizeOut) *sizeOut = rd32(image + dirs + 8 * 2 + 4);
    return rva;
}

// One level of the tree: the entry whose id matches, or the first entry when
// `id` is ~0u.  Answers the entry's offset field, with bit 31 meaning "another
// directory".
static unsigned dirLook(const Pe *pe, unsigned dirOffset, unsigned id) {
    const unsigned char *d = pe->image + dirOffset;
    if (dirOffset == 0 || dirOffset + 16 > pe->size) return 0;
    const unsigned named = rd16(d + 12), ids = rd16(d + 14);
    for (unsigned i = 0; i < named + ids; i++) {
        const unsigned char *e = d + 16 + i * 8;
        const unsigned name = rd32(e);
        if (id == ~0u || (!(name & 0x80000000u) && name == id))
            return rd32(e + 4);
    }
    return 0;
}

const unsigned char *peResource(const Pe *pe, unsigned type, unsigned id,
                                unsigned *length) {
    unsigned rootSize = 0;
    const unsigned root = rsrcRoot(pe, &rootSize);
    const unsigned rootOff = peOffset(pe, root);
    if (!rootOff) return NULL;

    unsigned e = dirLook(pe, rootOff, type);
    if (!(e & 0x80000000u)) return NULL;
    e = dirLook(pe, rootOff + (e & 0x7fffffffu), id);
    if (!(e & 0x80000000u)) return NULL;
    e = dirLook(pe, rootOff + (e & 0x7fffffffu), ~0u);   // any language
    if (e & 0x80000000u) return NULL;
    const unsigned leaf = rootOff + e;
    if (leaf + 16 > pe->size) return NULL;
    const unsigned dataRva = rd32(pe->image + leaf);
    const unsigned size = rd32(pe->image + leaf + 4);
    const unsigned off = peOffset(pe, dataRva);
    if (!off || off + size > pe->size) return NULL;
    if (length) *length = size;
    return pe->image + off;
}

/* ------------------------------------------------------------------ menus */

// The Shift-JIS for one UTF-16 code point, or null where the table has none.
static const unsigned char *toSjis(unsigned code) {
    int lo = 0, hi = kRsrcCharCount - 1;
    while (lo <= hi) {
        const int mid = (lo + hi) / 2;
        if (kRsrcChars[mid].code == code) return kRsrcChars[mid].sjis;
        if (kRsrcChars[mid].code < code) lo = mid + 1;
        else hi = mid - 1;
    }
    return NULL;
}

// A resource string is UTF-16 and terminated by a nought word.  It comes back
// as Shift-JIS, which is what the rest of the port reads: the English release
// writes its menu in ASCII and the Japanese one writes it in Japanese, and
// both are the same string to a font that draws Shift-JIS.  The ampersand a
// Windows menu marks its accelerator with is dropped.
static const unsigned char *readText(const unsigned char *p, char *out,
                                     int size) {
    int at = 0;
    for (;;) {
        const unsigned w = rd16(p);
        p += 2;
        if (!w) break;
        if (w == '&') continue;
        if (w < 0x80) {
            if (at < size - 1) out[at++] = (char)w;
            continue;
        }
        const unsigned char *sjis = toSjis(w);
        if (!sjis) {
            if (at < size - 1) out[at++] = '?';
            continue;
        }
        for (int i = 0; sjis[i] && at < size - 1; i++)
            out[at++] = (char)sjis[i];
    }
    out[at] = 0;
    return p;
}

// One popup's items, appending to `menu`.  Recurses into a submenu so its
// items land in the parent, which is what the port's own bar does with them.
static const unsigned char *menuItems(const unsigned char *p,
                                      const unsigned char *end,
                                      RsrcMenu *menu, int depth) {
    for (;;) {
        if (p + 4 > end) return p;
        const unsigned flags = rd16(p);
        p += 2;
        RsrcMenuItem *item = menu->items < RSRC_MENU_MAX
            ? &menu->item[menu->items] : NULL;
        if (flags & 0x10) {                     // MF_POPUP: no id of its own
            RsrcMenuItem here;
            memset(&here, 0, sizeof here);
            here.popup = 1;
            p = readText(p, here.text, RSRC_TEXT);
            if (depth > 0 && item) {
                // Flattened: the submenu's own caption is dropped and its
                // items go straight into the parent.
                p = menuItems(p, end, menu, depth + 1);
            } else {
                if (item) { *item = here; menu->items++; }
                p = menuItems(p, end, menu, depth + 1);
            }
        } else {
            const unsigned command = rd16(p);
            p += 2;
            char text[RSRC_TEXT];
            p = readText(p, text, RSRC_TEXT);
            if (item) {
                memset(item, 0, sizeof *item);
                item->command = command;
                item->separator = (command == 0 && text[0] == 0);
                snprintf(item->text, RSRC_TEXT, "%s", text);
                menu->items++;
            }
        }
        if (flags & 0x80) return p;             // MF_END
    }
}

int rsrcMenuBar(const Pe *pe, unsigned id, RsrcMenuBar *out) {
    unsigned length = 0;
    const unsigned char *p = peResource(pe, RSRC_TYPE_MENU, id, &length);
    memset(out, 0, sizeof *out);
    if (!p || length < 4) return 0;
    const unsigned char *end = p + length;
    p += 4;                                     // version and header size
    while (p + 4 <= end && out->menus < RSRC_MENUS_MAX) {
        const unsigned flags = rd16(p);
        p += 2;
        if (!(flags & 0x10)) return out->menus > 0;   // the bar is all popups
        RsrcMenu *menu = &out->menu[out->menus++];
        memset(menu, 0, sizeof *menu);
        p = readText(p, menu->text, RSRC_TEXT);
        p = menuItems(p, end, menu, 1);
        if (flags & 0x80) break;
    }
    return out->menus > 0;
}

/* ---------------------------------------------------------------- dialogs */

// A control's title can be an ordinal too, not only a string: DIALOG 120's
// icon carries 0xffff and then the icon's own resource id, and reading that as
// text swallowed the terminator and shifted every control after it.
static const unsigned char *readTitle(const unsigned char *p, char *out,
                                      int size) {
    if (rd16(p) == 0xffff) {
        snprintf(out, size, "#%u", rd16(p + 2));
        return p + 4;
    }
    return readText(p, out, size);
}

// A class is either a nought word (none), an ordinal 0xffff followed by a
// word, or a string.
static const unsigned char *readClass(const unsigned char *p, char *out,
                                      int size) {
    if (rd16(p) == 0) { out[0] = 0; return p + 2; }
    if (rd16(p) == 0xffff) {
        // 0x80 is BUTTON, and the six run in that order - getting this
        // one out by a place turned every button into a static and
        // every static into an edit box, which is what the dialogs
        // looked like: white bars where the numbers belong.
        static const char *kOrdinal[6] = {
            "Button", "Edit", "Static", "ListBox", "ScrollBar", "ComboBox"
        };
        const unsigned n = rd16(p + 2);
        snprintf(out, size, "%s", n >= 0x80 && n <= 0x85
                 ? kOrdinal[n - 0x80] : "?");
        return p + 4;
    }
    return readText(p, out, size);
}

static const unsigned char *align4(const unsigned char *base,
                                   const unsigned char *p) {
    const size_t at = (size_t)(p - base);
    return base + ((at + 3u) & ~(size_t)3u);
}

int rsrcDialog(const Pe *pe, unsigned id, RsrcDialog *out) {
    unsigned length = 0;
    const unsigned char *base = peResource(pe, RSRC_TYPE_DIALOG, id, &length);
    memset(out, 0, sizeof *out);
    if (!base || length < 18) return 0;
    const unsigned char *p = base;
    const unsigned char *end = base + length;

    int extended = 0;
    unsigned items;
    if (rd16(p) == 1 && rd16(p + 2) == 0xffff) {
        // DLGTEMPLATEEX: dlgVer, signature, helpID, exStyle, style, count.
        extended = 1;
        out->style = rd32(p + 12);
        items = rd16(p + 16);
        out->x = (short)rd16(p + 18);
        out->y = (short)rd16(p + 20);
        out->w = (short)rd16(p + 22);
        out->h = (short)rd16(p + 24);
        p += 26;
    } else {
        out->style = rd32(p);
        items = rd16(p + 8);
        out->x = (short)rd16(p + 10);
        out->y = (short)rd16(p + 12);
        out->w = (short)rd16(p + 14);
        out->h = (short)rd16(p + 16);
        p += 18;
    }
    char scratch[RSRC_TEXT];
    p = readClass(p, scratch, RSRC_TEXT);       // the menu
    p = readClass(p, scratch, RSRC_TEXT);       // the window class
    p = readText(p, out->caption, RSRC_TEXT);
    if (out->style & 0x40u) {                   // DS_SETFONT
        p += extended ? 6 : 2;                  // size, weight, italic, charset
        p = readText(p, scratch, RSRC_TEXT);    // the face name
    }

    for (unsigned i = 0; i < items && p < end; i++) {
        p = align4(base, p);
        if (p + 18 > end) break;
        RsrcControl c;
        memset(&c, 0, sizeof c);
        if (extended) {
            c.exStyle = rd32(p + 4);
            c.style = rd32(p + 8);
            c.x = (short)rd16(p + 12);
            c.y = (short)rd16(p + 14);
            c.w = (short)rd16(p + 16);
            c.h = (short)rd16(p + 18);
            c.id = rd32(p + 20);
            p += 24;
        } else {
            c.style = rd32(p);
            c.exStyle = rd32(p + 4);
            c.x = (short)rd16(p + 8);
            c.y = (short)rd16(p + 10);
            c.w = (short)rd16(p + 12);
            c.h = (short)rd16(p + 14);
            c.id = rd16(p + 16);
            p += 18;
        }
        p = readClass(p, c.cls, RSRC_TEXT);
        p = readTitle(p, c.text, RSRC_TEXT);
        // Creation data: a nought word means none, and any other value is
        // the size in bytes counting the word itself.  Adding two to it as
        // well shifted every control after the first one that had any.
        const unsigned extra = rd16(p);
        p += extra ? extra : 2u;
        if (out->controls < RSRC_CONTROLS_MAX) out->control[out->controls++] = c;
    }
    return 1;
}

/* ---------------------------------------------------------------- strings */

int rsrcString(const Pe *pe, unsigned id, char *out, int size) {
    if (size > 0) out[0] = 0;
    unsigned length = 0;
    const unsigned char *p =
        peResource(pe, RSRC_TYPE_STRING, id / 16u + 1u, &length);
    if (!p) return 0;
    const unsigned char *end = p + length;
    // Sixteen counted strings, one after another; the wanted one is the
    // (id & 15)th, and a zero count is a string that is not there.
    for (unsigned i = 0; i < 16 && p + 2 <= end; i++) {
        const unsigned words = rd16(p);
        p += 2;
        if (i == (id & 15u)) {
            if (!words) return 0;
            // readText wants a nought-terminated run; this one is counted, so
            // it is copied out by hand through the same conversion.
            int at = 0;
            for (unsigned k = 0; k < words && p + 2 <= end; k++) {
                const unsigned w = rd16(p + k * 2);
                if (w < 0x80) {
                    if (at < size - 1) out[at++] = (char)w;
                    continue;
                }
                const unsigned char *sjis = toSjis(w);
                if (!sjis) {
                    if (at < size - 1) out[at++] = '?';
                    continue;
                }
                for (int b = 0; sjis[b] && at < size - 1; b++)
                    out[at++] = (char)sjis[b];
            }
            out[at] = 0;
            return at > 0;
        }
        p += words * 2;
    }
    return 0;
}
