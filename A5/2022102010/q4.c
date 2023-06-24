#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct HeapStruct *Heap;
typedef struct Triplet *Triplet;

struct Triplet
{
    int i;
    int j;
    int weight;
};

struct HeapStruct
{
    int capacity;
    int size;
    Triplet *Elements;
};

Heap initiallizeHeap(int capacity)
{
    Heap H = (Heap)malloc(sizeof(struct HeapStruct));
    H->capacity = capacity + 1;
    H->size = 1;
    H->Elements = (Triplet *)malloc(sizeof(Triplet) * H->capacity);
    for (int i = 0; i < H->capacity; i++)
    {
        H->Elements[i] = (Triplet)malloc(sizeof(struct Triplet));
    }
    H->Elements[0]->weight = -1;
    return H;
}

void Insert(Heap H, Triplet e)
{
    int i;
    for (i = H->size; H->Elements[i / 2]->weight > e->weight && i / 2 != 0; i = i / 2)
    {
        H->Elements[i] = H->Elements[i / 2];
    }
    H->size++;
    H->Elements[i] = e;
}

Triplet DeleteHead(Heap H)
{
    Triplet returnValue = H->Elements[1];
    H->Elements[1] = H->Elements[--H->size];
    int temp;
    for (int i = 1; i * 2 < H->size; i = temp)
    {
        int left = i * 2;
        int right = i * 2 + 1;
        if (H->Elements[i]->weight > H->Elements[left]->weight)
        {
            if (right < H->size)
            {
                if (H->Elements[right]->weight > H->Elements[left]->weight)
                {
                    Triplet temp2 = H->Elements[i];
                    H->Elements[i] = H->Elements[left];
                    H->Elements[left] = temp2;
                    temp = left;
                }
                else
                {
                    Triplet temp2 = H->Elements[i];
                    H->Elements[i] = H->Elements[right];
                    H->Elements[right] = temp2;
                    temp = right;
                }
            }
            else
            {
                Triplet temp2 = H->Elements[i];
                H->Elements[i] = H->Elements[left];
                H->Elements[left] = temp2;
                temp = left;
            }
        }
        else if (H->Elements[i]->weight > H->Elements[right]->weight)
        {
            Triplet temp2 = H->Elements[i];
            H->Elements[i] = H->Elements[right];
            H->Elements[right] = temp2;
            temp = right;
        }
        else
        {
            break;
        }
    }
    return returnValue;
}

Triplet makeTriplet(int i, int j, int weight)
{
    Triplet t = (Triplet)malloc(sizeof(struct Triplet));
    t->i = i;
    t->j = j;
    t->weight = weight;
    return t;
}

