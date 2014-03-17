#include <stdio.h>

#define MONTH_POS 7;
#define DAY_POS 11;
#define YEAR_MASK 0x7F;
#define MONTH_MASK 0xF;
#define DAY_MASK 0x1F;
#define YEAR_BASE 1970;
#define YEAR_CAP 2097;

typedef unsigned short pkdate_t;
typedef struct date3 { unsigned year; unsigned month; unsigned day; } date3_t;
int pack_date(pkdate_t * dst, const date3_t * src);
int unpack_date(date3_t * dst, pkdate_t date);

int main(){
	return 0;
}

int pack_date(pkdate_t * dst, const date3_t * src){
	if(src.year<YEAR_BASE || src.year>YEAR_CAP)
		return -1;
	if(src.month>12 || src.month ==0)
		return -1;
	if(src.day>31 || src.day==0)
		return -1;
	dst = (src.year-YEAR_BASE)|(src.month<<MONTH_POS)|(src.day<<DAY_POS);
	return 0;
}

int unpack_date(date3_t * dst, pkdate_t date){
	dst.year = YEAR_BASE + (date&YEAR_MASK);
	dst.month = (date>>MONTH_POS)&MONTH_MASK;
	dst.day = (date>>DAY_POS)&DAY_MASK;
}
