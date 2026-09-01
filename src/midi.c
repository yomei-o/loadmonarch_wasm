// The music, from the game's own .MID files.
//
// The original hands them to MCI and lets Windows find a synthesiser.  There
// is no synthesiser in a browser, so this reads the file and makes the sound
// itself: a standard MIDI parse, then a small subtractive voice per note.  It
// is not a General MIDI instrument set and does not pretend to be - it is the
// notes, in tune and in time, which is what carries a Falcom tune.
//
// Everything stays in C so the native build can write a WAV of the same
// rendering and the two can be compared.
#include "midi.h"

#include <math.h>
#include <string.h>

#define MAX_TRACKS 32
#define MAX_VOICES 24

typedef struct {
    const unsigned char *at;
    const unsigned char *end;
    unsigned long long when;    // absolute tick of the pending event
    unsigned char running;      // the running status byte
    int done;
} Track;

typedef struct {
    int active;
    int note;
    float frequency;
    float phase;
    float amplitude;            // where the envelope is
    float target;               // where it is heading
    int releasing;
    unsigned char channel;
    int percussive;             // channel 10, rendered as noise
    unsigned noise;             // its own little generator
} Voice;

typedef struct {
    Track tracks[MAX_TRACKS];
    int trackCount;
    Voice voices[MAX_VOICES];
    unsigned division;          // ticks per quarter note
    unsigned tempo;             // microseconds per quarter note
    unsigned long long tick;    // where playback has reached
    double tickRemainder;       // fractional ticks carried between blocks
    int finished;
} Player;

static Player g_player;
static int g_ready;
static int g_loop;

static unsigned read32be(const unsigned char *p) {
    return ((unsigned)p[0] << 24) | ((unsigned)p[1] << 16) |
           ((unsigned)p[2] << 8) | (unsigned)p[3];
}

static unsigned read16be(const unsigned char *p) {
    return ((unsigned)p[0] << 8) | (unsigned)p[1];
}

// MIDI's variable-length quantity: seven bits a byte, top bit continues.
static unsigned long long readVarint(const unsigned char **at,
                                     const unsigned char *end) {
    unsigned long long value = 0;
    while (*at < end) {
        const unsigned char byte = *(*at)++;
        value = (value << 7) | (byte & 0x7f);
        if ((byte & 0x80) == 0) break;
    }
    return value;
}

static void advanceTrack(Track *track) {
    if (track->at >= track->end) { track->done = 1; return; }
    track->when += readVarint(&track->at, track->end);
}

int midiLoad(const unsigned char *data, unsigned size, int loop) {
    memset(&g_player, 0, sizeof g_player);
    g_ready = 0;
    g_loop = loop;
    if (size < 14 || memcmp(data, "MThd", 4) != 0) return 0;
    const unsigned headerLength = read32be(data + 4);
    if (headerLength < 6) return 0;
    g_player.division = read16be(data + 12);
    if (g_player.division == 0 || (g_player.division & 0x8000u)) {
        // SMPTE division; the game's files are metrical, so decline rather
        // than play at the wrong speed.
        return 0;
    }
    g_player.tempo = 500000;        // 120 bpm until the file says otherwise

    unsigned at = 8 + headerLength;
    while (at + 8 <= size && g_player.trackCount < MAX_TRACKS) {
        const unsigned length = read32be(data + at + 4);
        if (memcmp(data + at, "MTrk", 4) == 0) {
            if (at + 8 + length > size) break;
            Track *track = &g_player.tracks[g_player.trackCount++];
            track->at = data + at + 8;
            track->end = track->at + length;
            track->running = 0;
            track->when = 0;
            track->done = 0;
            advanceTrack(track);
        }
        at += 8 + length;
    }
    if (g_player.trackCount == 0) return 0;
    g_ready = 1;
    return 1;
}

static float noteFrequency(int note) {
    return 440.0f * powf(2.0f, (float)(note - 69) / 12.0f);
}

static void startNote(unsigned char channel, int note, int velocity) {
    Voice *chosen = NULL;
    for (int i = 0; i < MAX_VOICES; i++) {
        if (!g_player.voices[i].active) { chosen = &g_player.voices[i]; break; }
    }
    if (!chosen) {
        // Steal the quietest, so a busy passage loses the least.
        float quietest = 1e9f;
        for (int i = 0; i < MAX_VOICES; i++) {
            if (g_player.voices[i].amplitude < quietest) {
                quietest = g_player.voices[i].amplitude;
                chosen = &g_player.voices[i];
            }
        }
    }
    memset(chosen, 0, sizeof *chosen);
    chosen->active = 1;
    chosen->note = note;
    chosen->channel = channel;
    chosen->percussive = channel == 9;      // the drum channel, zero-based
    chosen->frequency = noteFrequency(note);
    chosen->target = (float)velocity / 127.0f * 0.22f;
    chosen->noise = (unsigned)(note * 2654435761u) | 1u;
}

