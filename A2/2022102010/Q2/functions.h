#ifndef _FUNCTIONS_H
#define _FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Head *Queue;
typedef struct Node *ptrNode;

struct Head
{
    int numOfElements;
    ptrNode front;
    ptrNode rear;
};

struct Node
{
    int val;
    ptrNode next;
};

Queue initiallizeQueue();

void Push(Queue head, int val);

int Pop(Queue head);

void Inject(Queue head, int val);

int popRear(Queue head);

void Print(Queue head);

void PrintNode(ptrNode front, Queue Q);

void PrintReverse(Queue head);

int findElem(Queue head, int pos);

void removeKElems(Queue head, int k);

#endif