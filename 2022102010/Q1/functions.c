#include "functions.h"

int flag = 0;

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

int returnFlag(){
    return flag;
}

Stack init()
{
    Stack S = (Stack)malloc(sizeof(struct head));
    S->noOfElements = 0;
    S->Top = NULL;
    return S;
}

int isEmpty(Stack S)
{
    return (S->noOfElements == 0);
}

void push(Stack S, char e)
{
    ptrNode nodeToPush = (ptrNode)malloc(sizeof(struct Node));
    nodeToPush->val = e;
    nodeToPush->Next = S->Top;
    S->Top = nodeToPush;
    S->noOfElements++;
}

char pop(Stack S)
{
    if (isEmpty(S) != 1)
    {
        ptrNode nodeToPop = S->Top;
        S->Top = nodeToPop->Next;
        S->noOfElements--;
        char returnValue = nodeToPop->val;
        free(nodeToPop);
        return returnValue;
    }
}

int isBalanced(char *A, int lenth)
{
    Stack S = init();
    flag = 0;
    for (int i = 0; i < lenth; i++)
    {
        if (A[i] == '(' || A[i] == '{' || A[i] == '[')
        {
            push(S, A[i]);
            flag = 1;
        }
        else if (A[i] == ')' || A[i] == '}' || A[i] == ']')
        {
            char tempChar = pop(S);
            if (A[i] == ')')
            {
                if (tempChar != '(')
                {
                    return 0;
                }
            }
            else if (A[i] == '}')
            {
                if (tempChar != '{')
                {
                    return 0;
                }
            }
            else
            {
                if (tempChar != '[')
                {
                    return 0;
                }
            }
        }
    }
    if (isEmpty(S) && flag == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isPalindromic(char *A, int length)
{
    Stack(S) = init();
    for (int i = 0; i < length / 2; i++)
    {
        push(S, A[i]);
    }
    int startLength = (length % 2 == 0) ? length / 2 : (length / 2) + 1;
    for (int i = startLength; i < length; i++)
    {
        if (pop(S) != A[i])
        {
            return 0;
        }
    }
    if (isEmpty(S))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}