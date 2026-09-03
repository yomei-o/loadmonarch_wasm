# Prints every DIALOG resource in DS7E_WIN.EXE, which is what src/dlgdefs.c
# was transcribed from.  Run it after touching that file to compare.
#
#   python tools/dump_dialogs.py ds7e.zip
# -*- coding: utf-8 -*-
"""Every DIALOG resource in the executable, control by control.

They are DLGTEMPLATEEX (dlgVer 1, signature 0xffff), so the item id is a DWORD
and the header carries a help id and a font weight the plain template has not.
"""
import struct
import sys
import zipfile

ARCHIVE = sys.argv[1] if len(sys.argv) > 1 else 'ds7e.zip'

z = zipfile.ZipFile(ARCHIVE)
d = z.read([n for n in z.namelist() if n.upper().endswith('.EXE')][0])
pe = struct.unpack_from('<I', d, 0x3c)[0]
nsec = struct.unpack_from('<H', d, pe + 6)[0]
optsz = struct.unpack_from('<H', d, pe + 20)[0]
secs = []
off = pe + 24 + optsz
for i in range(nsec):
    e = d[off + i * 40:off + (i + 1) * 40]
    nm = e[:8].rstrip(b'\0').decode()
    vsz, va, rsz, ra = struct.unpack_from('<IIII', e, 8)
    secs.append((nm, va, vsz, ra))
rs = [s for s in secs if s[0] == '.rsrc'][0]
rva0, fa0 = rs[1], rs[3]


def at(r):
    return fa0 + (r - rva0)


def kids(diroff):
    o = fa0 + diroff
    nn, ni = struct.unpack_from('<HH', d, o + 12)
    return [struct.unpack_from('<II', d, o + 16 + i * 8) for i in range(nn + ni)]


CLASSES = {0x80: 'BUTTON', 0x81: 'EDIT', 0x82: 'STATIC', 0x83: 'LISTBOX',
           0x84: 'SCROLLBAR', 0x85: 'COMBOBOX'}
BS = {0: 'PUSH', 1: 'DEFPUSH', 2: 'CHECK', 3: 'AUTOCHECK', 4: 'RADIO',
      5: '3STATE', 6: 'AUTO3STATE', 7: 'GROUP', 8: 'USERBUTTON',
      9: 'AUTORADIO', 0x0b: 'OWNERDRAW'}
SS = {0: 'LEFT', 1: 'CENTER', 2: 'RIGHT', 3: 'ICON', 4: 'BLACKRECT',
      5: 'GRAYRECT', 6: 'WHITERECT', 7: 'BLACKFRAME', 8: 'GRAYFRAME',
      9: 'WHITEFRAME', 0x0b: 'BITMAP', 0x0e: 'ETCHEDHORZ'}


def read_name(b, p):
    w = struct.unpack_from('<H', b, p)[0]
    if w == 0xffff:
        return struct.unpack_from('<H', b, p + 2)[0], p + 4
    out = []
    while True:
        w = struct.unpack_from('<H', b, p)[0]
        p += 2
        if w == 0:
            break
        out.append(w)
    return bytes().join(struct.pack('<H', c) for c in out).decode(
        'utf-16-le', 'replace'), p


def dump(rid, b, out):
    ver, sig = struct.unpack_from('<HH', b, 0)
    ext = (ver, sig) == (1, 0xffff)
    if ext:
        helpid, ex, style, cdit, x, y, cx, cy = struct.unpack_from(
            '<IIIHhhhh', b, 4)
        p = 26
    else:
        style, ex, cdit, x, y, cx, cy = struct.unpack_from('<IIHhhhh', b, 0)
        p = 18
    menu, p = read_name(b, p)
    klass, p = read_name(b, p)
    title, p = read_name(b, p)
    font = ''
    if style & 0x40:                       # DS_SETFONT
        if ext:
            pt, weight, italic, charset = struct.unpack_from('<HHBB', b, p)
            p += 6
        else:
            pt = struct.unpack_from('<H', b, p)[0]
            p += 2
        name, p = read_name(b, p)
        font = '%s %dpt' % (name, pt)
    out.append('DIALOG %d  "%s"  %dx%d  style %08x  %s  (%d controls)%s' %
               (rid, title, cx, cy, style, font, cdit,
                '' if ext else '   [plain template]'))
    for i in range(cdit):
        p = (p + 3) & ~3
        if ext:
            chelp, cex, cstyle, cx0, cy0, cw, ch, cid = struct.unpack_from(
                '<IIIhhhhI', b, p)
            p += 24
        else:
            cstyle, cex, cx0, cy0, cw, ch, cid = struct.unpack_from(
                '<IIhhhhH', b, p)
            p += 18
        cls, p = read_name(b, p)
        text, p = read_name(b, p)
        extra = struct.unpack_from('<H', b, p)[0]
        p += 2 + extra
        if isinstance(cls, int):
            cls = CLASSES.get(cls, hex(cls))
        kind = cls
        if cls == 'BUTTON':
            kind = 'BTN.' + BS.get(cstyle & 0x0f, '?')
        elif cls == 'STATIC':
            kind = 'TXT.' + SS.get(cstyle & 0x1f, '?')
        vis = '' if (cstyle & 0x10000000) else ' HIDDEN'
        dis = ' DISABLED' if (cstyle & 0x08000000) else ''
        out.append('    %-14s %5d  %4d,%-4d %3dx%-3d %08x%s%s  "%s"' %
                   (kind, cid, cx0, cy0, cw, ch, cstyle, vis, dis, text))
    out.append('')


lines = []
for tname, toff in kids(0):
    if (tname & 0x7fffffff) != 5 or not (toff & 0x80000000):
        continue
    for nname, noff in kids(toff & 0x7fffffff):
        if not (noff & 0x80000000):
            continue
        for lname, loff in kids(noff & 0x7fffffff):
            o = fa0 + (loff & 0x7fffffff)
            da, sz = struct.unpack_from('<II', d, o)
            dump(nname & 0x7fffffff, d[at(da):at(da) + sz], lines)
sys.stdout.write('\n'.join(lines) + '\n')
