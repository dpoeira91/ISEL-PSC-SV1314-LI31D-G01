#include <stdio.h>
#include <math.h>

#include "Point++.h"

unsigned Point::count=0;

Point :: Point(int x , int y){
	this->x = x;
	this->y = y;
	count +=1;
}
	
double Point::getMagnitude(){
	return sqrt(x*x + y*y);
}

void Point::translate(int dx , int dy){
	x += dx;
	y += dy;
}

void Point::printTo(FILE * stream){
	fprintf(stream, "{ x: %d ; y: %d }" , x, y);
}

unsigned Point::getCount(){
	return count;
}

Point3D::Point3D(int x, int y, int z) : Point(x,y){
	this.z = z;
}
	
double Point3D::getMagnitude(){
		return sqrt(x*x + y*y + z*z);
}
	
void Point3D::translate(int dx , int dy, int dz){
	Point::translate(dx,dy);
	this.z += dz;
}
	
void Point3D::printTo(FILE * stream){
	fprintf(stream, "{ x: %d ; y: %d ; z: %d }" , x, y,z);
}

int main (){
	
	Point vp(3,4);
	Point * rp = new Point(5,6);
	
	Point3D vp3(1,2,3);
	Point3D * rp3 = new Point3D(11,13,15);
	
	printf("sizeof vp3 =  %f \n" , sizeof (vp3));
	printf("sizeof rp3 =  %f \n" , sizeof (rp3);
	
	printf("vp.mangnitude =  %f \n" , vp.getMagnitude());
	printf("rp.mangnitude =  %f \n" , rp->getMagnitude());
	
	
	printf("vp3.mangnitude =  %f \n" , vp3.getMagnitude());
	printf("rp3.mangnitude =  %f \n" , rp3->getMagnitude());
	
	vp.translate(-2,1);
	rp->translate(5,10);
	
	vp3.translate(-2,1,4);
	rp3->translate(5,10,2);
	
	vp.printTo(stdout); putchar('\n');
	rp->printTo(stdout); putchar('\n');
	
	vp3.printTo(stdout); putchar('\n');
	rp3->printTo(stdout); putchar('\n');
	
	printf("Total Points = %u \n" , Point::getCount());
	
	delete rp;
	return 0;
}
