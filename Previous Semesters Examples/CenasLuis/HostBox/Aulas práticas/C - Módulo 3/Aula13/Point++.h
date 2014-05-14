class Point {
protected:
	int x;
	int y;
	static unsigned count;
public:
	Point(int x , int y);
	
	double getMagnitude();
	
	void translate(int dx , int dy);
	
	void printTo(FILE * stream);
	
	static unsigned getCount();
};

class Point3D : public Point {
private:
	int z;
public:
	Point3D(int x, int y, int z);
	
	double getMagnitude();
	
	void translate(int dx , int dy, int dz);
	
	void printTo(FILE * stream);
};
