#include "heap.h"

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    Heap H = initiallizeHeap(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        Insert(H, arr[i]);
    }
    findDerangementAndPrint(arr,n,H);
    return 0;
}