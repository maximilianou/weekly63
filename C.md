

```
TDD - C
https://cunit.sourceforge.net/doc/index.html

Functional C
https://research.utwente.nl/en/publications/functional-c


Object Oriented ANSI C
https://www.cs.rit.edu/~ats/books/ooc.pdf



cat build.sh 
#!/bin/sh
c89 -o bin/prn src/prn/print.c
./bin/prn
echo ""
c89 -o bin/args src/args/args.c
./bin/args une due tre quattro
echo ""

cat prn/print.c 
#include <stdio.h>
int main(void){
  printf("Step by Step");
  return 0; 
}


cat args/args.c 
#include <stdio.h>
void main(int argc, char *argv[]) {
  int i=0;
  printf("(%d) ", argc);
  for (i=0; i<argc; i++){
    printf("%s, ", argv[i]);
  }
}

----------------------------------

/* base/src/test/note.h */
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
#endif.


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
  free(note);
}

void showNote(Note* note){
  printf("|%s|:%s", note->title, note->body );
}



/* base/src/test/test_note.c */
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


# base/Makefile

note.o: 
	c89 -o lib/note.o -c src/test/note.c

test_note: note.o
	c89 -o bin/test_note src/test/test_note.c lib/note.o

test: test_note
	./bin/test_note

clean:
	rm lib/note.o
	rm bin/test_note



#!/bin/sh
# base/buld.sh
c89 -o bin/printing src/printing/print.c
./bin/printing
echo ""
rm bin/printing

c89 -o bin/args src/args/args.c
./bin/args une due tre quattro
echo ""
rm bin/args

c89 -o lib/note.o -c src/test/note.c
c89 -o bin/test_note src/test/test_note.c lib/note.o
./bin/test_note
echo ""
rm bin/test_note











```



