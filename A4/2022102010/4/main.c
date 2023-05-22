#include "sort.h"

int main()
{
    int t;
    scanf("%d", &t);
    for (int v = 0; v < t; v++)
    {
        int k, m;
        scanf("%d %d", &k, &m);
        int arr[k * m];
        for (int i = 0; i < k * m; i++)
        {
            scanf("%d", &arr[i]);
        }
        int j;
        scanf("%d", &j);
        printf("%d\n", maxNoOfWins(arr, m, k, j));
    }
    return 0;
}