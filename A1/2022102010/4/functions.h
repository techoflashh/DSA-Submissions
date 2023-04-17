#include <stdio.h>
#include <stdlib.h>

typedef struct Node *PtrNode;

typedef struct Matrix *sMatrix;

typedef struct structForAdd *PtrNode2;

struct Node
{
    int val;
    int col;
    PtrNode NextNode;
    PtrNode PrevNode;
};

struct Matrix
{
    int row;
    PtrNode HeadofRow;
    sMatrix Next;
    sMatrix Prev;
};

struct structForAdd
{
    int row;
    int col;
    int val;
    PtrNode2 Next;
    PtrNode2 Prev;
};

PtrNode initializeLinkedList();

sMatrix initializeMatrix();

PtrNode2 initializeAddLL();

void InsertElementInRow(PtrNode Head, int col, int val);

void insertElementsForTRA(PtrNode2 Head,int row,int col,int val);

void insertElementsForADD(PtrNode2 Head,int row,int col,int val);

void InsertRow(sMatrix Head, int row, PtrNode rowHead);

PtrNode2 splitInTwo(PtrNode2 listHead);

PtrNode2 mergeTwoHalves(PtrNode2 firstHalf, PtrNode2 secondHalf);

PtrNode2 mergeSort(PtrNode2 listHead);

sMatrix findRow(sMatrix S, int row);

void PrintADD(PtrNode2 Head);

void PrintMatrix(sMatrix Head);

sMatrix TRA(PtrNode2 listHead);

PtrNode2 ADD(PtrNode2 S1, PtrNode2 S2);

sMatrix MUL(sMatrix S1, PtrNode2 S);

int lenLL();