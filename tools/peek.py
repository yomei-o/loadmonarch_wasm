# -*- coding: utf-8 -*-
"""Read any virtual address out of DS7E_WIN.EXE - bytes, dwords, or code.

Ghidra did not turn every routine in this executable into a function, and the
ones it missed are exactly the ones worth reading (the window painters, the
vtables).  RESUME.md described doing this by hand with a throwaway python
one-liner and objdump; this is the same thing, kept.

    python tools/peek.py ds7e.zip dw  0x4303d0 24      # 24 dwords
    python tools/peek.py ds7e.zip b   0x432120 64      # 64 bytes, hex + ascii
    python tools/peek.py ds7e.zip s   0x432120         # the C string there
    python tools/peek.py ds7e.zip dis 0x40fc60 0x120   # x86-32, needs capstone
    python tools/peek.py ds7e.zip fn  0x40fc60         # ... to the first ret

A dword that lands inside .text is annotated with the offset from the nearest
lower function start Ghidra did name, so a vtable reads as names rather than
numbers.
"""
import os
import struct
import sys
import zipfile

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))


def load(archive):
    """The .EXE out of the zip, plus its section table."""
    z = zipfile.ZipFile(archive)
    name = [n for n in z.namelist() if n.upper().endswith('.EXE')][0]
    d = z.read(name)
    pe = struct.unpack_from('<I', d, 0x3c)[0]
    nsec = struct.unpack_from('<H', d, pe + 6)[0]
    optsz = struct.unpack_from('<H', d, pe + 20)[0]
    base = struct.unpack_from('<I', d, pe + 24 + 28)[0]
    secs = []
    off = pe + 24 + optsz
    for i in range(nsec):
        e = d[off + i * 40:off + (i + 1) * 40]
        nm = e[:8].rstrip(b'\0').decode('latin-1')
        vsz, va, rsz, ra = struct.unpack_from('<IIII', e, 8)
        secs.append((nm, base + va, vsz, ra, rsz))
    return d, secs, base


def where(secs, va):
    for nm, sva, vsz, ra, rsz in secs:
        if sva <= va < sva + max(vsz, rsz):
            return nm, ra + (va - sva)
    return None, None


def read(d, secs, va, n):
    nm, off = where(secs, va)
    if off is None:
        raise SystemExit('%08x is in no section' % va)
    return nm, d[off:off + n]


def names():
    """Every function start Ghidra did name, from decomp/index.csv."""
    out = []
    path = os.path.join(ROOT, 'decomp', 'index.csv')
    if not os.path.exists(path):
        return out
    for line in open(path, encoding='utf-8', errors='replace'):
        parts = line.strip().split(',')
        if len(parts) < 2:
            continue
        try:
            out.append((int(parts[0], 16), parts[1]))
        except ValueError:
            continue
    out.sort()
    return out


def label(table, va):
    """The named function this address is in, as `name+offset`."""
    lo, hi, best = 0, len(table) - 1, None
    while lo <= hi:
        mid = (lo + hi) // 2
        if table[mid][0] <= va:
            best = table[mid]
            lo = mid + 1
        else:
            hi = mid - 1
    if not best:
        return ''
    return '%s+0x%x' % (best[1], va - best[0]) if va != best[0] else best[1]


def main():
    if len(sys.argv) < 4:
        print(__doc__)
        return 2
    archive = sys.argv[1]
    what = sys.argv[2]
    va = int(sys.argv[3], 0)
    n = int(sys.argv[4], 0) if len(sys.argv) > 4 else 0
    d, secs, base = load(archive)
    table = names()

    if what == 'dw':
        nm, buf = read(d, secs, va, max(n, 1) * 4)
        for i in range(max(n, 1)):
            v = struct.unpack_from('<I', buf, i * 4)[0]
            sec, _ = where(secs, v)
            note = ''
            if sec == '.text':
                note = '  ' + label(table, v)
            elif sec:
                note = '  (%s)' % sec
            print('%08x  %08x%s' % (va + i * 4, v, note))
    elif what == 'b':
        nm, buf = read(d, secs, va, max(n, 16))
        for i in range(0, len(buf), 16):
            row = buf[i:i + 16]
            hexed = ' '.join('%02x' % c for c in row)
            text = ''.join(chr(c) if 32 <= c < 127 else '.' for c in row)
            print('%08x  %-47s  %s' % (va + i, hexed, text))
    elif what == 's':
        nm, buf = read(d, secs, va, 512)
        end = buf.find(b'\0')
        print(repr(buf[:end if end >= 0 else 512]))
    elif what in ('dis', 'fn'):
        try:
            import capstone
        except ImportError:
            raise SystemExit('dis needs capstone: pip install capstone')
        size = n if what == 'dis' and n else 0x400
        nm, buf = read(d, secs, va, size)
        md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
        md.detail = False
        for ins in md.disasm(buf, va):
            note = ''
            if ins.mnemonic in ('call', 'jmp') and ins.op_str.startswith('0x'):
                note = '   -> ' + label(table, int(ins.op_str, 16))
            print('%08x  %-24s %s %s%s' % (ins.address,
                                           ins.bytes.hex(),
                                           ins.mnemonic, ins.op_str, note))
            if what == 'fn' and ins.mnemonic == 'ret':
                break
    else:
        print(__doc__)
        return 2
    return 0


if __name__ == '__main__':
    sys.exit(main())
