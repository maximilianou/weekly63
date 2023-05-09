#include <stdio.h>

void main(int argc, char *argv[]) {
  int i=0;
  printf("(%d) ", argc);
  for (i=0; i<argc; i++){
    printf("%s, ", argv[i]);
  }
}
