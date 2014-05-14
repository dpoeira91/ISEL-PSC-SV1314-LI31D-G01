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
	return sqrt(x * x + y * y);
}

void Point::translate(int dx, int dy) {
	x += dx;
	y += dy;
}

void Point::printTo(FILE *stream) {
	fprintf(stream, "{ x: %d; y: %d }", x, y);
}

unsigned Point::getCount() {
	return count;
}

/* Point3D */

Point3D::Point3D(int x, int y, int z) : Point(x, y) {
	this->z = z;
}

double Point3D::getMagnitude() {
	return sqrt(x * x + y * y + z * z);
}

void Point3D::translate(int dx, int dy, int dz) {
	Point::translate(dx, dy);
	z += dz;
}

void Point3D::printTo(FILE *stream) {
	fprintf(stream, "{ x: %d; y: %d; z: %d }", x, y, z);
}

int main()
{

	Point vp(3, 4);
	Point *rp = new Point(5, 6);

	Point3D vp3(1, 2, 3);
	Point3D *rp3 = new Point3D(11, 13, 15);


	printf("sizeof(vp): %lu\n", sizeof(vp));
	printf("sizeof(vp3): %lu\n", sizeof(vp3));






















	return 0;

}
/*

	
	Point *pp  = rp;
	Point *pp3 = rp3;
	
	printf("sizeof(vp)  = %lu\n", sizeof(vp));
	printf("sizeof(vp3) = %lu\n", sizeof(vp3));
	
	printf("vp.magnitude = %f\n", vp.getMagnitude());
	printf("rp.magnitude = %f\n", rp->getMagnitude());
	
	printf("vp3.magnitude = %f\n", vp3.getMagnitude());
	printf("rp3.magnitude = %f\n", rp3->getMagnitude());
	
	vp.translate(-2, 1);
	rp->translate(5, 10);
	printf("vp: "); vp.printTo(stdout); putchar('\n');
	printf("rp: "); rp->printTo(stdout); putchar('\n');
	
	vp3.translate(-4, 7);		// uses Point::translate()
	vp3.translate(-3, 11, 2);
	rp3->translate(5, 10, -5);
		
	printf("vp3: "); vp3.printTo(stdout); putchar('\n');
	printf("rp3: "); rp3->printTo(stdout); putchar('\n');
	
	printf("pp: "); pp->printTo(stdout); putchar('\n');
	printf("pp3: "); pp3->printTo(stdout); putchar('\n');
	
	printf("Total Points = %u\n", Point::getCount());

	delete rp3;
	delete rp;
	
	return 0;
}
*/
