// The game's .MID files, parsed and voiced in C.  See midi.c.
#ifndef MIDI_H
#define MIDI_H

// The synthesiser builds its wavetables and envelope slopes from the sample
// rate, so a host says what its rate is once, before the first load.  22050 if
// nobody says.
void midiSetRate(unsigned rate);

// Takes a standard MIDI file.  Non-zero when it can be played.
int midiLoad(const unsigned char *data, unsigned size, int loop);

// Fills `frames` mono samples in -1..1 at `rate` hertz.  Non-zero when there
// is something playing.
int midiRender(float *out, unsigned frames, unsigned rate);

// The same in stereo, which is what the synthesiser actually makes - the
// instruments are panned.
int midiRenderStereo(float *left, float *right, unsigned frames,
                     unsigned rate);

// Non-zero once every track has run out.
int midiFinished(void);

void midiStop(void);

#endif
