#include "functions.h"

int main()
{
    char operation[10];
    scanf("%s", operation);
    if (operation[0] == 'T')
    {
        int N, M, K;
        scanf("%d %d %d", &N, &M, &K);
        PtrNode2 S1 = initializeAddLL();
        for (int v = 0; v < K; v++)
        {
            int i, j, val;
            scanf("%d %d %d", &i, &j, &val);
            insertElementsForTRA(S1,j,i,val);
        }
        printf("%d\n",K);
        sMatrix result = TRA(S1);
        PrintMatrix(result);
    }
    else if (operation[0] == 'A')
    {
        int N, M, K1, K2;
        scanf("%d %d %d %d", &N, &M, &K1, &K2);
        PtrNode2 S1 = initializeAddLL();
        for (int v = 0; v < K1; v++)
        {
            int i, j, val;
            scanf("%d %d %d", &i, &j, &val);
            insertElementsForADD(S1,i,j,val);
        }
        PtrNode2 S2 = initializeAddLL();
        for (int i = 0; i < K2; i++)
        {
            int i, j, val;
            scanf("%d %d %d", &i, &j, &val);
            insertElementsForADD(S2,i,j,val);
        }
        PtrNode2 result = ADD(S1, S2);
        printf("%d\n", lenLL());
        PrintADD(result);
    }
    else if (operation[0] == 'M')
    {
        int N, M, L, K1, K2;
        scanf("%d %d %d %d %d", &N, &M, &L, &K1, &K2);
        sMatrix S1 = initializeMatrix();
        for (int v = 0; v < K1; v++)
        {
            int i, j, val;
            scanf("%d %d %d", &i, &j, &val);
            sMatrix tempRow = findRow(S1, i);
            if (tempRow == NULL || tempRow == S1)
            {
                PtrNode rowHead = initializeLinkedList();
                InsertElementInRow(rowHead, j, val);
                InsertRow(S1, i, rowHead);
            }
            else
            {
                InsertElementInRow(tempRow->HeadofRow, j, val);
            }
        }
        PtrNode2 S2 = initializeAddLL();
        for (int i = 0; i < K2; i++)
        {
            int i, j, val;
            scanf("%d %d %d", &i, &j, &val);
            insertElementsForTRA(S2,j,i,val);
        }
        sMatrix result = MUL(S1, S2);
        printf("%d\n", lenLL());
        PrintMatrix(result);
    }
}