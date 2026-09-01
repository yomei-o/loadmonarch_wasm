// Reading the game out of its own zip, so nothing of it has to be shipped.
//
// A zip and an inflate, in about as little code as the format allows: the
// central directory is walked from the end, entries are matched by the tail of
// their name, and stored or deflated data is expanded in one pass.  Written in
// C rather than left to the browser so the native harness reads the same zip
// the page does, and so the port keeps its shape - the host provides bytes,
// everything else is ours.
#include "zip.h"

#include <string.h>

/* ------------------------------------------------------------- inflate */

typedef struct {
    const unsigned char *src;
    unsigned size;
    unsigned pos;               // byte position
    unsigned bit;               // bit within that byte
    int failed;
} BitStream;

static unsigned takeBit(BitStream *in) {
    if (in->pos >= in->size) { in->failed = 1; return 0; }
    const unsigned value = (in->src[in->pos] >> in->bit) & 1u;
    if (++in->bit == 8) { in->bit = 0; in->pos++; }
    return value;
}

// Deflate reads its numbers least significant bit first.
static unsigned takeBits(BitStream *in, int count) {
    unsigned value = 0;
    for (int i = 0; i < count; i++) value |= takeBit(in) << i;
    return value;
}

// A canonical Huffman table, held as the format describes it: how many codes
// of each length, and the symbols in order.
#define MAX_CODE_BITS 15
typedef struct {
    unsigned short count[MAX_CODE_BITS + 1];
    unsigned short symbol[288];
} Huffman;

static void buildHuffman(Huffman *table, const unsigned char *lengths,
                         int symbols) {
    memset(table->count, 0, sizeof table->count);
    for (int i = 0; i < symbols; i++) table->count[lengths[i]]++;
    table->count[0] = 0;
    unsigned short offset[MAX_CODE_BITS + 2];
    offset[1] = 0;
    for (int len = 1; len <= MAX_CODE_BITS; len++)
        offset[len + 1] = (unsigned short)(offset[len] + table->count[len]);
    for (int i = 0; i < symbols; i++)
        if (lengths[i]) table->symbol[offset[lengths[i]]++] = (unsigned short)i;
}

static int decodeSymbol(BitStream *in, const Huffman *table) {
    int code = 0, first = 0, index = 0;
    for (int len = 1; len <= MAX_CODE_BITS; len++) {
        code |= (int)takeBit(in);
        const int count = table->count[len];
        if (code - first < count) return table->symbol[index + (code - first)];
        index += count;
        first = (first + count) << 1;
        code <<= 1;
        if (in->failed) break;
    }
    in->failed = 1;
    return -1;
}

static const unsigned short kLengthBase[29] = {
    3, 4, 5, 6, 7, 8, 9, 10, 11, 13, 15, 17, 19, 23, 27, 31, 35, 43, 51, 59,
    67, 83, 99, 115, 131, 163, 195, 227, 258,
};
static const unsigned char kLengthExtra[29] = {
    0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4,
    5, 5, 5, 5, 0,
};
static const unsigned short kDistanceBase[30] = {
    1, 2, 3, 4, 5, 7, 9, 13, 17, 25, 33, 49, 65, 97, 129, 193, 257, 385, 513,
    769, 1025, 1537, 2049, 3073, 4097, 6145, 8193, 12289, 16385, 24577,
};
static const unsigned char kDistanceExtra[30] = {
    0, 0, 0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8, 8, 9, 9, 10, 10,
    11, 11, 12, 12, 13, 13,
};

static int inflateBlockBody(BitStream *in, const Huffman *lit,
                            const Huffman *dist, unsigned char *out,
                            unsigned capacity, unsigned *written) {
    for (;;) {
        const int symbol = decodeSymbol(in, lit);
        if (in->failed || symbol < 0) return 0;
        if (symbol < 256) {
            if (*written >= capacity) return 0;
            out[(*written)++] = (unsigned char)symbol;
            continue;
        }
        if (symbol == 256) return 1;
        const int length = symbol - 257;
        if (length >= 29) return 0;
        const unsigned count = kLengthBase[length] +
                               takeBits(in, kLengthExtra[length]);
        const int distSymbol = decodeSymbol(in, dist);
        if (distSymbol < 0 || distSymbol >= 30) return 0;
        const unsigned back = kDistanceBase[distSymbol] +
                              takeBits(in, kDistanceExtra[distSymbol]);
        if (back == 0 || back > *written) return 0;
        if (*written + count > capacity) return 0;
        // Overlapping copies are the point, so this stays byte at a time.
        for (unsigned i = 0; i < count; i++) {
            out[*written] = out[*written - back];
            (*written)++;
        }
    }
}

