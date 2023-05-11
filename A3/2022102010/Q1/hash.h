#ifndef __HASH_H
#define __HASH_H

#include <stdio.h>
#include <stdlib.h>

#define P 33
#define Table_size 1009

typedef struct node *ptrNode;
typedef ptrNode* HashTable;

struct node
{
    char str[11];
    ptrNode next;
    ptrNode prev;
};

int stringLength(char* input);

int getHash(char *input);

int compareTwoStrings(char *a, char *b);

HashTable createHashtable(int table_size);

void insertinLL(ptrNode n, char *str);

void insert(HashTable ht, char *str);

void findAndPrint(HashTable ht,char* str);

#endif