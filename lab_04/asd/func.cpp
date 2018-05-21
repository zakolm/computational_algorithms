#include "stdafx.h"
#include "func.h"

double pow_d(double num, int n)
{
    return n == 0 ? 1 : num * pow_d(num, n - 1);
}

double func(double x, int k)
{
    return pow_d(x, k);
    //return sin(x * (k + 5));
    //return cos(x * k);
}

int initTable(struct table_s *table)
{
    if (!table)
        return NULL_PTR;

    table->cn = 0;
    table->degree = 0;

    table->x = NULL;
    table->y = NULL;
    table->p = NULL;

    table->arg = NULL;

    return OK_;
}

int scanTable(struct table_s *table, FILE *f_src)
{
    if (!table || !f_src)
        return NULL_PTR;

    int cn = 0;

    if (fscanf(f_src, "%d", &cn) != 1)
        return INC_INP_DATA;

    int degree = 0;

    if (fscanf(f_src, "%d", &degree) != 1)
        return INC_INP_DATA;

    double *x = (double *) malloc(sizeof(double) * cn);

    if (!x)
        return MEMORY_ERR;

    double *y = (double *) malloc(sizeof(double) * cn);

    if (!y)
    {
        free(x);

        return MEMORY_ERR;
    }

    double *p = (double *) malloc(sizeof(double) * cn);

    if (!p)
    {
        free(x);
        free(y);

        return MEMORY_ERR;
    }

    for (int i = 0; i < cn; i++)
    {
        if (fscanf(f_src, "%lf %lf %lf", &x[i], &y[i], &p[i]) != 3)
        {
            free(x);
            free(y);
            free(p);

            return INC_INP_DATA;
        }
    }

    table->cn = cn;
    table->degree = degree;
    table->x = x;
    table->y = y;
    table->p = p;

    return OK_;
}

double **allocate_matrix(int n, int m)
{
    double **data = (double **) malloc(n * sizeof(double*) + n * m * sizeof(double));

    if (!data)
        return NULL;

    for (int i = 0; i < n; i++)
        data[i] = (double*)((char*) data + n * sizeof(double*) + i * m * sizeof(double));

    return data;
}

double first(double *p, double *x, int k, int m, int cn)
{
    double sum = 0;

    for (int i = 0; i < cn; i++)
        sum += p[i] * func(x[i], k) * func(x[i], m);

    return sum;
}

double second(double *p, double *y, double *x, int k, int cn)
{
    double sum = 0;

    for (int i = 0; i < cn; i++)
        sum += p[i] * y[i] * func(x[i], k);

    return sum;
}

double *gauss(double **matr, int n, int m)
{
    double *arg = (double *) malloc(sizeof(double) * n);

    if (!arg)
        return NULL;

    double koef;

    for (int i = 0; i < n; i++)
    {
        koef = matr[i][i];

        if (koef == 0)
            return NULL;

        for (int j = i; j < m; j++)
            matr[i][j] /= koef;

        for (int j = i + 1; j < n; j++)
        {
            koef = matr[j][i] / matr[i][i];

            for (int k = 0; k < m; k++)
                matr[j][k] -= matr[i][k] * koef;
        }
    }

    for (int i = n - 1; i > 0; i--)
    {
        for (int j = i - 1; j > -1; j--)
        {
            koef = matr[j][i] / matr[i][i];

            for (int k = 0; k < m; k++)
                matr[j][k] -= matr[i][k] * koef;
        }
    }

    for (int i = 0; i < n; i++)
    {
        arg[i] = matr[i][m - 1];
    }

    return arg;
}

struct table_s *get_table(char *filename, int degree)
{
    FILE *f_src = fopen(filename, "r");

    if (!f_src)
        return NULL;

    int rc = OK_;

    struct table_s *table = (struct table_s *) malloc(sizeof(struct table_s));

    if (!table)
        return NULL;

    if ((rc = initTable(table)) == OK_)
        if ((rc = scanTable(table, f_src)) == OK_)
        {
            table->degree = degree;

            int n = table->degree + 1;
            int m = table->degree + 2;

            double **matr = allocate_matrix(n, m);

            if (!matr)
            {
                return NULL;
            }

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    if (j != m - 1)
                    {
                        matr[i][j] = first(table->p, table->x, i, j, table->cn);
                    }
                    else
                    {
                        matr[i][j] = second(table->p, table->y, table->x, i, table->cn);
                    }
                }
            }

            table->arg = gauss(matr, n, m);
        }

        fclose(f_src);

        if (rc != OK_)
            return NULL;
        else
            return table;
}

void free_table(struct table_s *table)
{
    free(table->x);
    free(table->y);
    free(table->p);
    free(table->arg);
    free(table);
}

double get_p(struct table_s *table, double x_p)
{
    double y_p = 0;

    for (int i = 0; i < table->degree + 1; i++)
        y_p += table->arg[i] * pow_d(x_p, i);

    return y_p;
}
