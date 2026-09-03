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
static const unsigned char *readText(const unsigned char *p,
                                     const unsigned char *end, char *out,
                                     int size) {
    int at = 0;
    for (;;) {
        if (p + 2 > end) break;
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
            p = readText(p, end, here.text, RSRC_TEXT);
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
            p = readText(p, end, text, RSRC_TEXT);
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
        p = readText(p, end, menu->text, RSRC_TEXT);
        p = menuItems(p, end, menu, 1);
        if (flags & 0x80) break;
    }
    return out->menus > 0;
}

/* ---------------------------------------------------------------- dialogs */

// A control's title can be an ordinal too, not only a string: DIALOG 120's
// icon carries 0xffff and then the icon's own resource id, and reading that as
// text swallowed the terminator and shifted every control after it.
static const unsigned char *readTitle(const unsigned char *p,
                                      const unsigned char *end, char *out,
                                      int size) {
    if (out && size > 0) out[0] = 0;
    if (p + 2 > end) return end;
    if (rd16(p) == 0xffff) {
        if (p + 4 > end) return end;
        snprintf(out, size, "#%u", rd16(p + 2));
        return p + 4;
    }
    return readText(p, end, out, size);
}

// A class is either a nought word (none), an ordinal 0xffff followed by a
// word, or a string.
static const unsigned char *readClass(const unsigned char *p,
                                      const unsigned char *end, char *out,
                                      int size) {
    if (out && size > 0) out[0] = 0;
    if (p + 2 > end) return end;
    if (rd16(p) == 0) { out[0] = 0; return p + 2; }
    if (rd16(p) == 0xffff) {
        if (p + 4 > end) return end;
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
    return readText(p, end, out, size);
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
    p = readClass(p, end, scratch, RSRC_TEXT);  // the menu
    p = readClass(p, end, scratch, RSRC_TEXT);  // the window class
    p = readText(p, end, out->caption, RSRC_TEXT);
    if (out->style & 0x40u) {                   // DS_SETFONT
        p += extended ? 6 : 2;                  // size, weight, italic, charset
        p = readText(p, end, scratch, RSRC_TEXT);   // the face name
    }

    for (unsigned i = 0; i < items && p < end; i++) {
        p = align4(base, p);
        if (p + (extended ? 24 : 18) > end) break;
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
        p = readClass(p, end, c.cls, RSRC_TEXT);
        p = readTitle(p, end, c.text, RSRC_TEXT);
        // Creation data: a nought word means none, and any other value is
        // the size in bytes counting the word itself.  Adding two to it as
        // well shifted every control after the first one that had any.
        if (p + 2 > end) break;
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

/* ------------------------------------------------------------------- help */

// Where .data is, which both searches walk.  Named by the section table
// rather than by address, so a different build still finds it.
static int dataSection(const Pe *pe, unsigned *vaOut, unsigned *foOut,
                       unsigned *sizeOut) {
    for (unsigned i = 0; i < pe->sections; i++) {
        const unsigned char *e = pe->image + pe->sectionAt + i * 40u;
        char name[9];
        memcpy(name, e, 8);
        name[8] = 0;
        if (strcmp(name, ".data") != 0) continue;
        const unsigned vsz = rd32(e + 8), rsz = rd32(e + 16);
        *vaOut = pe->base + rd32(e + 12);
        *foOut = rd32(e + 20);
        *sizeOut = vsz < rsz ? vsz : rsz;
        return 1;
    }
    return 0;
}

// The length of the string at this file offset, or -1 if it is not one: every
// byte printable or a newline, and a terminator inside a thousand.
static int stringAt(const Pe *pe, unsigned off, int least) {
    unsigned i = off;
    while (i < pe->size && i - off < 1000u) {
        const unsigned char c = pe->image[i];
        if (!c) break;
        if (c < 0x20 && c != '\t' && c != '\n' && c != '\r') return -1;
        i++;
    }
    if (i >= pe->size || pe->image[i]) return -1;
    const int length = (int)(i - off);
    return length >= least ? length : -1;
}


/* ------------------------------------------------------- the Graph Window */

// Does this string carry `what` in it?
static int carries(const char *s, const char *what) {
    const int n = (int)strlen(what);
    for (const char *p = s; *p; p++)
        if (strncmp(p, what, (size_t)n) == 0) return 1;
    return 0;
}

// A .data string this format table would accept: printable, NUL terminated,
// and with a `%s` in it for the country's name.
static const char *formatAt(const Pe *pe, unsigned va, unsigned dva,
                            unsigned dfo, unsigned dsize) {
    if (va < dva || va >= dva + dsize) return NULL;
    const unsigned off = dfo + (va - dva);
    const int length = stringAt(pe, off, 4);
    if (length < 4 || length > 60) return NULL;
    const char *s = (const char *)pe->image + off;
    return carries(s, "%s") ? s : NULL;
}

int rsrcGraphLines(const Pe *pe, const char **out, int max) {
    unsigned dva = 0, dfo = 0, dsize = 0;
    if (max < RSRC_GRAPH_LINES) return 0;
    if (!dataSection(pe, &dva, &dfo, &dsize)) return 0;

    // The area line: the only format with both a name and a fraction in it.
    // The Japanese release writes it as a quoted name, so the `%s` is not at
    // the front of the string in either release.
    const char *area = NULL;
    unsigned areaVa = 0;
    for (unsigned i = 0; i < dsize; i++) {
        const char *s = formatAt(pe, dva + i, dva, dfo, dsize);
        if (!s || !carries(s, "%3.2f")) continue;
        area = s;
        areaVa = dva + i;
        break;
    }
    if (!area) return 0;

    // Where the routine pushes it, and then every other format it pushes.
    // The window is drawn by one routine, so a few hundred bytes either side
    // of that push is the whole of it.
    unsigned site = 0;
    for (unsigned i = 0; i + 5 <= pe->size; i++)
        if (pe->image[i] == 0x68 && rd32(pe->image + i + 1) == areaVa) {
            site = i;
            break;
        }
    if (!site) return 0;

    const unsigned from = site > 0x400u ? site - 0x400u : 0;
    const unsigned to = site + 0x400u < pe->size ? site + 0x400u : pe->size - 5;
    const char *number[4] = {NULL, NULL, NULL, NULL};
    const char *defeated = NULL;
    int numbers = 0;
    for (unsigned i = from; i <= to; i++) {
        if (pe->image[i] != 0x68) continue;
        const char *s = formatAt(pe, rd32(pe->image + i + 1), dva, dfo, dsize);
        if (!s || s == area) continue;
        if (carries(s, "%d")) {
            int seen = 0;
            for (int k = 0; k < numbers; k++) if (number[k] == s) seen = 1;
            if (!seen && numbers < 4) number[numbers++] = s;
        } else if (!defeated) {
            defeated = s;
        }
    }
    if (numbers < 4 || !defeated) return 0;

    out[RSRC_GRAPH_AREA] = area;
    out[RSRC_GRAPH_FUNDS] = number[0];
    out[RSRC_GRAPH_LEADER] = number[1];
    out[RSRC_GRAPH_UNITS] = number[2];
    out[RSRC_GRAPH_ALL] = number[3];
    out[RSRC_GRAPH_DEFEATED] = defeated;
    return RSRC_GRAPH_LINES;
}

int rsrcHelpPages(const Pe *pe, const char **out, int max) {
    unsigned va = 0, fo = 0, size = 0;
    if (!dataSection(pe, &va, &fo, &size)) return 0;

    unsigned bestAt = 0;
    int best = 0, run = 0;
    unsigned runAt = 0;
    for (unsigned f = fo; f + 4 <= fo + size; f += 4) {
        const unsigned v = rd32(pe->image + f);
        int ok = 0;
        if (v >= va && v < va + size)
            ok = stringAt(pe, fo + (v - va), 20) > 0;
        if (ok) {
            if (!run) runAt = f;
            run++;
            if (run > best) { best = run; bestAt = runAt; }
        } else {
            run = 0;
        }
    }
    if (best < RSRC_HELP_PAGES) return 0;
    int n = 0;
    for (int i = 0; i < best && n < max; i++) {
        const unsigned v = rd32(pe->image + bestAt + (unsigned)i * 4u);
        out[n++] = (const char *)pe->image + fo + (v - va);
    }
    return n;
}

int rsrcHelpTopics(const Pe *pe, const char **out, int max) {
    unsigned va = 0, fo = 0, size = 0;
    if (!dataSection(pe, &va, &fo, &size)) return 0;

    // 0x462 is the combo's id, and every topic is added with `push <string>`
    // somewhere just before `push 0x462`.  Two forms of it appear - with and
    // without the `mov ecx, esi` the compiler put between them - so the search
    // is for the push of the id and then a look back for the push of a string.
    int n = 0;
    for (unsigned i = 0; i + 5 <= pe->size && n < max; i++) {
        if (pe->image[i] != 0x68) continue;                 // push imm32
        if (rd32(pe->image + i + 1) != 0x462) continue;
        // Back up over the two bytes of `mov ecx, esi` if they are there.
        unsigned at = i;
        if (at >= 2 && pe->image[at - 2] == 0x8b && pe->image[at - 1] == 0xce)
            at -= 2;
        if (at < 5 || pe->image[at - 5] != 0x68) continue;
        const unsigned v = rd32(pe->image + at - 4);
        if (v < va || v >= va + size) continue;
        if (stringAt(pe, fo + (v - va), 3) <= 0) continue;
        out[n++] = (const char *)pe->image + fo + (v - va);
    }
    return n;
}
