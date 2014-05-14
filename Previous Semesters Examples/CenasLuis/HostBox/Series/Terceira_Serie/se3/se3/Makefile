CFLAGS = -Wall -pedantic -std=c99 -g -c

rdfat : fat32lib.so rdfat.o
	gcc -rdynamic -o rdfat rdfat.o -ldl
	
fileList.o : fileList.c 
	gcc $(CFLAGS) fileList.c

fatapp.o : fatapp.c
	gcc $(CFLAGS) fatapp.c

rdfat.o : rdfat.c
	gcc $(CFLAGS) rdfat.c
	
fat32lib.so : fileList.o fatapp.o
	gcc -o fat32lib.so -shared fileList.o fatapp.o
	
clean :
	rm -f rdfat fileList.o fatapp.o rdfat.o

test1 :
	rdfat myfat.bin text10.txt fileCpy1.txt
	
test2 :
	rdfat myfat.bin text3.txt fileCpy2.txt

test3 :
	rdfat myfat.bin /Pictures/Empty.txt fileCpy3.txt

test4 : 
	rdfat myfat.bin /Folder/Other/Here/Folder.txt fileCpy4.txt

test5 :
	rdfat myfat.bin /Folder/Other/There/Folder.txt fileCpy5.txt

tests : test1 test2 test3 test4 test5

clearFiles:
	rm -f fileCpy1.txt fileCpy2.txt fileCpy3.txt fileCpy4.txt fileCpy5.txt
