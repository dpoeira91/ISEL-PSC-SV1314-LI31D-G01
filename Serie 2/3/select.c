# include <stdio.h>

struct size_t {long long int value};

size_t select(void *items, size_t dim, size_t num, int (*check)(void *item, void *ctx), 
void *result[], void *ctx); 
int check(void *item, void *ctx);

size_t select(void *items, size_t dim, size_t num, int (*check)(void *item, void *ctx), 
void *result[], void *ctx){
size_t counter, size_t i;
int addr;
counter.value = 0;
for(i.value = 0;i<num.value;i.value++){
	addr = check( *(items + (dim.value*i.value)),ctx);
	if(addr!=0)
		result[counter.value++] = (items + i.value);
}
return counter;
}