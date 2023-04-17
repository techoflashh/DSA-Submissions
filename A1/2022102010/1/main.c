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
            int n;
            scanf("%d", &n);
            char inputstr[n + 1];
            scanf("%s", inputstr);
            reverseString(inputstr, n);
        }
        else if(operation[4] == '2')
        {
            int n;
            scanf("%d",&n);
            char inputstr[n+1];
            scanf("%s",inputstr);
            char* result = compressString(inputstr,n);
            printf("%s\n",result);

            free(result);
        }
        else if(operation[4] == '3')
        {
            int n;
            scanf("%d",&n);
            int arr[n];
            for (int i=0;i<n;i++){
                scanf("%d",&arr[i]);
            }
            int* result = uniqueElements(arr,n);
            
            for (int i=0;i<arrlenop3();i++){
                printf("%d ",result[i]);
            }
            printf("\n");
            free(result);
        
        }
        else if (operation[4] == '4')
        {
            int R,C;
            scanf("%d %d",&R,&C);
            int** Matrix = (int**)malloc(sizeof(int *)*R);
            for (int i=0;i<R;i++){
                Matrix[i] = (int *)malloc(sizeof(int)*C);
            }
            for (int i=0;i<R;i++){
                for (int j=0;j<C;j++){
                    scanf("%d",&Matrix[i][j]);
                }
            }
            int** result = transpose(Matrix,R,C);

            for (int i=0;i<R;i++){
                free(Matrix[i]);
            }
            free(Matrix);

            for (int i=0;i<C;i++){
                for (int j=0;j<R;j++){
                    printf("%d ",result[i][j]);
                }
                printf("\n");
            }

            for (int i=0;i<C;i++){
                free(result[i]);
            }
            free(result);
        }
    }
}