static void stopNote(unsigned char channel, int note) {
    for (int i = 0; i < MAX_VOICES; i++) {
        Voice *voice = &g_player.voices[i];
        if (voice->active && voice->channel == channel && voice->note == note)
            voice->releasing = 1;
    }
}

static void handleEvent(Track *track) {
    if (track->at >= track->end) { track->done = 1; return; }
    unsigned char status = *track->at;
    if (status & 0x80) {
        track->at++;
        track->running = status;
    } else {
        status = track->running;
        if (!status) { track->done = 1; return; }
    }

    if (status == 0xff) {
        if (track->at >= track->end) { track->done = 1; return; }
        const unsigned char meta = *track->at++;
        const unsigned long long length = readVarint(&track->at, track->end);
        if (meta == 0x51 && length >= 3 && track->at + 3 <= track->end) {
            g_player.tempo = ((unsigned)track->at[0] << 16) |
                             ((unsigned)track->at[1] << 8) |
                             (unsigned)track->at[2];
        }
        track->at += length;
        if (meta == 0x2f) track->done = 1;
        return;
    }
    if (status == 0xf0 || status == 0xf7) {
        const unsigned long long length = readVarint(&track->at, track->end);
        track->at += length;
        return;
    }

    const unsigned char kind = status & 0xf0;
    const unsigned char channel = status & 0x0f;
    const int twoBytes = kind != 0xc0 && kind != 0xd0;
    if (track->at + (twoBytes ? 2 : 1) > track->end) {
        track->done = 1;
        return;
    }
    const unsigned char first = *track->at++;
    const unsigned char second = twoBytes ? *track->at++ : 0;

    if (kind == 0x90 && second > 0) startNote(channel, first, second);
    else if (kind == 0x80 || (kind == 0x90 && second == 0))
        stopNote(channel, first);
    else if (kind == 0xb0 && first == 123) {
        for (int i = 0; i < MAX_VOICES; i++)
            if (g_player.voices[i].channel == channel)
                g_player.voices[i].releasing = 1;
    }
}

// One voice's sample.  A sawtooth softened towards a triangle reads closer to
// the FM instruments these tunes were written for than a square does.
static float voiceSample(Voice *voice, float rate) {
    if (voice->percussive) {
        voice->noise = voice->noise * 1664525u + 1013904223u;
        const float noise = (float)((int)(voice->noise >> 16) & 0xffff) /
                            32768.0f - 1.0f;
        return noise * voice->amplitude;
    }
    voice->phase += voice->frequency / rate;
    if (voice->phase >= 1.0f) voice->phase -= 1.0f;
    const float saw = voice->phase * 2.0f - 1.0f;
    const float triangle = 1.0f - 4.0f * fabsf(voice->phase - 0.5f);
    return (saw * 0.35f + triangle * 0.65f) * voice->amplitude;
}

int midiRender(float *out, unsigned frames, unsigned rate) {
    memset(out, 0, frames * sizeof *out);
    if (!g_ready) return 0;

    const float attack = 1.0f / (0.004f * (float)rate);
    const float decay = 1.0f / (0.35f * (float)rate);

    for (unsigned f = 0; f < frames; f++) {
        // Ticks are consumed at the tempo the file last asked for.
        const double ticksPerSecond =
            1000000.0 / (double)g_player.tempo * (double)g_player.division;
        g_player.tickRemainder += ticksPerSecond / (double)rate;
        while (g_player.tickRemainder >= 1.0) {
            g_player.tickRemainder -= 1.0;
            g_player.tick++;
            int alive = 0;
            for (int t = 0; t < g_player.trackCount; t++) {
                Track *track = &g_player.tracks[t];
                while (!track->done && track->when <= g_player.tick) {
                    handleEvent(track);
                    if (!track->done) advanceTrack(track);
                }
                if (!track->done) alive = 1;
            }
            if (!alive) {
                g_player.finished = 1;
                if (g_loop) {
                    // Start the tracks over without disturbing the voices.
                    for (int t = 0; t < g_player.trackCount; t++) {
                        Track *track = &g_player.tracks[t];
                        track->at = track->end - (track->end - track->at);
                    }
                    g_player.finished = 1;      // the host decides to reload
                }
            }
        }

        float mix = 0.0f;
        for (int i = 0; i < MAX_VOICES; i++) {
            Voice *voice = &g_player.voices[i];
            if (!voice->active) continue;
            if (voice->releasing) {
                voice->amplitude -= decay * voice->target;
                if (voice->amplitude <= 0.0f) { voice->active = 0; continue; }
            } else if (voice->amplitude < voice->target) {
                voice->amplitude += attack * voice->target;
                if (voice->amplitude > voice->target)
                    voice->amplitude = voice->target;
            }
            mix += voiceSample(voice, (float)rate);
        }
        // A soft knee rather than a hard clip, so a dense chord does not
        // crackle.
        out[f] = tanhf(mix);
    }
    return 1;
}

int midiFinished(void) { return g_player.finished; }
void midiStop(void) { g_ready = 0; memset(&g_player, 0, sizeof g_player); }
