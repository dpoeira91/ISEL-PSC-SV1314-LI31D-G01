CFLAGS = -c -m32 -g -O1 -Wall -std=c99 -pedantic

all: myHttpLib.so mJson mFile

myHttpLib.so : http_get_json.o http_get_file.o
	gcc -o myHttpLib.so -shared http_get_json.o http_get_file.o

mJson : myHttpLib.so json_test.o
	gcc -rdynamic -o mJson json_test.o myHttpLib.so -ldl -lcurl -ljansson

mFile : myHttpLib.so file_test.o
	gcc -rdynamic -o mFile file_test.o myHttpLib.so -ldl -lcurl -ljansson

clean : 
	rm mJson json_test.o mFile file_test.o
