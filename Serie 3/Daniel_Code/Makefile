CFLAGS = -c -m32 -g -O1 -Wall -std=c99 -pedantic
LFLAGS = -g -m32

lib : libWork.so mainGetFile

libWork.so : libWork.o
	gcc -shared -o libWork.so libWork.o -lcurl -ljansson -ldl

libWork.o : libWork.c
	gcc $(CFLAGS) -fPIC -o libWork.o libWork.c

mainGetFile: mainGetFile.o libWork.o
	gcc $(LFLAGS) -o mainGetFile mainGetFile.o ./libWork.so

mainGetFile.o : mainGetFile.c
	gcc $(CFLAGS) -fPIC -o mainGetFile.o mainGetFile.c

clean:
	rm ./libWork.o libWork.so mainGetFile mainGetFile.o
