#ifndef __HEAP_H
#define __HEAP_H

#include <stdio.h>
#include <stdlib.h>

typedef struct HeapStruct *Heap;

struct HeapStruct
{
    int capacity;
    int size;
    int *Elements;
};

Heap initiallizeHeap(int capacity);

void Insert(Heap H, int e);

int DeleteHead(Heap H);

void DeleteHeap(Heap H);

int calculateMaxNoOfNobs(int *arr, int len);

#endif