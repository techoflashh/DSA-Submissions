#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode *Tree;

struct TreeNode
{
    int key;
    int level;
    Tree leftChild;
    Tree rightChild;
};

typedef struct Head *Queue;
typedef struct Node *queueNodePtr;

struct Head
{
    int numOfElements;
    queueNodePtr front;
    queueNodePtr rear;
};

struct Node
{
    Tree val;
    queueNodePtr next;
    queueNodePtr prev;
};

Tree makeNode(int element, int level)
{
    Tree T = (Tree)malloc(sizeof(struct TreeNode));
    T->level = level;
    T->key = element;
    T->leftChild = NULL;
    T->rightChild = NULL;
    return T;
}

Queue initiallizeQueue()
{
    Queue Q = (Queue)malloc(sizeof(struct Head));
    Q->numOfElements = 0;
    Q->rear = NULL;
    Q->front = NULL;
    return Q;
}

Tree Insert(Tree T, int element, int level)
{
    if (T == NULL)
    {
        T = makeNode(element, level + 1);
    }
    else if (element < T->key)
    {
        T->leftChild = Insert(T->leftChild, element, level + 1);
    }
    else if (element > T->key)
    {
        T->rightChild = Insert(T->rightChild, element, level + 1);
    }
    return T;
}

void Push(Queue head, Tree val)
{
    queueNodePtr nodeToInsert = (queueNodePtr)malloc(sizeof(struct Node));
    nodeToInsert->val = val;
    if (head->numOfElements == 0)
    {
        head->front = nodeToInsert;
        head->rear = nodeToInsert;
        head->front->next = head->rear;
        head->rear->next = head->front;
        head->front->prev = head->rear;
        head->rear->prev = head->front;
    }
    else
    {
        nodeToInsert->next = head->front;
        head->front->prev = nodeToInsert;
        nodeToInsert->prev = head->rear;
        head->rear->next = nodeToInsert;
        head->rear = nodeToInsert;
    }
    head->numOfElements++;
}

void Inject(Queue head, Tree val)
{
    queueNodePtr nodeToInject = (queueNodePtr)malloc(sizeof(struct Node));
    nodeToInject->val = val;
    if (head->numOfElements == 0)
    {
        head->front = nodeToInject;
        head->rear = nodeToInject;
        head->front->next = head->rear;
        head->rear->next = head->front;
        head->front->prev = head->rear;
        head->rear->prev = head->front;
    }
    else
    {
        nodeToInject->next = head->front;
        head->front->prev = nodeToInject;
        nodeToInject->prev = head->rear;
        head->rear->next = nodeToInject;
        head->front = nodeToInject;
    }
    head->numOfElements++;
}

Tree Pop(Queue head)
{
    Tree returnValue;
    if (head->numOfElements == 0)
    {
        returnValue = NULL;
    }
    else if (head->numOfElements > 1)
    {
        queueNodePtr nodeToPop = head->front;
        head->rear->next = head->front->next;
        nodeToPop->next->prev = head->rear;
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

Tree popRear(Queue head)
{
    Tree returnValue;
    if (head->numOfElements == 0)
    {
        returnValue = NULL;
    }
    else if (head->numOfElements > 1)
    {
        queueNodePtr nodeToPop = head->rear;
        nodeToPop->prev->next = head->front;
        head->front->prev = nodeToPop->prev;
        head->rear = nodeToPop->prev;
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

void printBeutiful(Tree T)
{
    Queue Q = initiallizeQueue();
    Push(Q,T);
    int flag = 0;
    int flag2 = Q->rear->val->level;
    while (Q->numOfElements != 0)
    {
        if (flag == 0)
        {
            if (flag2 != Q->rear->val->level)
            {
                flag = 1;
                flag2 = Q->front->val->level;
            }
        }
        else
        {
            if (flag2 != Q->front->val->level)
            {
                flag = 0;
                flag2 = Q->rear->val->level;
            }
        }
        Tree temp;
        if (flag == 1)
        {
            temp = Pop(Q);
        }
        else
        {
            temp = popRear(Q);
        }

        if (temp->leftChild != NULL && temp->rightChild == NULL)
        {
            if (flag == 0)
            {
                Inject(Q, temp->leftChild);
            }
            else
            {
                Push(Q, temp->leftChild);
            }
        }
        if (temp->leftChild == NULL && temp->rightChild != NULL)
        {
            if (flag == 0)
            {
                Inject(Q, temp->rightChild);
            }
            else
            {
                Push(Q, temp->rightChild);
            }
        }
        if (temp->leftChild != NULL && temp->rightChild != NULL)
        {
            if (flag == 0)
            {
                Inject(Q, temp->leftChild);
                Inject(Q, temp->rightChild);
            }
            else
            {
                Push(Q, temp->rightChild);
                Push(Q, temp->leftChild);
            }
        }
        printf("%d ", temp->key);
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    for (int v = 0; v < t; v++)
    {
        int N;
        scanf("%d", &N);
        int temp;
        Tree T = NULL;
        for (int i = 0; i < N; i++)
        {
            scanf("%d", &temp);
            T = Insert(T, temp, -1);
        }
        printBeutiful(T);
        printf("\n");
    }
}