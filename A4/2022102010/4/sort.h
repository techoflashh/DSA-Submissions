#ifndef __SORT_H
#define __SORT_H

#include <stdio.h>
#include <stdlib.h>

int *merge(int *leftHalf, int *rightHalf, int sizeL, int sizeR);

int *mergeSort(int *arr, int size);

int maxNoOfWins(int *arr, int m, int k, int j);

#endif