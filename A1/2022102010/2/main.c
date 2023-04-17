#include "functions.h"

int main()
{
    int T;
    scanf("%d", &T);
    for (int v = 0; v < T; v++)
    {
        char operation[6];
        scanf("%s", operation);
        if (operation[4] == '1')
        {
            int n1, n2;
            scanf("%d %d", &n1, &n2);
            int arr1[n1], arr2[n2];
            for (int i = 0; i < n1; i++)
            {
                scanf("%d", &arr1[i]);
            }
            for (int i = 0; i < n2; i++)
            {
                scanf("%d", &arr2[i]);
            }
            int *result = intersectionArray(arr1, arr2, n1, n2);
            for (int i = 0;i<arrlenop1(); i++)
            {
                printf("%d ", result[i]);
            }
            printf("\n");
            
        }
        else if (operation[4] == '2')
        {   int n;
            scanf("%d",&n);
            char inputstr[n+1];
            scanf("%s", inputstr);
            char inputchar;
            scanf(" %c", &inputchar);
            int result = countCharOccurrences(inputstr,n, inputchar);
            printf("%d\n", result);
        }
        else if (operation[4] == '3')
        {   
            int n;
            scanf("%d",&n);
            char inputstr[n+1];
            scanf("%s", inputstr);
            char result = findFirstNonRepeatingChar(inputstr,n);
            if (result!='@')
                printf("%c\n", result);
            else
                printf("%d\n",-1);
        }
        else if (operation[4] == '4')
        {
            int n;
            scanf("%d", &n);
            char **strs = (char **)malloc(sizeof(char *) * n);
            for (int i = 0; i < n; i++)
            {
                strs[i] = (char *)malloc(sizeof(char) * 101);
            }
            int maxlen = -1;
            for (int i = 0; i < n; i++)
            {
                int temp;
                scanf("%d %s",&temp,strs[i]);
                if (temp > maxlen)
                {
                    maxlen = temp;
                }
            }
            char *result = findLongestCommonPrefix(strs, n, maxlen);
            printf("%s\n", result);
        }
        else if (operation[4] == '5'){
            int n;
            scanf("%d",&n);
            int inputarray[n];
            for (int i=0;i<n;i++){
                scanf("%d",&inputarray[i]);
            }
            int * result = maxMin(inputarray,n);
            for (int i = 0;i<arrlenop5(); i++)
            {
                printf("%d ", result[i]);
            }
            printf("\n");
        }
        else if (operation[4] == '6'){
            int n,m;
            scanf("%d %d",&n,&m);
            char str[n];
            char substr[m];
            scanf("%s",str);
            scanf("%s",substr);
            char* result = removeSubstring(str,n,substr,m);
            printf("%s\n",result);
        }
    }
}

