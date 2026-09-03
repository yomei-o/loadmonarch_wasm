// The tool bar the game draws instead of a second row of words: twenty-three
// 16x16 icons out of BITMAP 102, and the command each of them sends out of the
// MFC tool bar resource beside it.  tools/make_toolbar.py builds toolbar.c.
#ifndef TOOLBAR_H
#define TOOLBAR_H

extern const int kToolbarW, kToolbarH, kToolbarButton, kToolbarIcons;
extern const unsigned char kToolbarPalette[16][3];
extern const unsigned char kToolbarPixels[];

// One entry a button, in the order they sit on the bar; zero is a separator.
extern const unsigned short kToolbarCommand[];
extern const int kToolbarButtons;

#endif