static void fixedTables(Huffman *lit, Huffman *dist) {
    unsigned char lengths[288];
    for (int i = 0; i < 144; i++) lengths[i] = 8;
    for (int i = 144; i < 256; i++) lengths[i] = 9;
    for (int i = 256; i < 280; i++) lengths[i] = 7;
    for (int i = 280; i < 288; i++) lengths[i] = 8;
    buildHuffman(lit, lengths, 288);
    for (int i = 0; i < 30; i++) lengths[i] = 5;
    buildHuffman(dist, lengths, 30);
}

static int dynamicTables(BitStream *in, Huffman *lit, Huffman *dist) {
    static const unsigned char kOrder[19] = {
        16, 17, 18, 0, 8, 7, 9, 6, 10, 5, 11, 4, 12, 3, 13, 2, 14, 1, 15,
    };
    const int litCount = (int)takeBits(in, 5) + 257;
    const int distCount = (int)takeBits(in, 5) + 1;
    const int codeCount = (int)takeBits(in, 4) + 4;
    if (litCount > 286 || distCount > 30) return 0;

    unsigned char codeLengths[19];
    memset(codeLengths, 0, sizeof codeLengths);
    for (int i = 0; i < codeCount; i++)
        codeLengths[kOrder[i]] = (unsigned char)takeBits(in, 3);
    Huffman codes;
    buildHuffman(&codes, codeLengths, 19);

    unsigned char lengths[286 + 30];
    memset(lengths, 0, sizeof lengths);
    int filled = 0;
    while (filled < litCount + distCount) {
        const int symbol = decodeSymbol(in, &codes);
        if (symbol < 0) return 0;
        if (symbol < 16) {
            lengths[filled++] = (unsigned char)symbol;
        } else if (symbol == 16) {
            if (filled == 0) return 0;
            const unsigned char previous = lengths[filled - 1];
            int repeat = 3 + (int)takeBits(in, 2);
            while (repeat-- && filled < litCount + distCount)
                lengths[filled++] = previous;
        } else if (symbol == 17) {
            int repeat = 3 + (int)takeBits(in, 3);
            while (repeat-- && filled < litCount + distCount)
                lengths[filled++] = 0;
        } else {
            int repeat = 11 + (int)takeBits(in, 7);
            while (repeat-- && filled < litCount + distCount)
                lengths[filled++] = 0;
        }
        if (in->failed) return 0;
    }
    buildHuffman(lit, lengths, litCount);
    buildHuffman(dist, lengths + litCount, distCount);
    return 1;
}

// Raw deflate, no zlib wrapper - which is what a zip entry holds.
static int inflateRaw(const unsigned char *src, unsigned size,
                      unsigned char *out, unsigned capacity,
                      unsigned *written) {
    BitStream in;
    memset(&in, 0, sizeof in);
    in.src = src;
    in.size = size;
    *written = 0;
    for (;;) {
        const unsigned last = takeBit(&in);
        const unsigned type = takeBits(&in, 2);
        if (in.failed) return 0;
        if (type == 0) {
            // Stored: skip to the byte boundary, then a length and its
            // complement.
            if (in.bit) { in.bit = 0; in.pos++; }
            if (in.pos + 4 > in.size) return 0;
            const unsigned count = (unsigned)in.src[in.pos] |
                                   ((unsigned)in.src[in.pos + 1] << 8);
            in.pos += 4;
            if (in.pos + count > in.size) return 0;
            if (*written + count > capacity) return 0;
            memcpy(out + *written, in.src + in.pos, count);
            in.pos += count;
            *written += count;
        } else if (type == 1 || type == 2) {
            Huffman lit, dist;
            if (type == 1) fixedTables(&lit, &dist);
            else if (!dynamicTables(&in, &lit, &dist)) return 0;
            if (!inflateBlockBody(&in, &lit, &dist, out, capacity, written))
                return 0;
        } else {
            return 0;
        }
        if (last) return 1;
    }
}

