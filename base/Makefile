

note.o: 
	c89 -o lib/note.o -c src/test/note.c

test_note: note.o
	c89 -o bin/test_note src/test/test_note.c lib/note.o

test: test_note
	./bin/test_note