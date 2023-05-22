#!/bin/sh
# base/build.sh

mkdir -p build/lib
mkdir -p build/bin
mkdir -p build/tmp

c89 -o build/bin/printing src/printing/print.c
./build/bin/printing
echo ""
rm build/bin/printing

c89 -o build/bin/args src/args/args.c
./build/bin/args une due tre quattro
echo ""
rm build/bin/args

#c89 -o build/lib/note.o -c src/note/note.c
#c89 -o build/bin/note_test src/test/note/note_test.c build/lib/note.o
#./build/bin/note_test
#echo ""
#rm build/bin/note_test

c89 -o build/bin/files src/files/files.c 
./build/bin/files

rm -r build



