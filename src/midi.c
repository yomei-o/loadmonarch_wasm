// The music, from the game's own .MID files.
//
// The original hands them to MCI and lets Windows find a synthesiser.  There is
// none in a browser, so the port renders them itself - and rather than keep the
// single softened sawtooth this file used to carry, it now drives the wavetable
// synthesiser from the sibling port windepth_wasm (src/synth.c, src/smf.c),
// which has a General-MIDI-ish instrument set, three band-limited tables per
// voice, an ADSR each, panning and hand-made drums for channel ten.  Falcom
// wrote these tunes for a sound card of about 1990 and that is what it sounds
// like.
//
// What is left here is the shape the rest of the port already asked for: load
// an image, render at a rate, say when it has run out.
#include "midi.h"

#include "synth.h"

#include <string.h>

static Music g_music;
static int g_rate;                  // what mus_init was last given
static int g_loaded;

// The synthesiser is told its rate once and keeps it, so the rate has to be
// settled before a tune is loaded rather than when it is rendered - the
// wavetables and every envelope slope are built from it.  A host that changes
// rate loses what was playing and reloads; the one that does not need never
// call this at all, and 22050 is what both of this port's hosts ask for.
static void setRate(unsigned rate) {
    const int want = rate ? (int)rate : 22050;
    if (g_rate == want) return;
    if (g_loaded) {
        mus_stop(&g_music);
        mus_free(&g_music);
        g_loaded = 0;
    }
    mus_init(&g_music, want);
    // 0.55 is the synthesiser's own, and these tunes come out around a third
    // of full scale with it; the loudest peaks at 0.47, so this leaves headroom
    // and still sounds like music rather than a whisper.
    mus_set_gain(&g_music, 0.9f);
    g_rate = want;
}

void midiSetRate(unsigned rate) { setRate(rate); }

int midiLoad(const unsigned char *data, unsigned size, int loop) {
    setRate((unsigned)(g_rate ? g_rate : 22050));
    if (g_loaded) {
        mus_stop(&g_music);
        mus_free(&g_music);
        g_loaded = 0;
        mus_init(&g_music, g_rate);
    }
    if (mus_load(&g_music, data, (long)size) != 0) return 0;
    g_loaded = 1;
    mus_play(&g_music, loop);
    return 1;
}

int midiRenderStereo(float *left, float *right, unsigned frames,
                     unsigned rate) {
    // The rate is settled at load time; a caller that asks for a different one
    // here is told about it by getting silence rather than a tune at the wrong
    // speed, and should call midiSetRate before loading.
    if (rate && (int)rate != g_rate) setRate(rate);
    if (!g_loaded) {
        memset(left, 0, frames * sizeof *left);
        memset(right, 0, frames * sizeof *right);
        return 0;
    }
    mus_render(&g_music, left, right, (int)frames);
    return g_music.playing;
}

int midiRender(float *out, unsigned frames, unsigned rate) {
    // Mono, for a host that wants one channel: the two summed and halved, which
    // is what a mono output does to a panned mix.
    enum { CHUNK = 512 };
    static float left[CHUNK], right[CHUNK];
    int playing = 0;
    unsigned done = 0;
    while (done < frames) {
        unsigned n = frames - done;
        if (n > CHUNK) n = CHUNK;
        playing = midiRenderStereo(left, right, n, rate);
        for (unsigned i = 0; i < n; i++)
            out[done + i] = (left[i] + right[i]) * 0.5f;
        done += n;
    }
    return playing;
}

int midiFinished(void) { return !g_loaded || !g_music.playing; }

void midiStop(void) {
    if (g_loaded) mus_stop(&g_music);
}
