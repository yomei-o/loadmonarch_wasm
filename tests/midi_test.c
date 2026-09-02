// Render one of the game's tunes to a WAV, so the parse and the voices can be
// heard and measured without a browser.
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/host.h"
#include "../src/midi.h"

#define RATE 22050

static void writeWav(const char *path, const float *samples, unsigned frames) {
    FILE *f = fopen(path, "wb");
    if (!f) return;
    const unsigned dataBytes = frames * 2;
    fwrite("RIFF", 1, 4, f);
    unsigned v = 36 + dataBytes; fwrite(&v, 4, 1, f);
    fwrite("WAVEfmt ", 1, 8, f);
    v = 16; fwrite(&v, 4, 1, f);
    unsigned short s = 1; fwrite(&s, 2, 1, f);       // PCM
    s = 1; fwrite(&s, 2, 1, f);                      // mono
    v = RATE; fwrite(&v, 4, 1, f);
    v = RATE * 2; fwrite(&v, 4, 1, f);
    s = 2; fwrite(&s, 2, 1, f);
    s = 16; fwrite(&s, 2, 1, f);
    fwrite("data", 1, 4, f);
    fwrite(&dataBytes, 4, 1, f);
    for (unsigned i = 0; i < frames; i++) {
        float x = samples[i];
        if (x > 1.0f) x = 1.0f;
        if (x < -1.0f) x = -1.0f;
        short pcm = (short)(x * 32000.0f);
        fwrite(&pcm, 2, 1, f);
    }
    fclose(f);
}

int main(int argc, char **argv) {
    if (argc < 4) {
        fprintf(stderr, "usage: midi_test <zip|dir> <SOUND/LM000.MID> "
                        "<out.wav> [seconds]\n");
        return 2;
    }
    static Host host;
    const size_t length = strlen(argv[1]);
    if (length > 4 && strcmp(argv[1] + length - 4, ".zip") == 0) {
        FILE *f = fopen(argv[1], "rb");
        if (!f) { perror(argv[1]); return 2; }
        fseek(f, 0, SEEK_END);
        const long size = ftell(f);
        fseek(f, 0, SEEK_SET);
        unsigned char *archive = malloc((size_t)size);
        if (!archive || fread(archive, 1, (size_t)size, f) != (size_t)size)
            return 2;
        fclose(f);
        if (!hostUseZip(&host, archive, (unsigned)size)) return 1;
    } else if (!hostUseDirectory(&host, argv[1])) {
        return 1;
    }

    static unsigned char file[0x60000];
    unsigned got = 0;
    if (!hostRead(&host, argv[2], file, sizeof file, &got)) {
        fprintf(stderr, "cannot read %s\n", argv[2]);
        return 1;
    }
    printf("%s: %u bytes\n", argv[2], got);
    midiSetRate(RATE);
    if (!midiLoad(file, got, 0)) {
        fprintf(stderr, "cannot play that file\n");
        return 1;
    }

    const unsigned seconds = argc > 4 ? (unsigned)atoi(argv[4]) : 10;
    const unsigned frames = seconds * RATE;
    float *samples = malloc(frames * sizeof *samples);
    if (!samples) return 1;
    midiRender(samples, frames, RATE);

    // Something has to have come out, and it has to be within range.
    double energy = 0;
    float peak = 0;
    for (unsigned i = 0; i < frames; i++) {
        energy += (double)samples[i] * samples[i];
        const float a = samples[i] < 0 ? -samples[i] : samples[i];
        if (a > peak) peak = a;
    }
    const double rms = energy > 0 ? sqrt(energy / frames) : 0;
    printf("%u frames, peak %.3f, rms %.4f, %s\n", frames, peak, rms,
           midiFinished() ? "reached the end" : "still playing");
    writeWav(argv[3], samples, frames);
    printf("wrote %s\n", argv[3]);
    return (rms > 0.005 && peak <= 1.001) ? 0 : 1;
}
