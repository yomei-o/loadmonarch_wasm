// The game's .MID files, parsed and voiced in C.  See midi.c.
#ifndef MIDI_H
#define MIDI_H

// Takes a standard MIDI file.  Non-zero when it can be played.
int midiLoad(const unsigned char *data, unsigned size, int loop);

// Fills `frames` mono samples in -1..1 at `rate` hertz.  Non-zero when there
// is something playing.
int midiRender(float *out, unsigned frames, unsigned rate);

// Non-zero once every track has run out.
int midiFinished(void);

void midiStop(void);

#endif
