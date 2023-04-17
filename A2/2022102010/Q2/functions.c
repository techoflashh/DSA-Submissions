#include "functions.h"

Queue initiallizeQueue()
{
    Queue Q = (Queue)malloc(sizeof(struct Head));
    Q->numOfElements = 0;
    Q->rear = NULL;
    Q->front = NULL;
    return Q;
}

void Push(Queue head, int val)
{
    ptrNode nodeToInsert = (ptrNode)malloc(sizeof(struct Node));
    nodeToInsert->val = val;
    if (head->numOfElements == 0)
    {
        head->front = nodeToInsert;
        head->rear = nodeToInsert;
        head->front->next = head->rear;
        head->rear->next = head->front;
    }
    else
    {
        nodeToInsert->next = head->front;
        head->rear->next = nodeToInsert;
        head->rear = nodeToInsert;
    }
    head->numOfElements++;
}

int Pop(Queue head)
{
    int returnValue;
    if (head->numOfElements == 0)
    {
        returnValue = -1;
    }
    else if (head->numOfElements > 1)
    {
        ptrNode nodeToPop = head->front;
        head->rear->next = head->front->next;
        head->front = nodeToPop->next;
        returnValue = nodeToPop->val;
        head->numOfElements--;
        free(nodeToPop);
    }
    else
    {
        returnValue = head->front->val;
        free(head->front);
        head->front = NULL;
        head->rear = NULL;
        head->numOfElements--;
    }
    return returnValue;
}

void Inject(Queue head, int val)
{
    ptrNode nodeToInject = (ptrNode)malloc(sizeof(struct Node));
    nodeToInject->val = val;
    if (head->numOfElements == 0)
    {
        head->front = nodeToInject;
        head->rear = nodeToInject;
        head->front->next = head->rear;
        head->rear->next = head->front;
    }
    else
    {
        nodeToInject->next = head->front;
        head->rear->next = nodeToInject;
        head->front = nodeToInject;
    }
    head->numOfElements++;
}

int popRear(Queue head)
{
    int returnValue;
    if (head->numOfElements == 0)
    {
        returnValue = -1;
    }
    else if (head->numOfElements > 1)
    {
        ptrNode nodeToPop = head->rear;
        ptrNode prevNodeofRear = head->front;
        while (prevNodeofRear->next != nodeToPop)
        {
            prevNodeofRear = prevNodeofRear->next;
        }
        prevNodeofRear->next = head->front;
        head->rear = prevNodeofRear;
        returnValue = nodeToPop->val;
        head->numOfElements--;
        free(nodeToPop);
    }
    else
    {
        returnValue = head->front->val;
        free(head->front);
        head->front = NULL;
        head->rear = NULL;
        head->numOfElements--;
    }
    return returnValue;
}

void Print(Queue head)
{
    ptrNode nodeForTraversing = head->front;
    if (head->front == NULL)
    {
        printf("%d\n", -1);
        return;
    }
    while (nodeForTraversing != head->rear)
    {
        printf("%d ", nodeForTraversing->val);
        nodeForTraversing = nodeForTraversing->next;
    }
    printf("%d\n", nodeForTraversing->val);
}

void PrintNode(ptrNode front, Queue Q)
{
    if (front == Q->rear)
    {
        printf("%d ", front->val);
        return;
    }
    else
    {
        PrintNode(front->next, Q);
        printf("%d ", front->val);
    }
}

void PrintReverse(Queue head)
{
    if (head->front == NULL)
    {
        printf("%d\n", -1);
        return;
    }
    PrintNode(head->front, head);
    printf("\n");
}

int findElem(Queue head, int pos)
{

    if (pos > head->numOfElements)
    {
        return -1;
    }
    else
    {
        ptrNode nodeForTraversing = head->front;
        for (int i = 1; i < pos; i++)
        {
            nodeForTraversing = nodeForTraversing->next;
        }
        return nodeForTraversing->val;
    }
}

void removeKElems(Queue head, int k)
{
    int removeCount;
    if (head->numOfElements <= k)
    {
        removeCount = head->numOfElements;
    }
    else
    {
        removeCount = k;
    }
    for (int i = 0; i < removeCount; i++)
    {
        Pop(head);
    }
}