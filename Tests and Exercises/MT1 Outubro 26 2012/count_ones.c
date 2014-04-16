#include<stdio.h>

int count_ones(short v);

int main(){
	printf("%d\n", count_ones(0xFF75));
	printf("%d\n", count_ones(0x0085));
}

int count_ones(short v) {
	char c = (char)v;
	int i = c, cnt = 0;
	while (i != 0) {
		if (i & 1) cnt++;
		i = (unsigned int)i >> 1;
	}
	return cnt;
}