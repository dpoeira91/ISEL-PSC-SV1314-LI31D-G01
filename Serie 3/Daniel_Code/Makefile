CFLAGS = -c -m32 -g -O1 -Wall -std=c99 -pedantic
LFLAGS = -g -m32
all: mylib.so mainJson mainGetFile


#mylib.so : http_get_json.o http_get_file.o
#	gcc -o mylib.so -shared http_get_json.o http_get_file.o

mylib.so : http_get_json.o http_get_file.o
	gcc $(LFLAGS) -o mylib.so http_get_json.o http_get_file.o 

##mainJson : mylib.so mainJson.o
##	gcc -rdynamic -o mainJson mainJson.o -ldl -lcurl -ljansson

mainJson : mainJson.o mylib.so
	gcc $(LFLAGS) -o mainJson mainJson.o -lcurl -ljansson

#mainGetFile : mylib.so mainGetFile.o
#	gcc -rdynamic -o mainGetFile mainGetFile.o -ldl -lcurl -ljansson

mainGetFile : mainGetFile.o mylib.so
	gcc $(LFLAGS) -o mainGetFile mainGetFile.o -lcurl -ljansson

http_get_json.o : http_get_json.c
	gcc $(CFLAGS) http_get_json.c -lcurl -ljansson
	
http_get_file.o : http_get_file.c
	gcc $(CFLAGS) http_get_file.c -lcurl -ljansson
	
mainJson.o : mainJson.c 
	gcc $(CFLAGS) mainJson.c -lcurl -ljansson
	
mainGetFile.o : mainGetFile.c
	gcc $(CFLAGS) mainGetFile.c -lcurl -ljansson
clean:
	rm mainJson mainJson.o mainGetFile mainGetFile.o
