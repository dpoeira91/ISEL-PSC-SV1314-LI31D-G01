	#include <stddef.h>
	#include <stdbool.h>
	
	int find_in (int * values , size_t len, bool (*is_better)(int new, int old));
	
	bool is_min(int new, int old) {
		return *new < *old;
	}
	
	int find_min(int * values, size_t len ) {
		return find_in (values, len, is_min);
	}
	
	bool is_max(int new, int old) {return *new > *old;}
	
	int find_max(int * values, size_t len) {return find_in(values, len, is_max);}
	
