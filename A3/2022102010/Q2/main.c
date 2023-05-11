#include "hash.h"

int main()
{
    int n, q;
    scanf("%d %d", &n, &q);
    char temp[n + 1];
    scanf("%s", temp);
    long long int *prefix = getHashMapPrefix(temp, n);
    long long int *suffix = getHashMapSuffix(temp, n);
    long long int *powerOfP = getPowerOfP(n);
    int l, r;
    for (int i = 0; i < q; i++)
    {
        scanf("%d %d", &l, &r);
        l--;
        r--;
        checkPalindromeAndPrint(prefix, suffix, powerOfP, n, l, r);
    }
}