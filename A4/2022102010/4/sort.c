
#include "sort.h"

int *merge(int *leftHalf, int *rightHalf, int sizeL, int sizeR)
{
    int *result = (int *)malloc(sizeof(int) * (sizeL + sizeR));
    int c = 0, l = 0, r = 0;
    while (c < sizeL + sizeR)
    {
        if (l < sizeL)
        {
            if (r < sizeR)
            {
                if (leftHalf[l] < rightHalf[r])
                {
                    result[c++] = leftHalf[l++];
                }
                else
                {
                    result[c++] = rightHalf[r++];
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

int *mergeSort(int *arr, int size)
{
    if (size == 1)
    {
        return arr;
    }
    int mid = size / 2;
    int *leftHalf = (int *)malloc(sizeof(int) * (mid));
    int *rightHalf = (int *)malloc(sizeof(int) * (size - mid));
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

int maxNoOfWins(int *arr, int m, int k, int j)
{
    int *maxArr = (int *)malloc(sizeof(int) * m);
    int *jthArr = (int *)malloc(sizeof(int) * m);
    int cMaxArr = 0;
    int cJthArr = 0;
    int tempMax = 0;
    for (int i = 0; i < m * k; i++)
    {
        if (i % k != j - 1)
        {
            if (i % k == k - 1)
            {
                if (arr[i] > tempMax)
                {
                    maxArr[cMaxArr++] = arr[i];
                    tempMax = 0;
                }
                else
                {
                    maxArr[cMaxArr++] = tempMax;
                    tempMax = 0;
                }
            }
            else
            {
                if (arr[i] > tempMax)
                {
                    tempMax = arr[i];
                }
            }
        }
        else
        {
            jthArr[cJthArr++] = arr[i];
            if (i%k==k-1){
                maxArr[cMaxArr++] = tempMax;
                tempMax = 0;
            }
        }
    }
    cMaxArr = 0;
    cJthArr = 0;
    int maxWin = 0;
    maxArr = mergeSort(maxArr, m);
    jthArr = mergeSort(jthArr, m);
    while (cJthArr != m)
    {
        if (maxArr[cMaxArr] > jthArr[cJthArr])
        {
            cJthArr++;
        }
        else
        {
            maxWin++;
            cJthArr++;
            cMaxArr++;
        }
    }
    free(maxArr);
    free(jthArr);
    return maxWin;
}
