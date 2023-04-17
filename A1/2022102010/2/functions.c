#include "functions.h"

int ARR_LEN_OP1 = 0;

int ARR_LEN_OP5 = 0;

int stringLength(char *str)
{
    int count = 0;
    for (int i = 0;; i++)
    {
        if (str[i] == '\0')
        {
            return count;
        }
        else
        {
            count++;
        }
    }
}

int *intersectionArray(int *arr1, int *arr2, int lenArr1, int lenArr2)
{
    int minlen = (lenArr1 <= lenArr2) ? lenArr1 : lenArr2;
    int *result = (int *)malloc(sizeof(int) * minlen);
    int *freq1 = (int *)malloc(sizeof(int) * 10000001);
    int *freq2 = (int *)malloc(sizeof(int) * 10000001);
    int max = -1;
    for (int i = 0; i < lenArr1; i++)
    {
        freq1[arr1[i]] += 1;
        if (arr1[i]>max){
            max=arr1[i];
        }
    }
    for (int i = 0; i < lenArr2; i++)
    {
        freq2[arr2[i]] += 1;
        if (arr2[i]>max){
            max=arr2[i];
        }
    }
    int index = 0;
    for (int i = 0; i <= max; i++)
    {
        if (freq1[i] != 0 && freq2[i] != 0)
        {
            int mintemp = (freq1[i] <= freq2[i]) ? freq1[i] : freq2[i];
            for (int j = 0; j < mintemp; j++)
            {
                result[index++] = i;
            }
        }
    }
    free(freq1);
    free(freq2);
    ARR_LEN_OP1 = index;
    int *defaultResult = (int *)malloc(sizeof(int));
    defaultResult[0] = -1;
    int *resultArray = (int *)realloc(result, sizeof(int) * index);
    return (ARR_LEN_OP1 != 0) ? resultArray : defaultResult;
}

int arrlenop1()
{
    return (ARR_LEN_OP1 != 0) ? ARR_LEN_OP1 : 1;
}

int countCharOccurrences(const char *str, int length, char ch)
{
    int count = 0;
    for (int i = 0; i < length; i++)
    {
        if (ch == str[i])
        {
            count++;
        }
    }
    return count;
}

char findFirstNonRepeatingChar(const char *str, int length)
{
    char flag = '@';
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length; j++)
        {
            if (str[i] == str[j] && i != j)
            {
                break;
            }
            else if (str[i] != str[j] && j == length - 1)
            {
                flag = str[i];
                i = length;
                break;
            }
        }
    }
    return flag;
}

char *findLongestCommonPrefix(char **str, int numStr, int maxLen)
{
    int flag = 1;
    int index = 0;
    char *result = (char *)malloc(sizeof(char) * maxLen);
    for (int i = 0; i < maxLen && flag == 1; i++)
    {
        for (int j = 0; j < numStr; j++)
        {
            if (str[0][i] != str[j][i])
            {
                flag = 0;
                break;
            }
            else if (j == numStr - 1)
            {
                result[index++] = str[0][i];
            }
        }
    }
    result[index] = '\0';
    char *defaultResult = malloc(sizeof(char) * 3);
    defaultResult[0] = '-';
    defaultResult[1] = '1';
    defaultResult[2] = '\0';
    return (stringLength(result) == 0) ? defaultResult : result;
}

int *maxMin(int *arr, int lenArr)
{
    int *result = (int *)malloc(sizeof(int) * lenArr);
    int *maxl = (int *)malloc(sizeof(int)*lenArr);
    int *minr = (int *)malloc(sizeof(int)*lenArr);
    int max_from_left = -1;
    int min_from_right = 1000001;
    int l=0,r=0;
    for (int i=0;i<lenArr;i++){
        if (arr[i]>max_from_left){
            max_from_left = arr[i];
            maxl[l++] = i;
        }
    }

    for (int i=lenArr-1;i>=0;i--){
        if (arr[i]<min_from_right){
            min_from_right = arr[i];
            minr[r++] = i;
        }
    }
    int *freq = (int *)malloc(sizeof(int) * lenArr);
    result = intersectionArray(maxl,minr,l,r);
    free(maxl);
    free(minr);
    free(freq);
    int *defaultResult = malloc(sizeof(int));
    defaultResult[0] = -1;
    ARR_LEN_OP5 = arrlenop1();
    int *resultArray = realloc(result, sizeof(int) * ARR_LEN_OP5);
    return (ARR_LEN_OP5 == 0) ? defaultResult : resultArray;
}


int arrlenop5()
{
    return (ARR_LEN_OP5 != 0) ? ARR_LEN_OP5 : 1;
}

char *removeSubstring(char *str, int strLength, const char *substr, int substrLength)
{
    char *result = (char *)malloc(sizeof(char) * strLength);
    int index = 0;
    for (int i = 0; i < strLength; i++)
    {
        int flag = 0;
        int tempindex = 0;
        for (int j = i; j < i + substrLength; j++)
        {
            if (str[j] != substr[tempindex++])
            {
                flag = 1;
                break;
            }
        }
        if (flag)
        {
            result[index++] = str[i];
        }
        else
        {
            i += substrLength - 1;
        }
    }
    result[index++] = '\0';
    char *defaultResult = malloc(sizeof(char) * 3);
    defaultResult[0] = '-';
    defaultResult[1] = '1';
    defaultResult[2] = '\0';
    return (stringLength(result) == 0) ? defaultResult : result;
}
