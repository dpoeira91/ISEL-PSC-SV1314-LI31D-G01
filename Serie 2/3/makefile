CFLAGS = -c -m32 -g -O1 -Wall -std=c99 -pedantic
LFLAGS = -g -m32

ex3 : ex3.o select.o
	gcc $(LFLAGS) -o ex3  ex3.o select.o

ex3.o : ex3.c
	gcc $(CFLAGS) -o ex3.o ex3.c

select.o : select.s
	gcc $(CFLAGS) -o select.o select.s

clean:
	rm ex3 ex3.o select.o

