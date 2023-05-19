/* base/src/test/test_note.c */
#include <assert.h>
#include "note.h"


void createNote_test(){  
  Note * firstNote = createNote();
  assert( firstNote != NULL );
  /* assert( firstNote == NULL ); */
}
void removeNote_test(){  
  Note * firstNote = createNote();
  firstNote->title = "TDD title";
  firstNote->body  = "TDD body";
  assert( firstNote->title != NULL );
  /*  assert( firstNote->title == NULL ); */
  removeNote(firstNote);
  assert( firstNote->title == NULL );
  /* assert( firstNote->title != NULL ); */

}

int main(int argc, char *argv[], char* env[]){

  createNote_test();
  removeNote_test();


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