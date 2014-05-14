#include <stdio.h>
#include "Point++.h"

void printAllPoints( Point * points [] , size_t len ){
	size_t i;
	for (i = 0 ; i < len ; ++i ){
		points[i] -> printTo(stdout);
		putchar('\n');
	}
}

Point * createPoint(int x , int y );

Point * createPoint3D(int x , int y , int z );

Point *  createLabeledPoint(int x, int y, const char * label );

int main(){
	Point * points [6] = {
		createPoint(3, 4),
		createPoint3D(5, 6, 7),
		createPoint(8, 9),
		createLabeledPoint(10, 11, "I'm a labeled point!"),
		createPoint3D(12,13, 14),
		createLabeledPoint(15, 16, "Pretty programer :D")
		};
	printAllPoints(points, 6);
}
