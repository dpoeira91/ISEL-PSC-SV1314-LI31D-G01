#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "Point.h"

unsigned Point_count =0;

void Point_ctor(Point * this , int x , int y){
	this->x = x;
	this->y = y;
	Point_count +=1;
}
	
double Point_getMagnitude(Point * this){
	return sqrt(this->x * this->x + this->y * this->y);
}
	
void Point_translate(Point * this, int dx , int dy){
	this->x += dx;
	this->y += dy;
}
	
void Point_printTo(Point * this , FILE * stream){
	fprintf(stream, "{ x: %d ; y: %d }" , this->x, this->y);
}

unsigned Point_getCount(){
	return Point_count;
}

void Point3D_ctor(Point3D * this , int x , int y, int z){
	Point_ctor(&this->super, x, y );
	this->z = z;
}
	
double Point3D_getMagnitude(Point3D * this){
	return sqrt(this->super.x * this->super.x +
					this->super.y * this->super.y +
					this->z * this->z);
}
	
void Point3D_translate(Point3D * this, int dx , int dy , int dz){
		Point_translate(&this->super, dx, dy);
		this->z +=dz;
}
	
void Point3D_printTo(Point3D * this , FILE * stream){
	fprintf(stream, "{ x : %d ; y : %d ; z : %d }" , this->super.x, this->super.y, this->super.z);
}


int main (){
	
	Point vp;
	Point * rp = (Point *)malloc(sizeof(Point));
	
	Point_ctor(&vp, 3 , 4);
	Point_ctor(rp, 5, 6);
	
	printf("vp.magnitude = %f\n" , Point_getMagnitude(&vp));
	printf("rp.mangnitude =  %f \n" , Point_getMagnitude(rp));
	
	Point_translate(&vp,-2,1);
	Point_translate(rp,5,10);
	
	Point_printTo(&vp,stdout); putchar('\n');
	Point_printTo(rp,stdout); putchar('\n');
	
	printf("Total Points = %u \n" , Point_getCount());

	
	free (rp);
	return 0;
}
