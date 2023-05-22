#include "sort.h"

int main()
{
    int t;
    scanf("%d", &t);
    for (int v = 0; v < t; v++)
    {
        int n;
        scanf("%d", &n);
        char **inputStrings = (char **)malloc(sizeof(char *) * n);
        for (int i = 0; i < n; i++)
        {
            int temp;
            scanf("%d", &temp);
            inputStrings[i] = (char *)malloc(sizeof(char) * (temp + 1));
            for (int j = 0; j < temp; j++)
            {
                scanf(" %c", &inputStrings[i][j]);
            }
            inputStrings[i][temp] = '@';
        }

        stringList result = mergeSort(inputStrings, n);
        for (int i = 0; i < n; i++)
        {
            printString(result[i]);
        }
    }
}