CFLAGS = -Wall -pedantic -std=c99 -g -c

xprog : xprog.o xmalloc.o dlist.o
	gcc -o xprog xprog.o xmalloc.o dlist.o

xprog.o : xprog.c 
	gcc $(CFLAGS) xprog.c

xmalloc.o : xmalloc.c
	gcc $(CFLAGS) xmalloc.c

dlist.o : dlist.c
	gcc $(CFLAGS) dlist.c
	
clean :
	rm -f xprog xprog.o xmalloc.o dlist.o
