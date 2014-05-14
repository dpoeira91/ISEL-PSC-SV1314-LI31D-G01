#include <stdio.h>
#include <math.h>

#include "Point++.h"

unsigned Point::count = 0;

Point::Point(int x, int y) {
	this->x = x;
	this->y = y;
	count += 1;
}

double Point::getMagnitude() {
	return sqrt(x*x + y*y);
}

void Point::translate(int dx, int dy) {
	x += dx;
	y += dy;
}

void Point::innerPrintTo(FILE * stream) {
	fprintf(stream, "x: %d; y: %d", x, y);
}

void Point::printTo(FILE * stream) {
	fprintf(stream, "{ ");
	innerPrintTo(stream);
	fprintf(stream, " }");
}

unsigned Point::getCount() {
	return count;
}

Point * createPoint(int x, int y) {
	return new Point(x, y);
}

