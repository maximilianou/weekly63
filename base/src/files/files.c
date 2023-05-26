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
/*    return EXIT_FAILURE; */
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
/*    return EXIT_FAILURE; */
  }
  fprintf(logfile, format_content, logcontent);
  fflush(logfile);
  fclose(logfile);
  return EXIT_SUCCESS;
}

int catfile( char* argv ){
  enum { buff_max = 32 };
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

void initial_test(){
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

void logfile_test(){
  char* logfile_name = "//'TEST.UTIL.UTSID1H.CLOG1'";
  char* logfile_rename = "//'TEST.UTIL.UTSID1H.CLOG2'";

  logfile( logfile_name, "sviluppo in linguagio C leggere e scrivere sul-dal MVS dataset\n" );
  logfile( logfile_name, "stampare nel output del unix il contenuto di MVS dataset\n" );
  logfile( logfile_name, "rinominare MVS dataset\n" );

  rename( logfile_name, logfile_rename );
    
  flogfile( logfile_rename, "[%s]\n", "Formated text fprintf()");

  catfile( logfile_rename );
/*
  remove( logfile_name );
  remove( logfile_rename );
*/
}


/* int main(int argc, char* argv[argc + 1]){ */
int main(int argc, char* argv[]){

/*  initial_test(); */
  logfile_test();


}


/*
if ( (stream = fopen("myfile2.dat", "rb+, lrecl=80,\
blksize=240, recfm=fb, type=record")) == NULL )
printf("Could not open data file for read update\n");
*/

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
C implementations may extend these classes with platform-specific characters, such as 'ä' as a lowercase character or 'e' as punctuation.
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
"%U" Week number in the year ("00" to "53"), starting at Sunday
"%W" Week number in the year ("00" to "53"), starting at Monday
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