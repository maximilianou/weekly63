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


