#include "sort.h"

int isEven(int n)
{
    return (n % 2 == 0);
}

int stringCompare(char *a, char *b)
{
    for (int i = 1;; i++)
    {
        if (a[i - 1] != '@' && b[i - 1] != '@')
        {
            if (a[i - 1] == b[i - 1])
            {
                continue;
            }
            else
            {
                if (!isEven(i))
                {
                    if (a[i - 1] < b[i - 1])
                    {
                        return -1;
                    }
                    else
                    {
                        return 1;
                    }
                }
                else
                {
                    if (a[i - 1] > b[i - 1])
                    {
                        return -1;
                    }
                    else
                    {
                        return 1;
                    }
                }
            }
        }
        else if (a[i - 1] == '@' && b[i - 1] != '@')
        {
            if (!isEven(i - 1))
            {
                return -1;
            }
            else
            {
                return 1;
            }
        }
        else if (a[i - 1] != '@' && b[i - 1] == '@')
        {
            if (isEven(i - 1))
            {
                return -1;
            }
            else
            {
                return 1;
            }
        }
        else
        {
            return 1;
        }
    }
}

stringList merge(stringList leftHalf, stringList rightHalf, int sizeL, int sizeR)
{
    stringList result = (stringList)malloc(sizeof(char *) * (sizeL + sizeR));
    int c = 0, l = 0, r = 0;
    while (c < sizeL + sizeR)
    {
        if (l < sizeL)
        {
            if (r < sizeR)
            {
                if (stringCompare(leftHalf[l], rightHalf[r]) == -1)
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

stringList mergeSort(stringList arr, int size)
{
    if (size == 1)
    {
        return arr;
    }
    int mid = size / 2;
    stringList leftHalf = (stringList)malloc(sizeof(char *) * (mid));
    stringList rightHalf = (stringList)malloc(sizeof(char *) * (size - mid));
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

void printString(char *a)
{
    for (int i = 0; a[i] != '@'; i++)
    {
        printf("%c", a[i]);
    }
    printf("\n");
}