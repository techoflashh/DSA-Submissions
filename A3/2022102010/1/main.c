#include "hash.h"

int main()
{
    HashTable ht = createHashtable(Table_size);
    int n, q;
    scanf("%d %d", &n, &q);

    char temp[11];
    for (int i = 0; i < n; i++)
    {
        scanf("%s", temp);
        insert(ht, temp);
    }
    for (int i=0;i< q;i++){
        scanf("%s",temp);
        findAndPrint(ht,temp);
    }
}