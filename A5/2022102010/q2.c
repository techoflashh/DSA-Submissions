#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

typedef struct Head *Queue;
typedef struct Node *ptrNode;

struct Head
{
    int capacity;
    int numOfElements;
    int front;
    int rear;
    ptrNode* Elements;
};

struct Node
{
    short int i;
    short int j;
};

int modulo(int a, int b){
    return (a>=0)?a%b:a%b + b;
}

void initiallizeQueue(Queue Q);

bool isEmpty(Queue Q){
    return (Q->numOfElements == 0);
}

void Push(Queue Q,int i,int j);

ptrNode Pop(Queue Q);

void Inject(Queue Q,int i,int j);

void initiallizeQueue(Queue Q)
{
    Q->numOfElements = 0;
    Q->rear = -1;
    Q->front = 0;
}

void Inject(Queue Q,int i,int j)
{
    int index = modulo(--Q->front,Q->capacity);
    ptrNode temp = Q->Elements[index];
    temp->i = i;
    temp->j = j;
    Q->front = index;
    Q->numOfElements++;
}

ptrNode Pop(Queue Q)
{
    ptrNode returnValue = Q->Elements[Q->front];
    Q->front = modulo(++Q->front,Q->capacity);
    Q->numOfElements--;
    return returnValue;
}

void Push(Queue Q, int i,int j)
{
    int index = modulo(++Q->rear,Q->capacity);
    ptrNode temp = Q->Elements[index];
    temp->i = i;
    temp->j = j;
    Q->rear = index;
    Q->numOfElements++;
}

