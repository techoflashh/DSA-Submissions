#include "functions.h"

int main(){
    PtrNode L = InitializeLinkedList();
    int T;
    scanf("%d", &T);
    
    for (int v = 0; v < T; v++)
    {
        char operation[6];
        scanf("%s", operation);
        if (operation[4] == '1')
        {
            int element;
            scanf("%d",&element);
            Insert(L,element);
        }
        else if(operation[4] == '2')
        {
            int element;
            scanf("%d",&element);
            Find(L,element);
        }
        else if(operation[4] == '3')
        {
           Print(L);
        }
    }
    
    return 0;
}