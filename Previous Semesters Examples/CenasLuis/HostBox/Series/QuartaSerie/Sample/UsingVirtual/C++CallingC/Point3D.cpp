#include "Point3D.h"

#include <math.h>

Point3D::Point3D(int x, int y, int z) : Point(x, y) {
	this->z = z;
}

double Point3D::getMagnitude() {
	return sqrt(x*x + y*y + z*z);
}

void Point3D::translate(int dx, int dy, int dz) {
	Point::translate(dx, dy);
	z += dz;
}

void Point3D::innerPrintTo(FILE * stream) {
	Point::innerPrintTo(stream);
	fprintf(stream, "; z: %d", z);
}

Point * createPoint3D(int x, int y, int z) {
	return new Point3D(x, y, z);
}
