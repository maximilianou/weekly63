# base/Makefile

all: test clean

test: note_test
	./build/bin/note_test

note.o: directory
	c89 -c src/note/note.c -o build/lib/note.o

note_test: note.o 
	c89 src/test/note/note_test.c build/lib/note.o -o build/bin/note_test

directory:
	mkdir -p build/lib
	mkdir -p build/bin
	mkdir -p build/tmp

clean:
	rm -r build

variable:
	echo $(CXX)
	echo $(CC)

###
files: directory
	$(CC) src/files/files.c -o build/bin/files
	./build/bin/files
