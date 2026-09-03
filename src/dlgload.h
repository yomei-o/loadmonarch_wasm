// The dialogs as the loaded release has them.
//
// src/dlgdefs.c is a transcription of the English release's DLGTEMPLATEs, and
// the Japanese release is not laid out the same way: its 104 is thirty-one
// dialog units taller and a control fewer, its 126 has two of its buttons
// somewhere else, and every caption in it is Japanese.  So the templates are
// read out of whichever executable was opened, the way the menu is, and
// dlgdefs.c is what stands when there is nothing to read.
//
// The one piece of judgement here is which of the port's own widget kinds a
// resource control is, which its class and the low bits of its style say -
// BUTTON with BS_AUTOCHECKBOX is a check box, STATIC with SS_ICON is where the
// program's icon goes, and so on.  Everything else - the ids, the rectangles,
// the captions, the order - is the resource's.
#ifndef DLGLOAD_H
#define DLGLOAD_H

#include "dlg.h"
#include "dlgrun.h"
#include "host.h"

// Reads DS7E_WIN.EXE or DS7J_WIN.EXE out of the archive and fills the store.
// Answers how many of the twelve it recognised, or nought if there was no
// executable to read - and then everything falls back to dlgdefs.c.
int dlgLoadFromHost(const Host *host);

// The loaded template for one of the port's dialogs, or null.
const DlgTemplate *dlgLoaded(DlgWhich which);

// Which resource id each of the port's dialogs is, for anything that wants to
// go and look: 0 where the port has no dialog of its own for it.
unsigned dlgResourceId(DlgWhich which);

#endif