void dijkstra(int n, int m, int inputGrid[n][m], Heap H, int shortestPath[n][m], int visited[n][m])
{
    while (H->size != 1)
    {
        Triplet T = DeleteHead(H);
        int i = T->i;
        int j = T->j;
        int tempWeight = shortestPath[i][j];
        free(T);
        if (i + 1 < n)
        {
            int r = i + 1, c = j;
            if (tempWeight + inputGrid[r][c] < shortestPath[r][c])
            {
                shortestPath[r][c] = tempWeight + inputGrid[r][c];

                if (visited[r][c] == 0)
                {
                    Triplet temptriplet = makeTriplet(r, c, shortestPath[r][c]);
                    Insert(H, temptriplet);
                    visited[r][c] = 1;
                }
            }

            if (j + 1 < m)
            {
                r = i + 1, c = j + 1;
                if (tempWeight + inputGrid[r][c] < shortestPath[r][c])
                {
                    shortestPath[r][c] = tempWeight + inputGrid[r][c];

                    if (visited[r][c] == 0)
                    {
                        Triplet temptriplet = makeTriplet(r, c, shortestPath[r][c]);
                        Insert(H, temptriplet);
                        visited[r][c] = 1;
                    }
                }
            }
            if (j - 1 >= 0)
            {
                r = i + 1, c = j - 1;
                if (tempWeight + inputGrid[r][c] < shortestPath[r][c])
                {
                    shortestPath[r][c] = tempWeight + inputGrid[r][c];

                    if (visited[r][c] == 0)
                    {
                        Triplet temptriplet = makeTriplet(r, c, shortestPath[r][c]);
                        Insert(H, temptriplet);
                        visited[r][c] = 1;
                    }
                }
            }
        }
        if (i - 1 >= 0)
        {
            int r = i - 1, c = j;
            if (tempWeight + inputGrid[r][c] < shortestPath[r][c])
            {
                shortestPath[r][c] = tempWeight + inputGrid[r][c];

                if (visited[r][c] == 0)
                {
                    Triplet temptriplet = makeTriplet(r, c, shortestPath[r][c]);
                    Insert(H, temptriplet);
                    visited[r][c] = 1;
                }
            }
            if (j - 1 >= 0)
            {
                r = i - 1, c = j - 1;
                if (tempWeight + inputGrid[r][c] < shortestPath[r][c])
                {
                    shortestPath[r][c] = tempWeight + inputGrid[r][c];
                    if (visited[r][c] == 0)
                    {
                        Triplet temptriplet = makeTriplet(r, c, shortestPath[r][c]);
                        Insert(H, temptriplet);
                        visited[r][c] = 1;
                    }
                }
            }
            if (j + 1 < m)
            {
                r = i-1, c = j + 1;
                if (tempWeight + inputGrid[r][c] < shortestPath[r][c])
                {
                    shortestPath[r][c] = tempWeight + inputGrid[r][c];

                    if (visited[r][c] == 0)
                    {
                        Triplet temptriplet = makeTriplet(r, c, shortestPath[r][c]);
                        Insert(H, temptriplet);
                        visited[r][c] = 1;
                    }
                }
            }
        }
        if (j + 1 < m)
        {
            int r = i, c = j + 1;
            if (tempWeight + inputGrid[r][c] < shortestPath[r][c])
            {
                shortestPath[r][c] = tempWeight + inputGrid[r][c];

                if (visited[r][c] == 0)
                {
                    Triplet temptriplet = makeTriplet(r, c, shortestPath[r][c]);
                    Insert(H, temptriplet);
                    visited[r][c] = 1;
                }
            }
        }
        if (j - 1 >= 0)
        {
            int r = i, c = j - 1;
            if (tempWeight + inputGrid[r][c] < shortestPath[r][c])
            {
                shortestPath[r][c] = tempWeight + inputGrid[r][c];

                if (visited[r][c] == 0)
                {
                    Triplet temptriplet = makeTriplet(r, c, shortestPath[r][c]);
                    Insert(H, temptriplet);
                    visited[r][c] = 1;
                }
            }
        }
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    for (int v = 0; v < t; v++)
    {
        int n, m;
        scanf("%d %d", &n, &m);
        int inputGrid[n][m];
        int shortestPath[n][m];
        int visited[n][m];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                scanf("%d", &inputGrid[i][j]);
                shortestPath[i][j] = INT_MAX;
                visited[i][j] = 0;
            }
        }
        Heap H = initiallizeHeap(n * m);
        for (int i = 0; i < n; i++)
        {
            Triplet temp = makeTriplet(i, 0, inputGrid[i][0]);
            Insert(H, temp);
            shortestPath[i][0] = inputGrid[i][0];
            visited[i][0] = 1;
        }

        for (int i = 1; i < m; i++)
        {
            Triplet temp = makeTriplet(n - 1, i, inputGrid[n - 1][i]);
            Insert(H, temp);
            shortestPath[n - 1][i] = inputGrid[n - 1][i];
            visited[n - 1][i] = 1;
        }

        dijkstra(n, m, inputGrid, H, shortestPath, visited);

        int min = INT_MAX;
        for (int i = 0; i < m; i++)
        {
            if (shortestPath[0][i] < min)
            {
                min = shortestPath[0][i];
            }
        }

        for (int i = 1; i < n; i++)
        {
            if (shortestPath[i][m - 1] < min)
            {
                min = shortestPath[i][m - 1];
            }
        }

        printf("%d\n", min);
    }

    return 0;
}