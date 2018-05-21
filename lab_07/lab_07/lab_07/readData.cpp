#include "readData.h"

double **allocateMatrix(int n, int m);

sData *getTable(char *fileName)
{
    std::ifstream fSrc(fileName);

    sData *table = (sData*) malloc(sizeof(sData));

    fSrc >> table->n;

    table->data = allocateMatrix(table->n, 9);

    for (int i = 0; i < table->n; i++)
        fSrc >> table->data[i][0] >> table->data[i][1];

    fSrc.close();

    return table;
}

double **allocateMatrix(int n, int m)
{
    double **data = (double**) malloc(n * sizeof(double*) + n * m * sizeof(double));

    if (!data)
        return NULL;

    for (int i = 0; i < n; i++)
        data[i] = (double*)((char*) data + n * sizeof(double*) + i * m * sizeof(double));

    return data;
}
