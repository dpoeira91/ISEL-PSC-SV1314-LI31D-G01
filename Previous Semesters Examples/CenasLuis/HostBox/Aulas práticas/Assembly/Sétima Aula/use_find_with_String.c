	#include <stddef.h>
	#include <stdbool.h>
	#include <stdstr.h>
	
	void * find_in( void * values, size_t num_elems, size_t elem_size, bool (*is_better)(void * new, void * old))){
	
	bool is_first (const char * new , const char * old) {return strcmp(*new,*old)<0;}
	
	const char * find_first_string( const char * *values, size_t len) {
		return *find_in(values, len, is_max);
	}
	
