#include <stdlib.h>

#define myassert(EXPR) ((EXPR) ? (void)(0) : myassert_func((#EXPR), __FILE__ , __LINE__ ))

