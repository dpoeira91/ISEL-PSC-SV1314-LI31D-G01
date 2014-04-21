CFLAGS = -c -m32 -g -O1 -Wall -std=c99 -pedantic
LFLAGS = -g -m32

ex1 : ex1.o reverse.o
	gcc $(LFLAGS) -o ex1 ex1.o reverse.o

ex1.o : ex1.c
	gcc $(CFLAGS) -o ex1.o ex1.c

reverse.o : reverse.s
	gcc $(CFLAGS) -c -o reverse.o reverse.s

clean:
	rm ex1 ex1.o reverse.o


