#include "functions.h"

int main()
{
    Queue Q = initiallizeQueue();
    int T;
    scanf("%d", &T);
    for (int v = 0; v < T; v++)
    {
        char operations[6];
        scanf("%s", operations);
        if (operations[4] == '1')
        {
            int val;
            scanf("%d", &val);
            Push(Q, val);
        }
        else if (operations[4] == '2')
        {
            printf("%d\n", Pop(Q));
        }
        else if (operations[4] == '3')
        {
            int val;
            scanf("%d", &val);
            Inject(Q, val);
        }
        else if (operations[4] == '4')
        {
            printf("%d\n", popRear(Q));
        }
        else if (operations[4] == '5')
        {
            Print(Q);
        }
        else if (operations[4] == '6')
        {
            PrintReverse(Q);
        }
        else if (operations[4] == '7')
        {
            int pos;
            scanf("%d", &pos);
            printf("%d\n", findElem(Q, pos));
        }
        else if (operations[4] == '8')
        {
            int k;
            scanf("%d", &k);
            removeKElems(Q, k);
        }
    }
    return 0;
}