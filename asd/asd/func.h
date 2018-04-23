#ifndef FUNC_H
#define FUNC_H

#define _USE_MATH_DEFINES

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define OK_ 0
#define FILE_ERR -1
#define NULL_PTR -2
#define INC_INP_DATA -3
#define MEMORY_ERR -4

struct table_s
{
    int cn;
    int degree;
    
    double *x;
    double *y;
    double *p;

    double *arg;
};

struct table_s *get_table(char *filename, int degree);
void free_table(struct table_s *table);
double get_p(struct table_s *table, double x_p);

#endif // FUNC_H