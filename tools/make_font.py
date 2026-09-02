# Builds src/font16.c from the Shinonome bitmap fonts.
#
# The original draws its text with GDI, so nothing in the port could draw a
# string - only the digits the interface sheet carries as tiles.  Shinonome is
# a 16-dot bitmap family in the public domain, which is the same shape of thing
# a 1997 Windows game would have had on screen, so the port carries a subset of
# it instead of asking the browser for a font it cannot measure into a canvas.
#
#   COMMENT The original is designed by
#     Yasuyuki Furukawa <Furukawa.Yasuyuki@fujixerox.co.jp>, 2000.
#     (Public Domain)
#   Modified and Maintained by /efont/ -- http://openlab.ring.gr.jp/efont/
#
# The three BDFs it reads, none of which is kept in this repository:
#
#   shnmk16.bdf   16x16, JIS X 0208 - the kanji and full-width kana
#   shnm8x16r.bdf  8x16, latin1     - ASCII
#   font_src_diff.bit (16/hankaku)  8x16, JIS X 0201 - half-width katakana
#
#   base=https://raw.githubusercontent.com/mgo-tec/ShinonomeFONTread/master
#   curl -O $base/examples/OLED_Shinonome/data/shnmk16.bdf
#   curl -O $base/examples/OLED_Shinonome/data/shnm8x16r.bdf
#   curl -O https://raw.githubusercontent.com/code4fukui/shinonome-font/main/16/hankaku/font_src_diff.bit
#
# What goes in: every half-width code, and for the wide font JIS X 0208 rows 1
# to 8 - the symbols, digits, latin, kana, greek and cyrillic - plus whatever
# kanji the game's own strings use.  Those strings are a closed set: the five
# country names and sixteen order names of every scenery set in both releases,
# which tools/../tests/sim_harness.exe <zip> <map> 0 names prints.  209 of them
# at the time of writing, so the whole thing is about thirty kilobytes rather
# than the three hundred a full JIS X 0208 would be.
#
#   python tools/make_font.py <dir with the three files> [extra-sjis-hex-file]
import sys
import os


def read_bdf(path):
    """{encoding: [row bitmaps]} plus the box width, from one BDF."""
    glyphs = {}
    width = 8
    enc = None
    rows = None
    with open(path, "r", encoding="latin-1") as f:
        for line in f:
            line = line.rstrip("\n").rstrip("\r")
            if line.startswith("FONTBOUNDINGBOX"):
                width = int(line.split()[1])
            elif line.startswith("ENCODING"):
                enc = int(line.split()[1])
            elif line.startswith("BITMAP"):
                rows = []
            elif line.startswith("ENDCHAR"):
                if enc is not None and rows is not None:
                    glyphs[enc] = rows
                enc, rows = None, None
            elif rows is not None and line:
                rows.append(line.strip())
    return glyphs, width


def jis_to_sjis(jis):
    """A JIS X 0208 code (0xRRCC, row and cell each 0x21..0x7e) as Shift-JIS."""
    row, cell = jis >> 8, jis & 0xFF
    if row < 0x21 or row > 0x7E or cell < 0x21 or cell > 0x7E:
        return None
    if row % 2:                                  # odd row
        lead = (row + 1) // 2 + 0x70
        trail = cell + 0x1F + (1 if cell >= 0x60 else 0)
    else:
        lead = row // 2 + 0x70
        trail = cell + 0x7E
    if lead >= 0xA0:
        lead += 0x40                             # 0xe0..0xef, not 0xa0..
    return (lead << 8) | trail


def rows_to_bytes(rows, width, height=16):
    """A glyph's rows to the port's layout: for 16 wide, two bytes a row.

    BDF writes each row as hex; the /efont/ sources that end in .bit draw them
    with '@' for ink and '.' for paper instead, and both turn up among the
    three files this reads."""
    per = 2 if width > 8 else 1
    out = bytearray(height * per)
    for y, hexrow in enumerate(rows[:height]):
        if "@" in hexrow or "." in hexrow:
            bits = "".join("1" if c == "@" else "0" for c in hexrow)
            out_bits = bits.ljust(per * 8, "0")[:per * 8]
            for b in range(per):
                out[y * per + b] = int(out_bits[b * 8:(b + 1) * 8], 2)
            continue
        value = int(hexrow, 16)
        # BDF pads each row up to a byte boundary, so a row of an 8-wide glyph
        # is two hex digits and of a 16-wide one four.
        bits = len(hexrow) * 4
        value <<= max(0, (per * 8) - bits)
        for b in range(per):
            out[y * per + b] = (value >> ((per - 1 - b) * 8)) & 0xFF
    return bytes(out)


