# base/Makefile

all: test clean

test: note_test
	./bin/note_test

note.o: directory
	c89 -c src/test/note.c -o build/lib/note.o

note_test: note.o 
	c89 src/test/note_test.c build/lib/note.o -o bin/note_test

directory:
	mkdir -p build/lib

clean:
	rm -r build
	rm bin/note_test

variable:
	echo $(CXX)
	echo $(CC)
