#include "sort.h"

int main()
{
    int t;
    scanf("%d", &t);
    for (int v = 0; v < t; v++)
    {
        int n;
        scanf("%d", &n);
        pairPtr pairArray = (pairPtr)malloc(sizeof(struct pair) * n);
        int temp;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &temp);
            pairArray[i].a = temp;
        }
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &temp);
            pairArray[i].b = temp;
        }
        magicMarbles(pairArray, n);
    }
    return 0;
}