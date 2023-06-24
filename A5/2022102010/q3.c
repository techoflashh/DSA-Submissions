#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct pair *Pair;
typedef struct Head *Queue;
typedef struct Node *ptrNode;
typedef Pair Elemtype;

struct pair
{
    int i;
    int j;
};

struct Head
{
    int numOfElements;
    ptrNode front;
    ptrNode rear;
};

struct Node
{
    Elemtype val;
    ptrNode next;
};

Queue initiallizeQueue();

Elemtype Pop(Queue head);

void Inject(Queue head, Elemtype val);

Queue initiallizeQueue()
{
    Queue Q = (Queue)malloc(sizeof(struct Head));
    Q->numOfElements = 0;
    Q->rear = NULL;
    Q->front = NULL;
    return Q;
}

Elemtype Pop(Queue head)
{
    Elemtype returnValue;
    if (head->numOfElements == 0)
    {
        returnValue = NULL;
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

void Inject(Queue head, Elemtype val)
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

Pair createPair(int i, int j)
{
    Pair P = (Pair)malloc(sizeof(struct pair));
    P->i = i;
    P->j = j;
    return P;
}

int DFS(int n, int m, int i, int j, short int inputGrid[n][m], short int visitedGrid[n][m])
{
    Queue Q = initiallizeQueue();
    Pair P = createPair(i, j);
    int maxProfit = 0;
    int r, c;
    Inject(Q,P);
    visitedGrid[i][j] = 1;
    while (Q->numOfElements != 0)
    {
        P = Pop(Q);
        r = P->i;
        c = P->j;
        int degree = 0;
        if (r + 1 < n)
        {
            if (inputGrid[r + 1][c] == 1)
            {
                degree++;
                if (visitedGrid[r + 1][c] == 0)
                {
                    Pair tempPair = createPair(r + 1, c);
                    Inject(Q, tempPair);
                    visitedGrid[r + 1][c] = 1;
                }
            }
        }
        if (r - 1 >= 0)
        {
            if (inputGrid[r - 1][c] == 1)
            {
                degree++;
                if (visitedGrid[r - 1][c] == 0)
                {
                    Pair tempPair = createPair(r - 1, c);
                    Inject(Q, tempPair);
                    visitedGrid[r - 1][c] = 1;
                }
            }
        }
        if (c + 1 < m)
        {
            if (inputGrid[r][c + 1] == 1)
            {
                degree++;
                if (visitedGrid[r][c + 1] == 0)
                {
                    Pair tempPair = createPair(r, c + 1);
                    Inject(Q, tempPair);
                    visitedGrid[r][c + 1] = 1;
                }
            }
        }
        if (c - 1 >= 0)
        {
            if (inputGrid[r][c - 1] == 1)
            {
                degree++;
                if (visitedGrid[r][c - 1] == 0)
                {
                    Pair tempPair = createPair(r, c - 1);
                    Inject(Q, tempPair);
                    visitedGrid[r][c - 1] = 1;
                }
            }
        }
        maxProfit += degree;
    }
    return maxProfit;
}

int main()
{

    int n, m, r;
    scanf("%d %d %d", &n, &m, &r);
    short int inputGrid[n][m];
    short int visitedGrid[n][m];
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            inputGrid[i][j] = 0;
            visitedGrid[i][j] = 0;
        }
    }
    for (int v = 0; v < r; v++)
    {
        scanf("%d %d", &i, &j);
        inputGrid[i-1][j-1] = 1;
    }

    int max = INT_MIN;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (inputGrid[i][j]==1 && visitedGrid[i][j]==0){
                int temp = DFS(n,m,i,j,inputGrid,visitedGrid);
                if (temp>max){
                    max = temp;
                }
            }
        }
    }
    printf("%d\n",max);
    return 0;
}
