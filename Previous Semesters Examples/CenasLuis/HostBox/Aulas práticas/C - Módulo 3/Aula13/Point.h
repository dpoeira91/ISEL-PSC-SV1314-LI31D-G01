
typedef struct  Point {
	int x;
	int y;
} Point;

extern unsigned Point_count;

void Point_ctor(Point * this , int x , int y);
	
double Point_getMagnitude(Point * this);
	
void Point_translate(Point * this, int dx , int dy);
	
void Point_printTo(Point * this , FILE * stream);

unsigned Point_getCount();

typedef struct Point3D {
	Point super;
	int z;
} Point3D;

void Point3D_ctor(Point3D * this , int x , int y, int z);
	
double Point3D_getMagnitude(Point3D * this);
	
void Point3D_translate(Point3D * this, int dx , int dy , int dz);
	
void Point3D_printTo(Point3D * this , FILE * stream);
