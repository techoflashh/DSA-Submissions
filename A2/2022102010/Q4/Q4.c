#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode *Tree;

long long int MAX_SALE = 0;
long long int PREFIX_SUM = 0;

struct TreeNode
{
    long long int key;
    int min;
    int max;
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
    int flag;
    Tree val;
    queueNodePtr next;
};

Tree makeNode(long long int e, int min, int max)
{
    Tree T = (Tree)malloc(sizeof(struct TreeNode));
    T->key = e;
    T->min = min;
    T->max = max;
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


void Push(Queue head, Tree val)
{
    queueNodePtr nodeToInsert = (queueNodePtr)malloc(sizeof(struct Node));
    nodeToInsert->val = val;
    nodeToInsert->flag = 0;
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

void Inject(Queue head, Tree val, int flag)
{
    queueNodePtr nodeToInject = (queueNodePtr)malloc(sizeof(struct Node));
    nodeToInject->val = val;
    nodeToInject->flag = flag;
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

Tree ListToBST(const int *arr, int len)
{
    Tree T = NULL;
    Queue Q = initiallizeQueue();
    T = makeNode(arr[0], -10000001, 10000001);
    Push(Q, T);
    Tree temp;
    for (int i = 1; i < len; i++)
    {
        temp = Pop(Q);
        if (temp->max > arr[i] && temp->min < arr[i]){
            if (arr[i] < temp->key){
                if (temp->leftChild != NULL){
                    i--;
                }else{
                    temp->leftChild = makeNode(arr[i],temp->min,temp->key);
                    Inject(Q,temp,0);
                    Push(Q,temp->leftChild);
                }
            }else{
                temp->rightChild = makeNode(arr[i],temp->key,temp->max);
                Push(Q, temp->rightChild);
            }
        }else{
            i--;
        }
    }
    return T;
}

void ModifyBST(Tree T)
{
    Queue Q = initiallizeQueue();
    Inject(Q, T, 1);
    while (Q->numOfElements != 0)
    {
        int flag = Q->front->flag;
        Tree T = Pop(Q);
        if (flag == 0)
        {
            long long int temp = T->key;
            T->key += PREFIX_SUM;
            MAX_SALE += T->key;
            PREFIX_SUM += temp;
        }
        else
        {
            if (T->rightChild != NULL)
                Inject(Q, T->rightChild, 1);

            Inject(Q, T, 0);

            if (T->leftChild != NULL)
                Inject(Q, T->leftChild, 1);
        }
    }
}

void printLevelOrder(Tree T)
{
    Queue Q = initiallizeQueue();
    Push(Q, T);
    while (Q->numOfElements != 0)
    {
        Tree temp = Pop(Q);
        if (temp->leftChild != NULL && temp->rightChild != NULL)
        {
            Push(Q, temp->leftChild);
            Push(Q, temp->rightChild);
        }
        else if (temp->leftChild != NULL)
        {
            Push(Q, temp->leftChild);
        }
        else if (temp->rightChild != NULL)
        {
            Push(Q, temp->rightChild);
        }
        printf("%lld ", temp->key);
    }
}

int main()
{
    int N;
    scanf("%d", &N);
    int arr[N];
    Tree T = NULL;
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }
    T = ListToBST(arr, N);
    ModifyBST(T);
    printLevelOrder(T);
    printf("\n");
    printf("%lld\n", MAX_SALE);
}
