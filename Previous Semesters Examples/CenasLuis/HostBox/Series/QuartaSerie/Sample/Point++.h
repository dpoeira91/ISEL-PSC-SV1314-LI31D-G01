#ifndef POINTPP_H
#define POINTPP_H

class Point {
private:
	static unsigned count;
protected:
	int x;
	int y;
public:
	Point(int x, int y);

	double getMagnitude();
	void   translate(int dx, int dy);
	void   printTo(FILE * stream);
	
	static unsigned getCount();
};

class Point3D : public Point {
private:
	int z;
public:
	Point3D(int x, int y, int z);

	double getMagnitude();
	using Point::translate;	// unhide base class method
	void   translate(int dx, int dy, int dz);
	void   printTo(FILE * stream);
};

#endif
