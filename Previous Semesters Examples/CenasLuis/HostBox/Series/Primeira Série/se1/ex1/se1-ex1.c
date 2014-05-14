#include <stdbool.h>
#include <stddef.h>
#include <limits.h>

unsigned long long max_value(bool sign, size_t nbytes) {
	if (nbytes> sizeof(unsigned long))
		return 0;
	if (sign)
		return (1<<((nbytes*CHAR_BIT)-1))-1;
	else
		return (1<<(nbytes*CHAR_BIT))-1;
}
