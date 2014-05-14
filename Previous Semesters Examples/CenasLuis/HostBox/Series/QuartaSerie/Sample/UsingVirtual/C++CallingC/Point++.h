#ifndef POINTPP_H
#define POINTPP_H

#include <stdio.h>

class Point {
private:
	static unsigned count;
protected:
	int x;
	int y;
	virtual void innerPrintTo(FILE * stream);
public:
	Point(int x, int y);

	virtual double getMagnitude();
	
	void printTo(FILE * stream);
	void translate(int dx, int dy);
	
	static unsigned getCount();
};

/* create and return an instance of Point */

Point * createPoint(int x, int y);

#endif
