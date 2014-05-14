#ifndef LABELEDPOINT_H
#define LABELEDPOINT_H

typedef struct LabeledPoint LabeledPoint;

typedef struct LabeledPointInfo {
	void   (*innerPrintTo)(LabeledPoint * point, FILE * file);
	double (*getMagnitude)(LabeledPoint * point);
} LabeledPointInfo;

struct LabeledPoint {
	const LabeledPointInfo * vptr;
	const char * label;
	int x;
	int y;
};

#endif


