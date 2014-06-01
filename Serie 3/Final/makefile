CFLAGS = -c -m32 -g -O1 -Wall -std=c99 -pedantic
LFLAGS = -g -m32

all: libWork.so save_thoth_work

libWork.so :  http_get_file.o http_get_json.o html_representation.o json_resource_finder.o workitem_to_html.o
	gcc -shared -o libWork.so http_get_file.o http_get_json.o html_representation.o json_resource_finder.o workitem_to_html.o -lcurl -ljansson -ldl

#libWork.o : http_get_file.c http_get_json.c html_representation.c json_resource_finder.c workitem_to_html.c
#	gcc $(CFLAGS) -fPIC -o libWork.o http_get_file.c http_get_json.c html_representation.c json_resource_finder.c workitem_to_html.c

http_get_file.o : http_get_file.c
	gcc $(CFLAGS) http_get_file.c
	
http_get_json.o : http_get_json.c
	gcc $(CFLAGS) http_get_json.c
	
html_representation.o : html_representation.c
	gcc $(CFLAGS) html_representation.c
	
json_resource_finder.o : json_resource_finder.c
	gcc $(CFLAGS) json_resource_finder.c
	
workitem_to_html.o : workitem_to_html.c
	gcc $(CFLAGS) workitem_to_html.c
	
	
save_thoth_work : save_thoth_work.o libWork.so
	gcc $(LFLAGS) -o save_thoth_work save_thoth_work.o ./libWork.so
	
clean:
	rm ./libWork.so save_thoth_work save_thoth_work.o http_get_file.o http_get_json.o html_representation.o json_resource_finder.o workitem_to_html.o  -rf Thoth
