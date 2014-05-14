#ifndef POINT3D_H
#define POINT3D_H

#include "Point++.h"

class Point3D : public Point {
private:
	int z;
	void innerPrintTo(FILE * stream);
public:
	Point3D(int x, int y, int z);

	double getMagnitude();
	using Point::translate; // unhide base class method
	void   translate(int dx, int dy, int dz);
};

/* Create and return an instance of Point#D as a Point */

Point *createPoint3D(int x, int y, int z);

#endif
