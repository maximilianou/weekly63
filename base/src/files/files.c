#include <stdio.h>
#include <stdlib.h>

int logfile(char* logfilename, char* logcontent){
  FILE* logfile = fopen(logfilename,"a");
  if( !logfile ){
    perror("fopen_failed");
    return EXIT_FAILURE;
  }
  fputs(logcontent, logfile);
  fflush(logfile);
  fclose(logfile);
  return EXIT_SUCCESS;
}



int main(int argc, char* argv[argc + 1]){
  return logfile("build/tmp/logfile.log", "feeling_fine_today\n");
/*
  FILE* logfile = fopen("logfile.log","a");
  if( !logfile ){
    perror("fopen_filed");
    return EXIT_FAILURE;
  }
  fputs("feeling_fine_today\n", logfile);
  fflush(logfile);
  fclose(logfile);
  return EXIT_SUCCESS;
*/  
}