int dijkstra(int n, int m, short int input_Grid[n][m],Queue Q)
{
    int shortestPath[n][m];
    bool visited[n][m];
    bool known[n][m];
    short int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            shortestPath[i][j] = INT_MAX;
            visited[i][j] = 0;
            known[i][j] = 0;
        }
    }
    initiallizeQueue(Q);
    shortestPath[0][0] = 0;
    visited[0][0] = 1;
    Inject(Q, 0,0);
    while (Q->numOfElements != 0)
    {
        ptrNode P = Pop(Q);
        i = P->i;
        j = P->j;
        if (known[i][j]==0)
            known[i][j] = 1;
        else
            continue;
        if (known[n-1][m-1]==1){
            return shortestPath[n-1][m-1];
        }
        if (i + 1 < n)
        {
            if (visited[i + 1][j] == 0)
            {
                visited[i+1][j] = 1;
                if (input_Grid[i + 1][j] == input_Grid[i][j])
                {
                    Inject(Q, i+1,j);
                    if (shortestPath[i + 1][j] > shortestPath[i][j])
                    {
                        shortestPath[i + 1][j] = shortestPath[i][j];
                    }
                }
                else
                {
                    Push(Q, i+1,j);
                    if (shortestPath[i + 1][j] > shortestPath[i][j] + 1)
                    {
                        shortestPath[i + 1][j] = shortestPath[i][j] + 1;
                    }
                }
            }else{
                if (input_Grid[i + 1][j] == input_Grid[i][j])
                {
                    if (shortestPath[i + 1][j] > shortestPath[i][j])
                    {
                        Inject(Q,i+1,j);
                        shortestPath[i + 1][j] = shortestPath[i][j];
                    }
                }
                else
                {
                    if (shortestPath[i + 1][j] > shortestPath[i][j] + 1)
                    {
                        Inject(Q,i+1,j);
                        shortestPath[i + 1][j] = shortestPath[i][j] + 1;
                    }
                }
            }
        }

        if (i - 1 >= 0)
        {
            if (visited[i - 1][j] == 0)
            {
                visited[i-1][j] = 1;
                if (input_Grid[i - 1][j] == input_Grid[i][j])
                {
                    Inject(Q, i-1,j);
                    if (shortestPath[i - 1][j] > shortestPath[i][j])
                    {
                        shortestPath[i - 1][j] = shortestPath[i][j];
                    }
                }
                else
                {
                    Push(Q, i-1,j);
                    if (shortestPath[i - 1][j] > shortestPath[i][j] + 1)
                    {
                        shortestPath[i - 1][j] = shortestPath[i][j] + 1;
                    }
                }
            }else{
                if (input_Grid[i - 1][j] == input_Grid[i][j])
                {
                    
                    if (shortestPath[i - 1][j] > shortestPath[i][j])
                    {
                        Inject(Q,i-1,j);
                        shortestPath[i - 1][j] = shortestPath[i][j];
                    }
                }
                else
                {
                    if (shortestPath[i - 1][j] > shortestPath[i][j] + 1)
                    {
                        Inject(Q,i-1,j);
                        shortestPath[i - 1][j] = shortestPath[i][j] + 1;
                    }
                }
            }
        }
        if (j + 1 < m)
        {
            if (visited[i][j + 1] == 0)
            {
                visited[i][j+1] =1;
                if (input_Grid[i][j + 1] == input_Grid[i][j])
                {
                    Inject(Q, i,j+1);
                    if (shortestPath[i][j + 1] > shortestPath[i][j])
                    {
                        shortestPath[i][j + 1] = shortestPath[i][j];
                    }
                }
                else
                {
                    Push(Q, i,j+1);
                    if (shortestPath[i][j + 1] > shortestPath[i][j] + 1)
                    {
                        shortestPath[i][j + 1] = shortestPath[i][j] + 1;
                    }
                }
            }else{
                if (input_Grid[i][j + 1] == input_Grid[i][j])
                {
                    if (shortestPath[i][j + 1] > shortestPath[i][j])
                    {
                        Inject(Q,i,j+1);
                        shortestPath[i][j + 1] = shortestPath[i][j];
                    }
                }
                else
                {
                    if (shortestPath[i][j + 1] > shortestPath[i][j] + 1)
                    {
                        Inject(Q,i,j+1);
                        shortestPath[i][j + 1] = shortestPath[i][j] + 1;
                    }
                }
            }
        }
        if (j - 1 >= 0)
        {
            if (visited[i][j - 1] == 0)
            {
                visited[i][j-1] = 1;
                if (input_Grid[i][j - 1] == input_Grid[i][j])
                {
                    Inject(Q, i,j-1);
                    if (shortestPath[i][j - 1] > shortestPath[i][j])
                    {
                        shortestPath[i][j - 1] = shortestPath[i][j];
                    }
                }
                else
                {
                    Push(Q, i,j-1);
                    if (shortestPath[i][j - 1] > shortestPath[i][j] + 1)
                    {
                        shortestPath[i][j - 1] = shortestPath[i][j] + 1;
                    }
                }
            }
            else{
                if (input_Grid[i][j - 1] == input_Grid[i][j])
                {
                    if (shortestPath[i][j - 1] > shortestPath[i][j])
                    {
                        Inject(Q,i,j-1);
                        shortestPath[i][j - 1] = shortestPath[i][j];
                    }
                }
                else
                {
                    if (shortestPath[i][j - 1] > shortestPath[i][j] + 1)
                    {
                        Inject(Q,i,j-1);
                        shortestPath[i][j - 1] = shortestPath[i][j] + 1;
                    }
                }
            }
        }
    }
    free(Q);
    return shortestPath[n - 1][m - 1];
}

int main()
{
    short int t;
    scanf("%hd", &t);
    Queue Q = (Queue)malloc(sizeof(struct Head));
    Q->capacity = 1000000;
    Q->Elements = (ptrNode*)malloc(sizeof(ptrNode)*Q->capacity);
    for (int i=0;i<Q->capacity;i++){
        Q->Elements[i] = (ptrNode)malloc(sizeof(struct Node));
    }
    for (int v = 0; v < t; v++)
    {
        short int n, m;
        scanf("%hd %hd", &n, &m);
        short int input_grid[n][m];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                scanf("%hd", &input_grid[i][j]);
            }
        }
        printf("%d\n", dijkstra(n, m, input_grid,Q));
    }

    return 0;
}