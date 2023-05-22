#ifndef __SORT_H
#define __SORT_H

#include <stdio.h>
#include <stdlib.h>

typedef char **stringList;

int isEven(int n);

int stringCompare(char *a, char *b);

stringList merge(stringList leftHalf, stringList rightHalf, int sizeL, int sizeR);

stringList mergeSort(stringList arr, int size);

void printString(char *a);


#endif