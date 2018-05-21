#ifndef FUNC_H
#define FUNC_H

#define _USE_MATH_DEFINES

#include <stdlib.h>
#include <math.h>
#include "structs.h"

void fillTable(sData *table);

double f(double x, double *a);

double getH(double x1, double x2);
double getFirst(double left, double right, double h);
double getLeftUp(double left, double mid, double right, double h);
double getRightUp(double left, double mid, double right, double h);
double getRungeLeft(double cur, double left, double secondLeft, double h);
double getRungeRight(double cur, double right, double secondRight, double h);
double getAlignment(double x, double y, double rightX, double rightY);
double getNAN(double x);

#endif // FUNC_H
