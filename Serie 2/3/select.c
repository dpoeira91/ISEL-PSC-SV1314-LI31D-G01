# include <stdio.h>

size_t select(void *items, size_t dim, size_t num, int (*check)(void *item, void *ctx), 
void *result[], void *ctx); 

size_t select(void *items, size_t dim, size_t num, int (*check)(void *item, void *ctx), 
void *result[], void *ctx){
size_t counter;
int check_result,i;
counter = 0;
for(i = 0;i<num;i++){
	check_result = (check)( ( items + (dim * i)),ctx);
	if(check_result!=0)
		result[counter++] = (items + (dim * i));
}
return counter;
}