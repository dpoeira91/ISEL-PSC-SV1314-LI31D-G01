CFLAGS = -c -m32 -g -O1 -Wall -std=c99 -pedantic
LFLAGS = -g -m32

ex2 : ex2.o xstrpbrk.o
	gcc $(LFLAGS) -o ex2 ex2.o xstrpbrk.o

ex2.o : ex2.c
	gcc $(CFLAGS) -o ex2.o ex2.c

xstrpbrk.o : xstrpbrk.s
	gcc $(CFLAGS) -c -o xstrpbrk.o xstrpbrk.s

clean:
	rm ex2 ex2.o xstrpbrk.o


