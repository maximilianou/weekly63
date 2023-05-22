

```
TDD - C
https://cunit.sourceforge.net/doc/index.html

Functional C
https://research.utwente.nl/en/publications/functional-c


Object Oriented ANSI C
https://www.cs.rit.edu/~ats/books/ooc.pdf


Modern C
Jens Gustedt. Modern C. Manning, 2019, 9781617295812. ffhal-02383654



Regular program termination should use a return from main

Use exit from a function that may terminate the regular control flow.

Don’t use functions other than exit for program termination, unless
you have to inhibit the execution of library cleanups

Use as many assert s as you can to confirm runtime properties.

In production compilations, use NDEBUG to switch off all assert

```

```

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

```




# base/Makefile

all: test clean

test: note_test
	./build/bin/note_test

note.o: directory
	c89 -c src/note/note.c -o build/lib/note.o

note_test: note.o 
	c89 src/test/note/note_test.c build/lib/note.o -o build/bin/note_test

directory:
	mkdir -p build/lib
	mkdir -p build/bin
	mkdir -p build/tmp

clean:
	rm -r build

variable:
	echo $(CXX)
	echo $(CC)

###
files: directory
	$(CC) src/files/files.c -o build/bin/files
	./build/bin/files





#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include <errno.h>

int logfile(char* logfilename, char* logcontent){
  FILE* logfile = fopen(logfilename,"a");
  if( !logfile ){
    perror("fopen_failed");
    exit(EXIT_FAILURE);
//    return EXIT_FAILURE;
  }
  fputs(logcontent, logfile);
  fflush(logfile);
  fclose(logfile);
  return EXIT_SUCCESS;
}


int flogfile(char* logfilename, char* format_content, char* logcontent){
  FILE* logfile = fopen(logfilename,"a");
  if( !logfile ){
    perror("fopen_failed");
    exit(EXIT_FAILURE);
//    return EXIT_FAILURE;
  }
  fprintf(logfile, format_content, logcontent);
  fflush(logfile);
  fclose(logfile);
  return EXIT_SUCCESS;
}

int catfile( char* argv ){
  enum { buff_max = 32, };
  int ret = EXIT_FAILURE;
  char buffer[buff_max] = { 0 };
  FILE* instream = fopen(  argv, "r" );
  if( instream ){
    while( fgets( buffer, buff_max, instream ) ){
      fputs( buffer, stdout );
    }
    fclose(instream);
    ret = EXIT_SUCCESS;
  }else{
    fprintf(stderr, "Could not open %s", argv);
    perror(0);
    errno = 0;
  }
  return ret;
}

int main(int argc, char* argv[argc + 1]){
  char* logfile_name = "build/tmp/logfile.log";
  char* logfile_rename = "build/tmp/logfile_rename.log";

  logfile( logfile_name, "feeling_fine_today\n" );

  assert( access(logfile_name, F_OK) == 0 );

  rename( logfile_name, logfile_rename );

  assert( access(logfile_rename, F_OK) == 0 );
  assert( access(logfile_name, F_OK) != 0 );
    
  flogfile( logfile_rename, "[%s]\n", "Formated text fprintf()");

  catfile( logfile_rename );

  remove( logfile_name );
  remove( logfile_rename );

  assert( access(logfile_rename, F_OK) != 0 );
  assert( access(logfile_name, F_OK) != 0 );

}

