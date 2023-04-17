#ifndef _FUNCTIONS_H
#define _FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Node *ptrNode;
typedef struct head *Stack;

struct head
{
    int noOfElements;
    ptrNode Top;
};

struct Node
{
    char val;
    ptrNode Next;
};

int stringLength(char *str);

int returnFlag();

Stack init();

int isEmpty(Stack S);

void push(Stack S, char e);

char pop(Stack S);

int isBalanced(char *A, int lenth);

int isPalindromic(char *A, int length);

#endif