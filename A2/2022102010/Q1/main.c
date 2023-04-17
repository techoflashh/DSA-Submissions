#include "functions.h"

int main()
{
    int T;
    scanf("%d", &T);
    char inputString[10001];
    for (int v = 0; v < T; v++)
    {
        scanf("%s", inputString);
        if (isBalanced(inputString, stringLength(inputString)))
        {
            printf("Balanced\n");
        }
        else if (returnFlag() == 0 && isPalindromic(inputString, stringLength(inputString)))
        {
            printf("Palindromic\n");
        }
        else
        {
            printf("-1\n");
        }
    }
    return 0;
}