#include<stdio.h>


void * convertAll(const void * input, size_t idim, size_t len,
	void * output, size_t odim,
	void(*convertOne)(const void * in, void * out, void * ctx),
	void * ctx);

void * convertAll(const void * input, size_t idim, size_t len,
	void * output, size_t odim,
	void(*convertOne)(const void * in, void * out, void * ctx),
	void * ctx){
	size_t i;
	for (i = 0; i < len; i++){
		(convertOne)((input + (idim * i)), (output + (odim * i)), ctx);
	}
	return (output + (odim * i);
}