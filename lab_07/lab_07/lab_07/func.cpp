#include "func.h"

double f(double x, double *a)
{
    return a[0] * x / (a[1] + a[2] * x);
}

void fillTable(sData *table)
{
    double h = getH(table->data[0][0], table->data[1][0]);

    for (int i = 0; i < table->n; i++)
    {
        if (i == 0)
            table->data[i][2] = getNAN(0);
        else
            table->data[i][2] = getFirst(table->data[i][1], table->data[i - 1][1], h);

        if (i == table->n - 1)
            table->data[i][3] = getNAN(0);
        else
            table->data[i][3] = getFirst(table->data[i + 1][1], table->data[i][1], h);

        if ((i == 0) || (i == table->n - 1))
            table->data[i][4] = getNAN(0);
        else
            table->data[i][4] = getFirst(table->data[i + 1][1], table->data[i - 1][1], 2 * h);

        if (i == 0)
            table->data[i][5] = getLeftUp(table->data[i][1], table->data[i + 1][1], table->data[i + 2][1], h);
        else if (i == table->n - 1)
            table->data[i][5] = getRightUp(table->data[i][1], table->data[i - 1][1], table->data[i - 2][1], h);
        else
            table->data[i][5] = getNAN(0);

        if (i < 2)
            table->data[i][6] = getNAN(0);
        else
            table->data[i][6] = getRungeLeft(table->data[i][1], table->data[i - 1][1], table->data[i - 2][1], h);

        if (i > table->n - 3)
            table->data[i][7] = getNAN(0);
        else
            table->data[i][7] = getRungeRight(table->data[i][1], table->data[i + 1][1], table->data[i + 2][1], h);

        if (i == table->n - 1)
            table->data[i][8] = -getAlignment(table->data[i][0], table->data[i][1], table->data[i - 1][0], table->data[i - 1][1]);
        else
            table->data[i][8] = getAlignment(table->data[i][0], table->data[i][1], table->data[i + 1][0], table->data[i + 1][1]);
    }
}

double getH(double x1, double x2)
{
    return fabs(x1 - x2);
}

double getFirst(double left, double right, double h)
{
    return (left - right) / h;
}

double getLeftUp(double left, double mid, double right, double h)
{
    return (-3 * left + 4 * mid - right) / (2 * h);
}

double getRightUp(double left, double mid, double right, double h)
{
    return (3 * left - 4 * mid + right) / (2 * h);
}

double getRungeLeft(double cur, double left, double secondLeft, double h)
{
    double r = 2;

    double temp1 = getFirst(cur, left, h);
    double temp2 = getFirst(cur, secondLeft, r * h);

    return temp1 + (temp1 - temp2) / (r - 1);
}

double getRungeRight(double cur, double right, double secondRight, double h)
{
    double r = 2;

    double temp1 = getFirst(right, cur, h);
    double temp2 = getFirst(secondRight, cur, r * h);

    return temp1 + (temp1 - temp2);
}

double diffFunc(double x)
{
    // ln(x);
    return 1 / x;
}

double getAlignment(double x, double y, double rightX, double rightY)
{
    return -((y*y) / (x*x)) * getFirst(diffFunc(rightY), diffFunc(y), getH(diffFunc(x), diffFunc(rightX)));
}

double getNAN(double x)
{
    double y = log(0.0);
    return y * x;
}
