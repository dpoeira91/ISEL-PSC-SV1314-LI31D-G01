CFLAGS = -c -m32 -g -O1 -Wall -std=c99 -pedantic
LFLAGS = -g -m32

all: lib mainGetFile

lib : libWork.so

libWork.so : libWork.o
	gcc -shared -o libWork.so libWork.o -lcurl -ljansson -ldl

libWork.o : libWork.c
	gcc $(CFLAGS) -fPIC -o libWork.o libWork.c


mainJson : mainJson.o libWork.so
	gcc $(LFLAGS) -o mainJson mainJson.o

mainJson.o : mainJson.c libWork.so
	gcc $(CFLAGS) -fPIC -o mainJson.o mainJson.c


mainGetFile : mainGetFile.o
	gcc $(LFLAGS) -o mainGetFile mainGetFile.o libWork.so

mainGetFile.o : mainGetFile.c
	gcc $(CFLAGS) -fPIC -o mainGetFile.o mainGetFile.c

clean:
	rm ./workLib workLib.so libWork.o mainJson mainJson.o mainGetFile mainGetFile.o 
