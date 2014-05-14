#include <stdio.h>

// Escreva aqui as duas chaves para sua bomba.
const char * const KEYS[] = {
	"Locus medius tutus est.",
	"2 38 38 38 38 6",
};

int main() {
	for (int i = 0; i < sizeof KEYS / sizeof KEYS[0]; ++i)
		puts(KEYS[i]);
	return 0;
}
