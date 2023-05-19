/* base/src/test/note.c */
#include "note.h"
#include <stdlib.h>
#include <stdio.h>

Note* createNote(){
    Note* note = (Note *)malloc(sizeof(Note));
/*    (*note).self  = note; */
    (*note).title = "default title";
    (*note).body  = "default body";
    return note;
}

void removeNote(Note* note){
  printf("\n %i \n", note == NULL);
  free(note);
  printf("\n %i \n", note == NULL);
}

void showNote(Note* note){
  printf("|%s|:%s", note->title, note->body );
}