CFLAGS = -c -m32 -g -O1 -Wall -std=c99 -pedantic

all: mylib.so mainJson mainGetFile


mylib.so : http_get_json.o http_get_file.o
	gcc -o mylib.so -shared http_get_json.o http_get_file.o

mainJson : mylib.so mainJson.o
	gcc -rdynamic -o mainJson mainJson.o mylib.so -ldl -lcurl -ljansson

mainGetFile : mylib.so mainGetFile.o
	gcc -rdynamic -o mainGetFile mainGetFile.o mylib.so -ldl -lcurl -ljansson


#torna-se trivial	
#http_get_json.o : http_get_json.c
#	gcc $(CFLAGS) http_get_json.c
	
#http_get_file.o : http_get_file.c
#	gcc $(CFLAGS) http_get_file.c
	

# torna-se trivial
#mainJson.o : mainJson.c 
#	gcc $(CFLAGS) mainJson.c
#	
#mainGetFile.o : mainGetFile.c
#	gcc $(CFLAGS) mainGetFile.c
clean:
	rm mainJson mainJson.o mainGetFile mainGetFile.o
