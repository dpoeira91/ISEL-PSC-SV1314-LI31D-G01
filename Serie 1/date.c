#include <stdio.h>

typedef unsigned short pkdate_t;
typedef struct date3 { unsigned year; unsigned month; unsigned day; } date3_t;
int pack_date(pkdate_t * dst, const date3_t * src);
int unpack_date(date3_t * dst, pkdate_t date);

int main(){
	return 0;
}

int pack_date(pkdate_t * dst, const date3_t * src){
	if(src.year<1970 || src.year>2097)
		return -1;
	if(src.month>12 || src.month ==0)
		return -1;
	if(src.day>31 || src.day==0)
		return -1;
	dst = (src.year-1970)|(src.month<<7)|(src.day<<11);
	return 0;
}

int unpack_date(date3_t * dst, pkdate_t date){
	dst.year = 1970 + (date&0x7F);
	dst.month = date&0x780;
	dst.day = date&0xFC00;
}
