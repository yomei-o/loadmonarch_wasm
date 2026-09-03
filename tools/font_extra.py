# -*- coding: utf-8 -*-
"""Rebuild tools/font_extra.txt: every wide glyph the port needs beyond the
kana and symbols make_font.py takes wholesale.

    python tools/font_extra.py ds7e.zip ds7j.zip > tools/font_extra.txt

Two sources, because the font is generated and the list has to be too:

* whatever src/font16.c already carries outside JIS X 0208 rows 1 to 8 - the
  kanji of the game's own country and order names, which were collected once
  and would otherwise be lost the next time the font is regenerated
* what the two releases' MENU and DIALOG resources want, which is what
  tools/missing_glyphs.py works out
* the stage names in MAP/NAME.TXT, which the Load Quest Map list shows
* the Help dialog's eighteen pages, which are in .data rather than in the
  resources - see rsrc.h

So regenerating the font is:

    python tools/font_extra.py ds7e.zip ds7j.zip > tools/font_extra.txt
    python tools/make_font.py <dir with the BDFs> tools/font_extra.txt \\
        > src/font16.c
"""
import io
import os
import re
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, 'tools'))

import missing_glyphs                                       # noqa: E402


def jis_to_sjis(jis):
    """The same conversion make_font.py does, so the two agree."""
    row, cell = jis >> 8, jis & 0xFF
    if row < 0x21 or row > 0x7E or cell < 0x21 or cell > 0x7E:
        return None
    if row % 2:
        lead = (row + 1) // 2 + 0x70
        trail = cell + 0x1F + (1 if cell >= 0x60 else 0)
    else:
        lead = row // 2 + 0x70
        trail = cell + 0x7E
    if lead >= 0xA0:
        lead += 0x40
    return (lead << 8) | trail


def main():
    # Shift-JIS back to a JIS row, by building the forward map.
    row_of = {}
    for row in range(0x21, 0x7F):
        for cell in range(0x21, 0x7F):
            sjis = jis_to_sjis((row << 8) | cell)
            if sjis:
                row_of[sjis] = row

    have = missing_glyphs.font_codes()
    kanji = {c for c in have if row_of.get(c, 0) > 0x28}

    want = dict.fromkeys(sorted(kanji), '')
    archives = sys.argv[1:] or ['ds7e.zip', 'ds7j.zip']

    # MAP/NAME.TXT: the quest's name and the fifteen stage titles, which the
    # Load Quest Map list shows and which are Shift-JIS already.
    import zipfile
    for archive in archives:
        z = zipfile.ZipFile(archive)
        for name in z.namelist():
            if not name.upper().endswith('NAME.TXT'):
                continue
            raw = z.read(name)
            i = 0
            while i < len(raw) - 1:
                lead = raw[i]
                if (0x81 <= lead <= 0x9f) or (0xe0 <= lead <= 0xfc):
                    code = (lead << 8) | raw[i + 1]
                    if row_of.get(code, 0) > 0x28:
                        try:
                            want[code] = bytes(raw[i:i + 2]).decode('shift_jis')
                        except UnicodeDecodeError:
                            want[code] = ''
                    i += 2
                else:
                    i += 1

    # The Help dialog's pages, found the way src/rsrc.c finds them: the
    # longest run of .data pointers to strings of twenty characters or more.
    import struct
    import zipfile
    for archive in archives:
        z = zipfile.ZipFile(archive)
        d = z.read([n for n in z.namelist() if n.upper().endswith('.EXE')][0])
        bva, bfo, size = 0x432000, 0x30400, 14848

        def offset(va):
            return bfo + (va - bva) if bva <= va < bva + size else None

        def length(at):
            end = d.find(b'\0', at)
            return end - at if end >= 0 else -1

        best, run, start = (0, 0), 0, 0
        for f in range(bfo, bfo + size - 4, 4):
            v = struct.unpack_from('<I', d, f)[0]
            at = offset(v)
            ok = False
            if at:
                n = length(at)
                ok = (20 <= n < 1000 and
                      all(c >= 0x20 or c in (9, 10, 13) for c in d[at:at + n]))
            if ok:
                if run == 0:
                    start = f
                run += 1
                if run > best[0]:
                    best = (run, start)
            else:
                run = 0
        n, f = best
        for k in range(n):
            v = struct.unpack_from('<I', d, f + k * 4)[0]
            at = offset(v)
            page = d[at:d.find(b'\0', at)]
            i = 0
            while i < len(page) - 1:
                lead = page[i]
                if (0x81 <= lead <= 0x9f) or (0xe0 <= lead <= 0xfc):
                    code = (lead << 8) | page[i + 1]
                    if row_of.get(code, 0) > 0x28:
                        try:
                            want[code] = bytes(page[i:i + 2]).decode('shift_jis')
                        except UnicodeDecodeError:
                            want[code] = ''
                    i += 2
                else:
                    i += 1

    for archive in archives:
        for text in missing_glyphs.resource_strings(archive):
            for ch in text:
                if ord(ch) < 0x80:
                    continue
                try:
                    sjis = ch.encode('shift_jis')
                except UnicodeEncodeError:
                    continue
                if len(sjis) != 2:
                    continue
                code = (sjis[0] << 8) | sjis[1]
                if row_of.get(code, 0) > 0x28:
                    want[code] = ch

    print("# The wide glyphs src/font16.c has to carry beyond JIS X 0208's")
    print('# first eight rows: the kanji of the game\'s own names, and what')
    print("# the two releases' menus and dialogs are written in.")
    print('# Generated by tools/font_extra.py - see make_font.py.')
    out = sys.stdout
    for code in sorted(want):
        ch = want[code]
        try:
            out.write('%04x%s\n' % (code, '   # ' + ch if ch else ''))
        except UnicodeEncodeError:
            out.write('%04x\n' % code)
    print('# %d in all' % len(want), file=sys.stderr)
    return 0


if __name__ == '__main__':
    sys.exit(main())