/* ----------------------------------------------------------------- zip */

static unsigned read16(const unsigned char *p) {
    return (unsigned)p[0] | ((unsigned)p[1] << 8);
}

static unsigned read32(const unsigned char *p) {
    return (unsigned)p[0] | ((unsigned)p[1] << 8) | ((unsigned)p[2] << 16) |
           ((unsigned)p[3] << 24);
}

int zipOpen(Zip *zip, const unsigned char *data, unsigned size) {
    memset(zip, 0, sizeof *zip);
    if (size < 22) return 0;
    // The end record is at the tail, after a comment of unknown length.
    unsigned end = 0;
    int found = 0;
    const unsigned limit = size > 66000u ? size - 66000u : 0;
    for (unsigned i = size - 22; i + 1 > limit; i--) {
        if (read32(data + i) == 0x06054b50u) { end = i; found = 1; break; }
        if (i == 0) break;
    }
    if (!found) return 0;
    zip->data = data;
    zip->size = size;
    zip->entryCount = read16(data + end + 10);
    zip->directory = read32(data + end + 16);
    if (zip->directory >= size) return 0;
    return 1;
}

// Matches when `name` ends with `tail`, ignoring case and treating both
// slashes alike - the zip stores DS7E_WIN/MAP/B_000.MAP and callers ask for
// MAP/B_000.MAP.
static int nameEndsWith(const unsigned char *name, unsigned length,
                        const char *tail) {
    const unsigned tailLength = (unsigned)strlen(tail);
    if (tailLength > length) return 0;
    const unsigned char *start = name + (length - tailLength);
    for (unsigned i = 0; i < tailLength; i++) {
        unsigned char a = start[i], b = (unsigned char)tail[i];
        if (a >= 'a' && a <= 'z') a = (unsigned char)(a - 32);
        if (b >= 'a' && b <= 'z') b = (unsigned char)(b - 32);
        if (a == '\\') a = '/';
        if (b == '\\') b = '/';
        if (a != b) return 0;
    }
    // Either the whole name, or a clean boundary before it.
    if (tailLength == length) return 1;
    const unsigned char before = name[length - tailLength - 1];
    return before == '/' || before == '\\';
}

int zipRead(const Zip *zip, const char *name, unsigned char *out,
            unsigned capacity, unsigned *sizeOut) {
    unsigned at = zip->directory;
    for (unsigned entry = 0; entry < zip->entryCount; entry++) {
        if (at + 46 > zip->size) return 0;
        if (read32(zip->data + at) != 0x02014b50u) return 0;
        const unsigned method = read16(zip->data + at + 10);
        const unsigned packed = read32(zip->data + at + 20);
        const unsigned unpacked = read32(zip->data + at + 24);
        const unsigned nameLength = read16(zip->data + at + 28);
        const unsigned extraLength = read16(zip->data + at + 30);
        const unsigned commentLength = read16(zip->data + at + 32);
        const unsigned localAt = read32(zip->data + at + 42);
        const unsigned char *entryName = zip->data + at + 46;

        if (nameEndsWith(entryName, nameLength, name)) {
            if (localAt + 30 > zip->size) return 0;
            if (read32(zip->data + localAt) != 0x04034b50u) return 0;
            // The local header repeats the name and may carry different extra.
            const unsigned localName = read16(zip->data + localAt + 26);
            const unsigned localExtra = read16(zip->data + localAt + 28);
            const unsigned body = localAt + 30 + localName + localExtra;
            if (body + packed > zip->size) return 0;
            if (unpacked > capacity) return 0;
            if (method == 0) {
                if (packed != unpacked) return 0;
                memcpy(out, zip->data + body, unpacked);
                *sizeOut = unpacked;
                return 1;
            }
            if (method != 8) return 0;
            unsigned written = 0;
            if (!inflateRaw(zip->data + body, packed, out, capacity, &written))
                return 0;
            if (written != unpacked) return 0;
            *sizeOut = written;
            return 1;
        }
        at += 46 + nameLength + extraLength + commentLength;
    }
    return 0;
}