def main():
    here = sys.argv[1] if len(sys.argv) > 1 else "."
    extra_path = sys.argv[2] if len(sys.argv) > 2 else None

    kanji, kwidth = read_bdf(os.path.join(here, "shnmk16.bdf"))
    roman, rwidth = read_bdf(os.path.join(here, "shnm8x16r.bdf"))
    hankaku, hwidth = read_bdf(os.path.join(here, "font_src_diff.bit"))
    assert kwidth == 16 and rwidth == 8 and hwidth == 8, (kwidth, rwidth, hwidth)

    # half width: latin from the roman font, then the JIS X 0201 overlay, which
    # is where the yen sign, the overline and the katakana live.
    half = {}
    for enc, rows in roman.items():
        if 0x20 <= enc <= 0xFF:
            half[enc] = rows_to_bytes(rows, 8)
    for enc, rows in hankaku.items():
        if 0x20 <= enc <= 0xFF:
            half[enc] = rows_to_bytes(rows, 8)

    wanted = set()
    for jis in kanji:
        row = jis >> 8
        if 0x21 <= row <= 0x28:                  # symbols, kana, greek, cyrillic
            wanted.add(jis)
    if extra_path:
        for line in open(extra_path):
            line = line.strip()
            if not line:
                continue
            sjis = int(line, 16)
            lead, trail = sjis >> 8, sjis & 0xFF
            # back to JIS, so the glyph can be found
            for jis in kanji:
                if jis_to_sjis(jis) == sjis:
                    wanted.add(jis)
                    break
            else:
                print("no glyph for sjis %04x" % sjis, file=sys.stderr)

    wide = {}
    for jis in sorted(wanted):
        sjis = jis_to_sjis(jis)
        if sjis is None or jis not in kanji:
            continue
        wide[sjis] = rows_to_bytes(kanji[jis], 16)

    out = []
    out.append("// Generated by tools/make_font.py - do not edit.")
    out.append("//")
    out.append("// The Shinonome 16-dot bitmap font, which is in the public")
    out.append("// domain: designed by Yasuyuki Furukawa, 2000, and maintained")
    out.append("// by /efont/ at http://openlab.ring.gr.jp/efont/ .  Half width")
    out.append("// is eight by sixteen and one byte a row; full width is")
    out.append("// sixteen by sixteen and two.")
    out.append("//")
    out.append("// The wide set is JIS X 0208 rows 1 to 8 plus every kanji the")
    out.append("// game's own strings use, indexed by Shift-JIS code.")
    out.append("#include \"font16.h\"")
    out.append("")
    out.append("const unsigned char kFontHalf[256][16] = {")
    for code in range(256):
        g = half.get(code, bytes(16))
        out.append("    {" + ",".join("0x%02x" % b for b in g) + "},")
    out.append("};")
    out.append("")
    out.append("const unsigned short kFontWideCode[%d] = {" % len(wide))
    codes = sorted(wide)
    for i in range(0, len(codes), 12):
        out.append("    " + " ".join("0x%04x," % c for c in codes[i:i + 12]))
    out.append("};")
    out.append("")
    out.append("const unsigned char kFontWide[%d][32] = {" % len(wide))
    for c in codes:
        out.append("    {" + ",".join("0x%02x" % b for b in wide[c]) + "},")
    out.append("};")
    out.append("")
    out.append("const unsigned kFontWideCount = %d;" % len(wide))
    out.append("")

    with open(os.path.join("src", "font16.c"), "w", encoding="utf-8") as f:
        f.write("\n".join(out))
    print("wrote src/font16.c: %d half-width, %d full-width" %
          (len(half), len(wide)))


main()
