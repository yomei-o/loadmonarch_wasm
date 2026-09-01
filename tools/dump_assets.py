"""Decode the game's data files to PNG, to prove each format outright.

Formats settled by inspection (no decompiler needed):

  .256   uint32 width, uint32 height, then width*height 8-bit palette indices
  .PAL   256 RGBQUAD entries (B, G, R, 0) - a Windows DIB colour table
  .MAP   a 48x48 grid of terrain bytes, then a uint16 par value (the
         10/20/30/40/50 ladder the level list uses as its difficulty)
  .RGB   896 bytes = 224 RGBQUAD - the in-game palette blocks
  .BZ    Falcom's own compression, still to be read out of the executable

Run from the extracted DS7E_WIN directory:  python tools/dump_assets.py <dir>
"""
import os
import struct
import sys
import zlib


def png(path, w, h, rgb):
    def chunk(tag, body):
        c = tag + body
        return struct.pack('>I', len(body)) + c + struct.pack('>I', zlib.crc32(c))
    raw = b''.join(b'\0' + bytes(rgb[y * w * 3:(y + 1) * w * 3]) for y in range(h))
    with open(path, 'wb') as f:
        f.write(b'\x89PNG\r\n\x1a\n'
                + chunk(b'IHDR', struct.pack('>IIBBBBB', w, h, 8, 2, 0, 0, 0))
                + chunk(b'IDAT', zlib.compress(raw))
                + chunk(b'IEND', b''))


def load_pal(path):
    data = open(path, 'rb').read()
    return [(data[i * 4 + 2], data[i * 4 + 1], data[i * 4]) for i in range(256)]


def decode_256(path, pal):
    data = open(path, 'rb').read()
    w, h = struct.unpack_from('<II', data, 0)
    if w * h != len(data) - 8:
        raise ValueError('%s: %dx%d does not match %d bytes'
                         % (path, w, h, len(data) - 8))
    out = bytearray()
    for v in data[8:]:
        out += bytes(pal[v])
    return w, h, out


def decode_map(path):
    data = open(path, 'rb').read()
    if len(data) != 48 * 48 + 2:
        raise ValueError('%s: unexpected size %d' % (path, len(data)))
    # The trailer, not a header: every map ends in one of 10/20/30/40/50,
    # while byte 0 is simply the north-west corner's terrain.
    return struct.unpack_from('<H', data, len(data) - 2)[0], data[:48 * 48]


def main():
    root = sys.argv[1] if len(sys.argv) > 1 else '.'
    out = sys.argv[2] if len(sys.argv) > 2 else 'assets'
    os.makedirs(out, exist_ok=True)
    data_dir = os.path.join(root, 'DATA')
    for name in sorted(os.listdir(data_dir)):
        if not name.lower().endswith('.256'):
            continue
        stem = name[:-4]
        pal_path = os.path.join(data_dir, stem + '.PAL')
        if not os.path.exists(pal_path):
            continue
        w, h, rgb = decode_256(os.path.join(data_dir, name), load_pal(pal_path))
        png(os.path.join(out, stem + '.png'), w, h, rgb)
        print('%-10s %dx%d' % (stem, w, h))

    # The maps as a false-colour height field, so a wrong stride is obvious.
    map_dir = os.path.join(root, 'MAP')
    for name in sorted(os.listdir(map_dir)):
        if not name.lower().endswith('.map'):
            continue
        par, cells = decode_map(os.path.join(map_dir, name))
        rgb = bytearray()
        for v in cells:
            rgb += bytes(((v * 37) & 255, (v * 91) & 255, (v * 151) & 255))
        png(os.path.join(out, name[:-4] + '_map.png'), 48, 48, rgb)
        print('%-10s par %d' % (name, par))


if __name__ == '__main__':
    main()
