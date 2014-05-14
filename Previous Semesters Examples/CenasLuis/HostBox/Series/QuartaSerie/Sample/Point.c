#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "Point.h"

unsigned Point_count = 0;

void Point_ctor(Point *this, int x, int y) {
	this->x = x;
	this->y = y;
	Point_count += 1;
}

double Point_getMagnitude(Point *this) {
	return sqrt(this->x * this->x + this->y * this->y);
}

void Point_translate(Point *this, int dx, int dy) {
	this->x += dx;
	this->y += dy;
}

void Point_printTo(Point *this, FILE * stream) {
	fprintf(stream, "{ x: %d; y: %d }", this->x, this->y);
}

unsigned Point_getCount() {
	return Point_count;
}

void Point3D_ctor(Point3D *this, int x, int y, int z) {
	Point_ctor(&this->super, x, y);
	this->z = z;
}

double Point3D_getMagnitude(Point3D *this) {
	return sqrt(this->super.x * this->super.x +
	            this->super.y * this->super.y +
	            this->z * this->z);
}

void Point3D_translate(Point3D *this, int dx, int dy, int dz) {
	Point_translate(&this->super, dx, dy);
	this->z += dz;
}

void Point3D_printTo(Point3D *this, FILE * stream) {
	fprintf(stream, "{ x: %d; y: %d; z: %d }",
	        this->super.x, this->super.y, this->z);
}

int main()
{
	
	Point  vp;
	Point *rp = (Point *)malloc(sizeof(Point));
	
	Point3D  vp3;
	Point3D *rp3 = (Point3D *)malloc(sizeof(Point3D));
	
	Point *pp  = rp;
	Point *pp3 = (Point *)rp3;
	
	Point_ctor(&vp, 3, 4);
	Point_ctor(rp, 5, 6);

	Point3D_ctor(&vp3, 1, 2, 3);
	Point3D_ctor(rp3, 11, 13, 15);
	
	printf("sizeof(vp)  = %lu\n", sizeof(vp));
	printf("sizeof(vp3) = %lu\n", sizeof(vp3));
	
	printf("vp.magnitude = %f\n", Point_getMagnitude(&vp));
	printf("rp.magnitude = %f\n", Point_getMagnitude(rp));
	
	printf("vp3.magnitude = %f\n", Point3D_getMagnitude(&vp3));
	printf("rp3.magnitude = %f\n", Point3D_getMagnitude(rp3));
	
	Point_translate(&vp, -2, 1);
	Point_translate(rp, 5, 10);
	
	printf("vp: "); Point_printTo(&vp, stdout); putchar('\n');
	printf("rp: "); Point_printTo(rp, stdout); putchar('\n');
	
	Point_translate(&vp3.super, -4, 7);	
	Point3D_translate(&vp3, -3, 11, 2);
	Point3D_translate(rp3, 5, 10, -5);
		
	printf("vp3: "); Point3D_printTo(&vp3, stdout); putchar('\n');
	printf("rp3: "); Point3D_printTo(rp3, stdout); putchar('\n');
	
	printf("pp: "); Point_printTo(pp, stdout); putchar('\n');
	printf("pp3: "); Point_printTo(pp3, stdout); putchar('\n');
	
	printf("Total Points = %u\n", Point_getCount());

	free(rp3);
	free(rp);
	
	return 0;
}

