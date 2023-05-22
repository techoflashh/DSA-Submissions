#include "sort.h"

int main(){
    int t;
    scanf("%d",&t);
    for (int v=0;v<t;v++){
        int n,k;
        scanf("%d %d",&n,&k);
        Heap H = initiallizeHeap(n);
        int temp;
        for (int i=0;i<n;i++){
            scanf("%d",&temp);
            Insert(H,temp);
        }
        printf("%lld\n",maximumHappiness(H,k));
    }
    return 0;
}