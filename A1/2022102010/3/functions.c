#include "functions.h"

PtrNode InitializeLinkedList()
{
    PtrNode L = (PtrNode)malloc(sizeof(struct Node));
    L->NextNode = L;
    return L;
}

PtrNode createNode()
{
    return (PtrNode)malloc(sizeof(struct Node));
}

void Insert(PtrNode Head, int num)
{
    PtrNode p = createNode();
    p->Element = num;
    p->NextNode = Head->NextNode;
    Head->NextNode = p;
}

PtrNode Find(PtrNode Head, int num)
{
    PtrNode HeadCopy = Head;
    HeadCopy =  HeadCopy->NextNode;
    PtrNode temp = Head;
    while (HeadCopy->Element != num)
    {
        HeadCopy = HeadCopy->NextNode;
        temp = temp->NextNode;
        if (HeadCopy == Head)
        {
            return NULL;
        }
        
    }
    PtrNode p = HeadCopy;
    temp->NextNode = p->NextNode;
    HeadCopy->NextNode = Head->NextNode;
    Head->NextNode = p;
    return p;
}


void Print(PtrNode Head)
{
    PtrNode HeadCopy = Head;
    while (HeadCopy->NextNode != Head)
    {
        HeadCopy = HeadCopy->NextNode;
        printf("%d ", HeadCopy->Element);
    }
    printf("\n");
}
