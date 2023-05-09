#include "note.h"


int main(int argc, char *argv[]){

  /* TODO: create a note */
  /* TODO: verify note created */
  Note * firstNote = createNote();
  Note * secondNote = firstNote;

  /* TODO: show note */
  /* TODO: verify note showed */
  showNote(firstNote);
  showNote(secondNote);

  /* TODO: remove note */
  /* TODO: verify note removed */
  removeNote(firstNote);
  showNote(secondNote);
  
  return 0;
}