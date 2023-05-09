#!/bin/sh

c89 -o bin/printing src/printing/print.c

./bin/printing

echo ""

c89 -o bin/args src/args/args.c

./bin/args une due tre quattro

echo ""

rm bin/printing
rm bin/args


