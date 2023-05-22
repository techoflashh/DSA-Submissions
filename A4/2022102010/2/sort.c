#include "sort.h"

pairPtr merge(pairPtr leftHalf, pairPtr rightHalf, int sizeL, int sizeR)
{
    pairPtr result = (pairPtr)malloc(sizeof(struct pair) * (sizeL + sizeR));
    int c = 0, l = 0, r = 0;
    while (c < sizeL + sizeR)
    {
        if (l < sizeL)
        {
            if (r < sizeR)
            {
                if (leftHalf[l].a < rightHalf[r].a)
                {
                    result[c++] = leftHalf[l++];
                }
                else if (leftHalf[l].a > rightHalf[r].a)
                {
                    result[c++] = rightHalf[r++];
                }else{
                    if (leftHalf[l].b < rightHalf[r].b){
                        result[c++] = leftHalf[l++];
                    }else{
                        result[c++] = rightHalf[r++];
                    }
                }
            }
            else
            {
                free(rightHalf);
                while (l < sizeL)
                {
                    result[c++] = leftHalf[l++];
                }
            }
        }
        else
        {
            free(leftHalf);
            while (r < sizeR)
            {
                result[c++] = rightHalf[r++];
            }
        }
    }
    return result;
}

pairPtr mergeSort(pairPtr arr, int size)
{
    if (size == 1)
    {
        return arr;
    }
    int mid = size / 2;
    pairPtr leftHalf = (pairPtr)malloc(sizeof(struct pair) * (mid));
    pairPtr rightHalf = (pairPtr)malloc(sizeof(struct pair) * (size - mid));
    for (int i = 0; i < mid; i++)
    {
        leftHalf[i] = arr[i];
    }
    for (int i = mid; i < size; i++)
    {
        rightHalf[i - mid] = arr[i];
    }
    leftHalf = mergeSort(leftHalf, mid);
    rightHalf = mergeSort(rightHalf, size - mid);
    return merge(leftHalf, rightHalf, mid, size - mid);
}

void magicMarbles(pairPtr pairArray, int size)
{
    pairPtr sortedPairArray = mergeSort(pairArray, size);
    int j1[size], j2[size];
    j1[0] = sortedPairArray[0].a;
    if (sortedPairArray[0].a < sortedPairArray[0].b)
        j2[0] = sortedPairArray[0].a;
    else
        j2[0] = sortedPairArray[0].b;
    for (int i = 1; i < size; i++)
    {
        j1[i] = sortedPairArray[i].a;
        if (sortedPairArray[i].a >= sortedPairArray[i].b)
        {
            if (j2[i - 1] <= sortedPairArray[i].b)
            {
                j2[i] = sortedPairArray[i].b;
            }
            else
            {
                j2[i] = sortedPairArray[i].a;
            }
        }
        else
        {
            j2[i] = sortedPairArray[i].a;
        }
    }
    printf("%d %d\n", j1[size - 1], j2[size - 1]);
}