# Prints every MENU resource in DS7E_WIN.EXE, which is what src/ui.c's kBar
# is a transcription of.  Written because that transcription was made by hand
# and had four commands missing from it.
#
#   python tools/dump_menus.py [ds7e.zip]
"""Every MENU resource in the executable, item by item."""
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


# MENUITEM flags
GRAYED, DISABLED, CHECKED, POPUP, BREAKS, ENDMENU = 1, 2, 8, 0x10, 0x60, 0x80


def text_at(p):
    out = ''
    while struct.unpack_from('<H', d, p)[0]:
        out += chr(struct.unpack_from('<H', d, p)[0] & 0xff)
        p += 2
    return out, p + 2


def dump(rid, base, size):
    print(f'MENU {rid}  ({size} bytes)')
    # MENUHEADER: version and header size, both zero for the plain kind
    ver, hsz = struct.unpack_from('<HH', d, base)
    p = base + 4 + hsz
    depth = 1
    while p < base + size and depth > 0:
        flags = struct.unpack_from('<H', d, p)[0]
        p += 2
        cid = None
        if not flags & POPUP:
            cid = struct.unpack_from('<H', d, p)[0]
            p += 2
        label, p = text_at(p)
        marks = ''
        if flags & GRAYED: marks += ' GRAYED'
        if flags & DISABLED: marks += ' DISABLED'
        if flags & CHECKED: marks += ' CHECKED'
        pad = '  ' * depth
        if flags & POPUP:
            print(f'{pad}[{label}]{marks}')
            depth += 1
        else:
            print(f'{pad}{"" if cid else "":>0}{cid:6d}  {label or "(separator)"}{marks}')
        if flags & ENDMENU:
            depth -= 1


for tid, sub in kids(0):
    if (tid & 0x7fffffff) != 4:                 # RT_MENU
        continue
    for rid, sub2 in kids(sub & 0x7fffffff):
        for lid, leaf in kids(sub2 & 0x7fffffff):
            rva, size = struct.unpack_from('<II', d, fa0 + leaf)
            dump(rid & 0x7fffffff, at(rva), size)
