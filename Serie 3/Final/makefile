CFLAGS = -c -m32 -Wall -std=c99 -pedantic
LFLAGS = -g -m32

#all: myHttpLib.so saveThothWork

#myHttpLib.so : http_get_json.o http_get_file.o json_resource_finder.o
#	gcc $(LFLAGS) -o myHttpLib.so -shared http_get_json.o http_get_file.o json_resource_finder.o

#saveThothWork : myHttpLib.so save_thoth_work.o
#	gcc $(CFLAGS) -rdynamic -o save_thoth_work save_thoth_work.o myHttpLib.so -ldl -lcurl -ljansson

#clean : 
#	rm ./http_get_file.o ./http_get_json.o ./save_thoth_work.o ./myHttpLib.so ./json_resource_finder.o

save_thoth_work: save_thoth_work.o http_get_file.o http_get_json.o json_resource_finder.o
	gcc $(LFLAGS) -o save_thoth_work save_thoth_work.o http_get_file.o http_get_json.o json_resource_finder.o

save_thoth_work.o : save_thoth_work.c
	gcc $(CFLAGS) -o save_thoth_work.o save_thoth_work.c

http_get_file.o : http_get_file.c
	gcc $(CFLAGS) -o http_get_file.o http_get_file.c -lcurl

http_get_json.o : http_get_json.c
	gcc $(CFLAGS) -o http_get_json.o http_get_json.c -lcurl -ljansson

json_resource_finder.o : json_resource_finder.c
	gcc $(CFLAGS) -o json_resource_finder.o json_resource_finder.c -lcurl -ljansson