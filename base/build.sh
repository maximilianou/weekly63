#!/bin/sh
# base/build.sh

c89 -o bin/printing src/printing/print.c
./bin/printing
echo ""
rm bin/printing

c89 -o bin/args src/args/args.c
./bin/args une due tre quattro
echo ""
rm bin/args

mkdir -p build/lib
c89 -o build/lib/note.o -c src/test/note.c
c89 -o bin/note_test src/test/note_test.c build/lib/note.o
./bin/note_test
echo ""
rm bin/note_test
rm -r build