/*
REFERENCE:
To cite this version:
Jens Gustedt. Modern C. Manning, 2019, 9781617295812. ffhal-02383654

TABLE 8.6. Format specifications for printf and similar functions,
with the general syntax "%[FF][WW][.PP][LL]SS", where [] surrounding a field denotes that it is optional.
FF Flags Special form of conversion
WW Field width minimum width
PP Precision
LL Modifier Select width of type
SS Specifier Select conversion
TABLE 8.7. Format specifiers for printf and similar functions
'd' or 'i' Decimal Signed integer
'u' Decimal Unsigned integer
'o' Octal Unsigned integer
'x' or 'X' Hexadecimal Unsigned integer
'e' or 'E' [-]d.ddd e±dd, “scientific” Floating point
'f' or 'F' [-]d.ddd Floating point
'g' or 'G' generic e or f Floating point
'a' or 'A' [-]0xh.hhhh p±d, Hexadecimal Floating point
'%' '%' character No argument is converted.
'c' Character Integer
's' Characters String
'p' Address void* pointer

TABLE 8.9. Format modifiers for printf and similar functions. float
arguments are first converted to double.
Character Type Conversion
"hh" char types Integer
"h" short types Integer
"" signed, unsigned Integer
"l" long integer types integer
"ll" long long integer types Integer
"j" intmax_t, uintmax_t Integer
"z" size_t Integer
"t" ptrdiff_t Integer
"L" long double Floating point

TABLE 8.10. Format flags for printf and similar functions
Character Meaning Conversion
"#" Alternate form, such as prefix 0x "aAeEfFgGoxX"
"0" Zero padding Numeric
"-" Left adjustment Any
"␣" '␣' for positive values, '-' for negative Signed
"+" '+' for positive values, '-' for negative Signed



ctype.h

ABLE 8.11. Character classifiers. The third column indicates whether
C implementations may extend these classes with platform-specific characters, such as 'ä' as a lowercase character or 'e' as punctuation.
Name Meaning C locale Extended
islower Lowercase 'a' · · · 'z' Yes
isupper Uppercase 'A' · · · 'Z' Yes
isblank Blank '␣', '\t' Yes
isspace Space '␣', '\f', '\n', '\r', '\t', '\v' Yes
isdigit Decimal '0' · · · '9' No
isxdigit Hexadecimal '0' · · · '9', 'a' · · · 'f', 'A' · · · 'F' No
iscntrl Control '\a', '\b', '\f', '\n', '\r', '\t', '\v' Yes
isalnum Alphanumeric isalpha(x)||isdigit(x) Yes
isalpha Alphabet islower(x)||isupper(x) Yes
isgraph Graphical (!iscntrl(x)) && (x != '␣') Yes
isprint Printable !iscntrl(x) Yes
ispunct Punctuation isprint(x)&&!(isalnum(x)||isspace(x)) Yes
'\'' Quote
'\"' Double quotes
'\?' Question mark
'\\' Backslash
'\a' Alert
'\b' Backspace
'\f' Form feed
'\n' New line
'\r' Carriage return
'\t' Horizontal tab
'\v' Vertical tab
TABLE 8.12. Special characters in character and string literals




TABLE 8.13. strftime format specifiers. Those selected in the Locale
column may differ dynamically according to locale runtime settings; see
subsection 8.6. Those selected in the ISO 8601 column are specified by
that standard.
Spec Meaning Locale ISO 8601
"%S" Second ("00" to "60")
"%M" Minute ("00" to "59")
"%H" Hour ("00" to "23").
"%I" Hour ("01" to "12").
"%e" Day of the month ("␣1" to "31")
"%d" Day of the month ("01" to "31")
"%m" Month ("01" to "12")
"%B" Full month name X
"%b" Abbreviated month name X
"%h" Equivalent to "%b" X
"%Y" Year
"%y" Year ("00" to "99")
"%C" Century number (year/100)
"%G" Week-based year; the same as "%Y", except if the ISO
week number belongs another year
X
"%g" Like "%G", ("00" to "99") X
"%u" Weekday ("1" to "7"), Monday being "1"
"%w" Weekday ("0" to "6", Sunday being "0"
"%A" Full weekday name X
"%a" Abbreviated weekday name X
"%j" Day of the year ("001" to "366")
"%U" Week number in the year ("00" to "53"), starting at Sunday
"%W" Week number in the year ("00" to "53"), starting at Monday
"%V" Week number in the year ("01" to "53"), starting with
first four days in the new year
X
"%Z" Timezone name X
"%z" "+hhmm" or "-hhmm", the hour and minute offset from
UTC
"%n" Newline
"%t" Horizontal tabulator
"%%" Literal "%"
"%x" Date X
"%D" Equivalent to "%m/%d/%y"
"%F" Equivalent to "%Y-%m-%d" X
"%X" Time X
"%p" Either "AM" or "PM": noon is "PM", midnight is "AM" X
"%r" Equivalent to "%I:%M:%S␣%p" X
"%R" Equivalent to "%H:%M"
"%T" Equivalent to "%H:%M:%S" X
"%c" Preferred date and time representation 
*/




```



