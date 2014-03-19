#include <stdio.h>

const int month_pos = 7;
const int day_pos = 11;
const int year_base = 1970;
const int year_cap = 2097;
const int year_mask = 0x7F;
const int month_mask = 0xF;
const int day_mask = 0x1F;
enum months { jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec };


typedef unsigned short pkdate_t;
typedef struct date3 { unsigned year; unsigned month; unsigned day; } date3_t;
int pack_date(pkdate_t * dst, const date3_t * src);
int unpack_date(date3_t * dst, pkdate_t date);

int main(){
	pkdate_t *dateptr, date_pack;
	date3_t *srcptr, *dstptr, src,dst;
	int pack_ret, unpack_ret;
	src.year = 2014;
	src.month = 3;
	src.day = 18;
	dateptr = &date_pack;
	srcptr = &src;
	dstptr = &dst;
	printf("Year: %d , Month: %d , Day: %d\n", src.year, src.month, src.day);
	pack_ret = pack_date(dateptr, srcptr);
	printf("Pack function return: %d , Packed date: %d\n", pack_ret, *dateptr);
	unpack_ret = unpack_date(dstptr, *dateptr);
	printf("Unpack function return: %d , Year: %d , Month: %d , Day: %d\n",unpack_ret , dst.year, dst.month, dst.day);
	return 0;
}

int pack_date(pkdate_t * dst, const date3_t * src){
	unsigned y, m, d;
	y = src -> year;
	m = src -> month;
	d = src -> day;
	if(y<year_base || y>year_cap)
		return -1;
	if(m>12 || m ==0)
		return -1;
	if (m == feb){
		if (d>28 || d == 0)
			return -1;
	}
	else{
		if (m == jan || m == mar || m == may || m == jul || m == aug || m == oct || m == dec){
			if (d > 31 || d == 0)
				return -1;
		}
		else {
			if (d > 30 || d == 0)
				return -1;
		}
	}
	*dst = (y-year_base)|(m<<month_pos)|(d<<day_pos);
	return 0;
}

int unpack_date(date3_t * dst, pkdate_t date){
	unsigned y, m, d;
	y = year_base + (date & year_mask);
	m = (date >> month_pos) & month_mask;
	d = (date >> day_pos) & day_mask;
	if (y > year_cap)
		return -1;
	if (m > 12 || m == 0)
		return -1;
	if (m == feb){
		if (d>28 || d == 0)
			return -1;
	}
	else{
		if (m == jan || m == mar || m == may || m == jul || m == aug || m == oct || m == dec){
			if (d > 31 || d == 0)
				return -1;
		}
		else {
			if (d > 30 || d == 0)
				return -1;
		}
	}
	dst -> year  = y;
	dst -> month = m;
	dst -> day   = d;
	return 0;
}
