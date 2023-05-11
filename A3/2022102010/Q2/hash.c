#include "hash.h"

long long int *getHashMapPrefix(char *input, int len)
{
    long long int powervalue = P;
    long long int *hashMap = (long long int *)malloc(sizeof(long long int) * len);
    hashMap[0] = (input[0] - 'a' + 1) % Table_size;
    for (int i = 1; i < len; i++)
    {
        hashMap[i] = (hashMap[i - 1] + ((input[i] - 'a' + 1) * powervalue) % Table_size) % Table_size;
        powervalue = (powervalue * P) % Table_size;
    }
    return hashMap;
}

long long int *getHashMapSuffix(char *input, int len)
{
    long long int powervalue = P;
    long long int *hashMap = (long long int *)malloc(sizeof(long long int) * len);
    hashMap[len - 1] = (input[len - 1] - 'a' + 1) % Table_size;
    for (int i = len - 2; i >= 0; i--)
    {
        hashMap[i] = (hashMap[i + 1] + ((input[i] - 'a' + 1) * powervalue) % Table_size) % Table_size;
        powervalue = (powervalue * P) % Table_size;
    }
    return hashMap;
}

long long int *getPowerOfP(int n)
{
    long long int *pArray = (long long int *)malloc(sizeof(long long int) * n);
    pArray[0] = 1;
    for (int i = 1; i < n; i++)
    {
        pArray[i] = (pArray[i - 1] * P) % Table_size;
    }
    return pArray;
}

long long int negativeToPositive(long long int n)
{
    return (n < 0) ? Table_size + n : n;
}

void checkPalindromeAndPrint(long long int *prefix, long long int *suffix, long long int *powerOfP, int n, int l, int r)
{
    if (l == 0 && r == 0)
    {
        printf("YES\n");
        return;
    }
    int midl;
    int midr;
    if ((r + l) % 2 == 0)
    {
        midl = ((r + l) / 2) - 1;
        midr = midl + 2;
    }
    else
    {
        midl = (r + l) / 2;
        midr = midl + 1;
    }
    long long int leftPartHash;
    long long int rightPartHash;
    if (l == 0)
    {
        leftPartHash = prefix[midl];
    }
    else
    {
        leftPartHash = prefix[midl] - prefix[l - 1];
    }
    if (r == n - 1)
    {
        rightPartHash = suffix[midr];
    }
    else
    {
        rightPartHash = suffix[midr] - suffix[r + 1];
    }
    leftPartHash = negativeToPositive(leftPartHash);
    rightPartHash = negativeToPositive(rightPartHash);
    if (l > n - r - 1)
    {
        long long int multiplier = powerOfP[l + r - n + 1];
        rightPartHash = (rightPartHash * multiplier) % Table_size;
    }
    else if (l < n - r - 1)
    {
        long long int multiplier = powerOfP[n - r - l - 1];
        leftPartHash = (leftPartHash * multiplier) % Table_size;
    }
    if (leftPartHash == rightPartHash)
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }
}