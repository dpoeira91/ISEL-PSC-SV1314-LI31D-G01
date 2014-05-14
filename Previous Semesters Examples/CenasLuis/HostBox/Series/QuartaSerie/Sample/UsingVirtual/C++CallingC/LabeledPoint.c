#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

#include "LabeledPoint.h"

void LabeledPoint_innerPrintTo(LabeledPoint * point, FILE * file) {
	fprintf(file, "x: %d; y: %d; label: \"%s\"",
	        point->x, point->y, point->label);
}

double LabeledPoint_getMagnitude(LabeledPoint * point) {
	return sqrt(point->x * point->x + point->y * point->y);
}

const LabeledPointInfo LabeledPoint_vtable = {
	LabeledPoint_innerPrintTo,
	LabeledPoint_getMagnitude
};

LabeledPoint * createLabeledPoint(int x, int y, const char * label) {
	LabeledPoint * point = (LabeledPoint *)malloc(sizeof(LabeledPoint));
	point->vptr = &LabeledPoint_vtable;
	point->x = x;
	point->y = y;
	point->label = strdup(label);
	return point;
}

