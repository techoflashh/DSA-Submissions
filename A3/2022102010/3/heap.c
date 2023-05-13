#include "heap.h"

Heap initiallizeHeap(int capacity)
{
    Heap H = (Heap)malloc(sizeof(struct HeapStruct));
    H->capacity = capacity + 1;
    H->size = 1;
    H->Elements = (int *)malloc(sizeof(int) * H->capacity);
    H->Elements[0] = -1000001;
    return H;
}

void Insert(Heap H, int e)
{
    int i;
    for (i = H->size; H->Elements[i / 2] > e && i/2 !=0 ; i = i / 2)
    {
        H->Elements[i] = H->Elements[i / 2];
    }
    H->size++;
    H->Elements[i] = e;
}

int DeleteHead(Heap H)
{
    int returnValue = H->Elements[1];
    H->Elements[1] = H->Elements[--H->size];
    int temp;
    for (int i = 1; i * 2 < H->size; i = temp)
    {
        int left = i * 2;
        int right = i * 2 + 1;
        if (H->Elements[i] > H->Elements[left])
        {
            if (right < H->size)
            {
                if (H->Elements[right] > H->Elements[left])
                {
                    int temp2 = H->Elements[i];
                    H->Elements[i] = H->Elements[left];
                    H->Elements[left] = temp2;
                    temp = left;
                }
                else
                {
                    int temp2 = H->Elements[i];
                    H->Elements[i] = H->Elements[right];
                    H->Elements[right] = temp2;
                    temp = right;
                }
            }
            else
            {
                int temp2 = H->Elements[i];
                H->Elements[i] = H->Elements[left];
                H->Elements[left] = temp2;
                temp = left;
            }
        }
        else if (H->Elements[i] > H->Elements[right])
        {
            int temp2 = H->Elements[i];
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

void DeleteHeap(Heap H)
{
    free(H->Elements);
    free(H);
}

int calculateMaxNoOfNobs(int *arr, int len)
{
    int count = 0;
    int sum = 0;
    Heap H = initiallizeHeap(len);
    for (int i = 0; i < len; i++)
    {
        if (arr[i] >= 0)
        {
            Insert(H, arr[i]);
            count++;
            sum += arr[i];
        }
        else
        {
            if (arr[i] + sum >= 0)
            {
                count++;
                Insert(H, arr[i]);
                sum += arr[i];
            }
            else
            {
                if (arr[i] > H->Elements[1])
                {
                    sum -= H->Elements[1];
                    DeleteHead(H);
                    Insert(H, arr[i]);
                    sum += arr[i];
                }
            }
        }
    }
    DeleteHeap(H);
    return count;
}
