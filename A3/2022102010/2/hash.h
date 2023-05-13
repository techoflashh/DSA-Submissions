#ifndef __HASH_H
#define __HASH_H

#include <stdio.h>
#include <stdlib.h>

#define P 31
#define Table_size 1000000007

long long int *getHashMapPrefix(char *input, int len);

long long int *getHashMapSuffix(char *input, int len);

long long int *getPowerOfP(int n);

long long int negativeToPositive(long long int n);

void checkPalindromeAndPrint(long long int *prefix, long long int *suffix, long long int *powerOfP, int n, int l, int r);

#endif