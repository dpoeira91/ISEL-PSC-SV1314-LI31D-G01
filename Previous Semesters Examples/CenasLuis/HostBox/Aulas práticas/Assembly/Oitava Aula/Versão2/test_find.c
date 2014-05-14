	#include <stddef.h>
	#include <stdbool.h>
	
	void * find_in (void * values , size_t nelems, size_t esize,  void * (eval)(void * val, void * ctx), void * ctx);
	
	struct eval_shorter_context {
		char * * pshorter;
		size_t shorter_len;
	};
	
	void *eval_shorter (void * val, void * ctx){
		char * pstr = *(char**) val;
		struct eval_shorter_context * context =  (struct eval_shorter_context * ) ctx;
		
		size_t val_len = strlen(*pstr);
		if (val_len < context -> shorter_len) {
			context -> pshorter = pstr;
			context -> shorter_len = val_len;
		}
		return context -> pshorter;
	}
		 
	
	char * find_shorter_string (char * strs [] , size_t len) {
		struct eval_shorter_context context = { .shorter_len = UINT_MAX };
		return * (char **) find_in(strs, len, sizeof strs[0] , eval_shorter, context);
	}
	
	int main(int argc , char * argv[]){	
		char * shorter;
		shorter = find_shorter_string(argv +1 , argc -1);
		puts(shorter);
		return 0;
	}
	
