#include "hash.h"

int stringLength(char* input){
    int len = 0;
    while (input[len]!='\0'){
        len++;
    }
    return len;
}

int getHash(char *input)
{
    int sum = 0;
    int *freq1 = (int *)calloc(26, sizeof(int));
    for (int i = 0; i < stringLength(input); i++)
    {
        freq1[input[i] - 'a']++;
    }
    
    for (int i=25;i>=0;i--){
        while (freq1[i]){
            sum = ((sum*P)%Table_size + i)%Table_size;
            freq1[i]--;
        }
        
    }
    free(freq1);
    return sum % Table_size;
}

int compareTwoStrings(char *a, char *b)
{
    int *freq1 = (int *)calloc(26, sizeof(int));
    int *freq2 = (int *)calloc(26, sizeof(int));
    for (int i = 0; i < stringLength(a); i++)
    {
        freq1[a[i] - 'a']++;
    }
    for (int i = 0; i < stringLength(b); i++)
    {
        freq2[b[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++)
    {
        if (freq1[i] != freq2[i])
        {
            return 0;
        }
    }
    free(freq1);
    free(freq2);
    return 1;
}


HashTable createHashtable(int table_size)
{
    HashTable ht = (HashTable)malloc(sizeof(ptrNode) * table_size);
    for (int i = 0; i < table_size; i++)
    {
        ht[i] = (ptrNode)malloc(sizeof(struct node));
        ht[i]->next = ht[i];
        ht[i]->prev = ht[i];
    }
    return ht;
}

void insertinLL(ptrNode n, char *str)
{
    ptrNode temp = (ptrNode)malloc(sizeof(struct node));
    for (int i = 0; i < 11; i++)
    {
        temp->str[i] = str[i];
    }

    temp->next = n;
    temp->prev = n->prev;
    n->prev->next = temp;
    n->prev = temp;
}

void insert(HashTable ht, char *str)
{
    insertinLL(ht[getHash(str)], str);
}

void findAndPrint(HashTable ht,char* str){
    int key = getHash(str);
    int flag = 0;
    ptrNode temp = ht[key];
    if (temp->next != temp){
        ptrNode temp2 = temp->next;
        while (temp2!=temp){
            if (compareTwoStrings(temp2->str,str)){
                flag = 1;
                printf("%s ",temp2->str);
            }
            temp2 = temp2->next;
        }
        printf("\n");
    }
    if (temp->next == temp || flag==0){
        printf("-1\n");
    }
}
