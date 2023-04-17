#include<stdio.h>
#include<stdlib.h>

typedef struct Node * PtrNode;

struct Node
{
    int Element;
    PtrNode NextNode;
};

PtrNode InitializeLinkedList();

void Insert(PtrNode Head, int num);

PtrNode Find( PtrNode Head, int num );

void Print( PtrNode Head);
