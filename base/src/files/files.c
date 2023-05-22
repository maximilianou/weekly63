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


*/