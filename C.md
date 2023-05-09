

```
TDD - C
https://cunit.sourceforge.net/doc/index.html

Functional C
https://research.utwente.nl/en/publications/functional-c


Object Oriented ANSI C
https://www.cs.rit.edu/~ats/books/ooc.pdf

 find .
.
./base
./base/src
./base/src/prn
./base/src/prn/print.c
./base/src/args
./base/src/args/args.c
./base/build.sh
./base/test
./base/print.o
./base/bin
./base/bin/prn
./base/bin/args
./base/args.o


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





```



