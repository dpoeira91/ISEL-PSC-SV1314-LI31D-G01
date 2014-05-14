#ifndef POINTPP_H
#define POINTPP_H

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

class Point3D : public Point {
private:
	int z;
	void innerPrintTo(FILE * stream);
public:
	Point3D(int x, int y, int z);

	double getMagnitude();
	Point::translate; // unhide base class method
	void   translate(int dx, int dy, int dz);
};

#endif
