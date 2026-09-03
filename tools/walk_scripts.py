# -*- coding: utf-8 -*-
"""Recover the walk scripts dialog 105's parade is set up with.

    python tools/walk_scripts.py ds7e.zip

FUN_00411340 builds its scripts on the stack out of constants - a couple of
hundred `mov dword ptr [esp+N], imm` - and then copies one of them into the
actor at +0x26a as sixteen-bit words, up to a 0xff.  Which one is its second
argument, and 00410680 and its four siblings pass 0 to 12.

This walks the function with capstone, keeps a register file for the handful
of registers it loads constants into, records every store to the frame, and
prints each script as the run of words that ends at 0xff.  The scripts
themselves are what src/endstage.c would need to march the soldiers.
"""
import struct
import sys
import zipfile

import capstone


def load(archive):
    z = zipfile.ZipFile(archive)
    return z.read([n for n in z.namelist() if n.upper().endswith('.EXE')][0])


def text_of(d):
    pe = struct.unpack_from('<I', d, 0x3c)[0]
    nsec = struct.unpack_from('<H', d, pe + 6)[0]
    optsz = struct.unpack_from('<H', d, pe + 20)[0]
    base = struct.unpack_from('<I', d, pe + 24 + 28)[0]
    off = pe + 24 + optsz
    for i in range(nsec):
        e = d[off + i * 40:off + (i + 1) * 40]
        name = e[:8].rstrip(b'\0').decode()
        vsz, va, rsz, ra = struct.unpack_from('<IIII', e, 8)
        if name == '.text':
            return base + va, ra, rsz
    return None


def main():
    archive = sys.argv[1] if len(sys.argv) > 1 else 'ds7e.zip'
    start = int(sys.argv[2], 0) if len(sys.argv) > 2 else 0x411340
    d = load(archive)
    tva, tfo, tsz = text_of(d)
    at = tfo + (start - tva)
    code = d[at:at + 0x800]

    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    md.detail = True
    reg = {}
    frame = {}          # esp-relative offset -> value
    espAdjust = 0       # what has been pushed since `sub esp, N`
    lea = {}            # register -> the frame offset it points at

    for ins in md.disasm(code, start):
        m = ins.mnemonic
        ops = ins.operands
        if m == 'sub' and ins.op_str.startswith('esp,'):
            continue
        if m == 'push':
            espAdjust += 4
            continue
        if m == 'ret':
            break
        if m == 'call':
            # Whatever it was, the constants around it are what matter; the
            # caller-saved registers are not to be trusted after it.
            for r in ('eax', 'ecx', 'edx'):
                reg.pop(r, None)
                lea.pop(r, None)
            continue
        if m == 'xor' and len(ops) == 2 and \
           ops[0].type == capstone.x86.X86_OP_REG and \
           ops[1].type == capstone.x86.X86_OP_REG and \
           ops[0].reg == ops[1].reg:
            reg[ins.reg_name(ops[0].reg)] = 0
            lea.pop(ins.reg_name(ops[0].reg), None)
            continue
        if m in ('inc', 'dec') and len(ops) == 1 and \
           ops[0].type == capstone.x86.X86_OP_REG:
            name = ins.reg_name(ops[0].reg)
            if name in reg:
                reg[name] += 1 if m == 'inc' else -1
            continue
        if m == 'add' and len(ops) == 2 and \
           ops[0].type == capstone.x86.X86_OP_REG and \
           ops[1].type == capstone.x86.X86_OP_IMM:
            name = ins.reg_name(ops[0].reg)
            if name in reg:
                reg[name] += ops[1].imm
            continue
        if m == 'mov' and len(ops) == 2:
            dst, src = ops
            if dst.type == capstone.x86.X86_OP_REG and \
               src.type == capstone.x86.X86_OP_IMM:
                reg[ins.reg_name(dst.reg)] = src.imm
                lea.pop(ins.reg_name(dst.reg), None)
                continue
            if dst.type == capstone.x86.X86_OP_MEM and \
               dst.mem.base == capstone.x86.X86_REG_ESP:
                off = dst.mem.disp + espAdjust
                if src.type == capstone.x86.X86_OP_IMM:
                    frame[off] = src.imm
                elif src.type == capstone.x86.X86_OP_REG:
                    name = ins.reg_name(src.reg)
                    if name in lea:
                        frame[off] = ('&', lea[name])
                    elif name in reg:
                        frame[off] = reg[name]
                continue
        if m == 'lea' and len(ops) == 2 and \
           ops[1].mem.base == capstone.x86.X86_REG_ESP:
            lea[ins.reg_name(ops[0].reg)] = ops[1].mem.disp + espAdjust
            continue

    # The pointer table: the frame slots holding addresses of other slots.
    table = sorted((off, v[1]) for off, v in frame.items()
                   if isinstance(v, tuple))
    print('%d constants on the frame, %d of them pointers' %
          (len(frame), len(table)))
    print()
    for i, (slot, points) in enumerate(table):
        words = []
        at2 = points
        while not isinstance(frame.get(at2), tuple):
            if at2 not in frame:
                words.append('??')
                break
            words.append('%02x' % (frame[at2] & 0xffff))
            if frame[at2] == 0xff:
                break
            at2 += 4
        print('script %-2d (frame +0x%03x -> +0x%03x): %s'
              % (i, slot, points,
                 ' '.join(words)))
    return 0


if __name__ == '__main__':
    sys.exit(main())
