#include<stdio.h>
#include<stdlib.h>

typedef struct graphStruct* Graph;
typedef struct node* ptrNode;
typedef struct HeapStruct *Heap;
typedef int Vertex;

struct graphStruct{
    int numberOfElements;
    ptrNode* Elements;  
};

struct node{
    Vertex vertexID;
    ptrNode Next;
};

struct HeapStruct
{
    int capacity;
    int size;
    int *Elements;
};

Heap initiallizeHeap(int capacity)
{
    Heap H = (Heap)malloc(sizeof(struct HeapStruct));
    H->capacity = capacity + 1;
    H->size = 1;
    H->Elements = (int *)malloc(sizeof(int) * H->capacity);
    H->Elements[0] = -1000001;
    return H;
}

void Insert(Heap H, int e)
{
    int i;
    for (i = H->size; H->Elements[i / 2] > e && i/2 !=0 ; i = i / 2)
    {
        H->Elements[i] = H->Elements[i / 2];
    }
    H->size++;
    H->Elements[i] = e;
}

int DeleteHead(Heap H)
{
    int returnValue = H->Elements[1];
    H->Elements[1] = H->Elements[--H->size];
    int temp;
    for (int i = 1; i * 2 < H->size; i = temp)
    {
        int left = i * 2;
        int right = i * 2 + 1;
        if (H->Elements[i] > H->Elements[left])
        {
            if (right < H->size)
            {
                if (H->Elements[right] > H->Elements[left])
                {
                    int temp2 = H->Elements[i];
                    H->Elements[i] = H->Elements[left];
                    H->Elements[left] = temp2;
                    temp = left;
                }
                else
                {
                    int temp2 = H->Elements[i];
                    H->Elements[i] = H->Elements[right];
                    H->Elements[right] = temp2;
                    temp = right;
                }
            }
            else
            {
                int temp2 = H->Elements[i];
                H->Elements[i] = H->Elements[left];
                H->Elements[left] = temp2;
                temp = left;
            }
        }
        else if (H->Elements[i] > H->Elements[right])
        {
            int temp2 = H->Elements[i];
            H->Elements[i] = H->Elements[right];
            H->Elements[right] = temp2;
            temp = right;
        }
        else
        {
            break;
        }
    }
    return returnValue;
}


Graph createGraph(int numberOfElements){
    Graph G = (Graph)malloc(sizeof(struct graphStruct));
    G->numberOfElements = numberOfElements;
    G->Elements = (ptrNode*)malloc(sizeof(ptrNode)*numberOfElements);
    for (int i=0;i<numberOfElements;i++){
        G->Elements[i] = (ptrNode)malloc(sizeof(struct node));
        G->Elements[i]->vertexID = i;
        G->Elements[i]->Next = NULL;
    }
    return G;
}

void InsertEdge(Graph G, Vertex u, Vertex v){
    ptrNode temp;
    temp = (ptrNode)malloc(sizeof(struct node));
    temp->vertexID = v;
    temp->Next = G->Elements[u]->Next;
    G->Elements[u]->Next = temp;
    temp = (ptrNode)malloc(sizeof(struct node));
    temp->vertexID = u;
    temp->Next = G->Elements[v]->Next;
    G->Elements[v]->Next = temp;
}

void DFS(Graph G,int* visited,Heap H){
    Vertex tempVertexId = DeleteHead(H);
    printf("%d ",tempVertexId+1);
    ptrNode tempVertex = G->Elements[tempVertexId];
    while (tempVertex->Next != NULL){
        tempVertexId = tempVertex->Next->vertexID;
        if (visited[tempVertexId] == 0){
            Insert(H,tempVertexId);
            visited[tempVertexId] = 1; 
        }
        tempVertex = tempVertex->Next;
    }
    if (H->size>1){
        DFS(G,visited,H);
    }
        
}

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    Graph G = createGraph(n);
    for (int i=0;i<m;i++){
        Vertex u,v;
        scanf("%d %d",&u,&v);
        InsertEdge(G,u-1,v-1);
    }
    int* visited = (int *)calloc(n,sizeof(int));
    Heap H = initiallizeHeap(n);
    Insert(H,0);
    visited[0] = 1;
    DFS(G,visited,H);
    return 0;
}