#ifndef NOTE_H
#define NOTE_H

#include <stdlib.h>

typedef struct {
/*  Note* self; */
  char* title;
  char* body;
} Note;

Note* createNote();
void removeNote(Note* note);
void showNote(Note* note);
#endif