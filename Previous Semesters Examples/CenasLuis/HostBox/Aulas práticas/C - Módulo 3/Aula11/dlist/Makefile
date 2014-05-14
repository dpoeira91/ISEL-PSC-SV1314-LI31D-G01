prog : prog.o dlist.o myassert.o
	gcc -o prog prog.o dlist.o myassert.o

myassert.o : myassert.c
	gcc -Wall -DNDEBUG -pedantic -std=c99 -O2 -c myassert.c

dlist.o : dlist.c
	gcc -Wall -DNDEBUG -pedantic -std=c99 -O2 -c dlist.c

prog.o : prog.c
	gcc -Wall -DNDEBUG -pedantic -std=c99 -O2 -c prog.c
