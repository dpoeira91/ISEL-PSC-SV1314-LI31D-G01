#include <stdio.h>

//defines
#define YEAR_BASE	1970
#define YEAR_CAP	2097

//enum & constants
enum months { JAN = 1, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC, FIRST = JAN, LAST = DEC, };

const int month_days[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31 ,30 ,31};

//structures
struct datebits {
	unsigned short year : 7;
	unsigned short month : 4;
	unsigned short day: 5;	
};

typedef unsigned short pkdate_t;

typedef struct date3 { unsigned year; unsigned month; unsigned day; } date3_t;

union upkdate {
	pkdate_t pd;
	struct datebits dbits;
};

//method declaration
int pack_date(pkdate_t * dst, const date3_t * src);
int unpack_date(date3_t * dst, pkdate_t date);


int main(){
	pkdate_t date_pack;
	date3_t src,dst;
	int pack_ret, unpack_ret;
	src.year = 2011;
	src.month = 2;
	src.day = 28;
	printf("Year: %d , Month: %d , Day: %d\n", src.year, src.month, src.day);
	pack_ret = pack_date(&date_pack, &src);
	printf("Pack function return: %d , Packed date: %d\n", pack_ret, date_pack);
	unpack_ret = unpack_date(&dst, date_pack);
	printf("Unpack function return: %d , Year: %d , Month: %d , Day: %d\n",unpack_ret , dst.year, dst.month, dst.day);
	return 0;
}

int pack_date(pkdate_t * dst, const date3_t * src){
	union upkdate ud;
	unsigned y, m, d,leap = 0;
	y = src -> year;
	m = src -> month;
	d = src -> day;
	if(y<YEAR_BASE || y>YEAR_CAP )
		return -1;
	if(m > LAST || m < FIRST)
		return -1;
	if (y % 4 == 0 && (y % 100 != 0 || y % 100 == 0 & y % 400 == 0))
		leap = 1;
	if ((d > month_days[m] && !(m==FEB && leap==1 && d <= month_days[m]+leap)))
		return -1;
	ud.dbits.year = y - YEAR_BASE;
	ud.dbits.month = m;
	ud.dbits.day = d;
	*dst = ud.pd;
	return 0;
}

int unpack_date(date3_t * dst, pkdate_t date){
	unsigned y, m, d, leap = 0;
	union upkdate ud;
	ud.pd = date;

	y = YEAR_BASE + ud.dbits.year;
	m = ud.dbits.month;
	d = ud.dbits.day;
	if (y > YEAR_CAP)
		return -1;
	if (m > LAST || m < FIRST)
		return -1;
	if(y % 4 == 0 && (y % 100 != 0 || y % 100 == 0 & y % 400 == 0))
		leap = 1;
	if ((d > month_days[m] && !(m == FEB && leap == 1 && d <= month_days[m] + leap)))
		return -1;
	dst -> year  = y;
	dst -> month = m;
	dst -> day   = d;
	return 0;
}
