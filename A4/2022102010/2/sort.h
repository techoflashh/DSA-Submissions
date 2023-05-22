#ifndef __SORT_H
#define __SORT_H

#include <stdio.h>
#include <stdlib.h>

typedef struct pair *pairPtr;

struct pair
{
    int a;
    int b;
};

pairPtr merge(pairPtr leftHalf, pairPtr rightHalf, int sizeL, int sizeR);

pairPtr mergeSort(pairPtr arr, int size);

void magicMarbles(pairPtr pairArray, int size);


#endif