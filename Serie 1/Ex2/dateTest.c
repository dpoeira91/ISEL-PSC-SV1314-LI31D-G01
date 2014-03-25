#include <stdio.h>

typedef unsigned short pkdate_t;

typedef struct date3 { unsigned year; unsigned month; unsigned day; } date3_t;

//variable declaration
pkdate_t date_pack;
date3_t src,dst;
int pack_ret, unpack_ret;

//method declaration
int pack_date(pkdate_t * dst, const date3_t * src);
int unpack_date(date3_t * dst, pkdate_t date);

void printResult();


int main(){
	//invalid month
	src.year = 2011;	
	src.month = 0;
	src.day = 20;
	printResult();

	//invalid day of February
	src.month = 2;
	src.day = 29;
	src.year = 2014;	

	//year <base
	src.year = 1909;
	src.month = 3;	
	printResult();

	//year >cap
	src.year = 2098;
	printResult();

	//valid date
	src.year = 2011;
	src.month = 2;
	src.day = 28;
	printResult();
	return 0;
}

void printResult(){
	printf("Year: %d , Month: %d , Day: %d\n", src.year, src.month, src.day);
	pack_ret = pack_date(&date_pack, &src);
	printf("Pack function return: %d , Packed date: %d\n", pack_ret, date_pack);
	unpack_ret = unpack_date(&dst, date_pack);
	printf("Unpack function return: %d , Year: %d , Month: %d , Day: %d\n \n",unpack_ret , dst.year, dst.month, dst.day);
	date_pack = 0; // necessario "reiniciar" para cada teste
}
