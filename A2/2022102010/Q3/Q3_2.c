#include<stdio.h>
#include<stdlib.h>

typedef struct TreeNode* Tree;

struct TreeNode
{
    int key;
    int index;
    Tree leftChild;
    Tree rightChild;
};

typedef struct Head *Queue;
typedef struct Node *queueNodePtr;

struct Head
{
    int numOfElements;
    queueNodePtr front;
    queueNodePtr rear;
};

struct Node
{
    Tree val;
    queueNodePtr next;
};

Queue initiallizeQueue()
{
    Queue Q = (Queue)malloc(sizeof(struct Head));
    Q->numOfElements = 0;
    Q->rear = NULL;
    Q->front = NULL;
    return Q;
}

Tree makeNode(int element,int index){
    Tree T = (Tree)malloc(sizeof(struct TreeNode));
    T->key = element;
    T->index  = index;
    T->leftChild = NULL;
    T->rightChild = NULL;
    return T;
}

Tree Insert(Tree T,int element,int index){
    if (T==NULL){
        T = makeNode(element,index);
    }else if(index<T->index){
        T->leftChild  = Insert(T->leftChild,element,index);
    }else if(index>T->index){
        T->rightChild = Insert(T->rightChild,element,index);
    }
    return T;
}

void Push(Queue head, Tree val)
{
    queueNodePtr nodeToInsert = (queueNodePtr)malloc(sizeof(struct Node));
    nodeToInsert->val = val;
    if (head->numOfElements == 0)
    {
        head->front = nodeToInsert;
        head->rear = nodeToInsert;
        head->front->next = head->rear;
        head->rear->next = head->front;
    }
    else
    {
        nodeToInsert->next = head->front;
        head->rear->next = nodeToInsert;
        head->rear = nodeToInsert;
    }
    head->numOfElements++;
}

Tree Pop(Queue head)
{
    Tree returnValue;
    if (head->numOfElements == 0)
    {
        returnValue = NULL;
    }
    else if (head->numOfElements > 1)
    {
        queueNodePtr nodeToPop = head->front;
        head->rear->next = head->front->next;
        head->front = nodeToPop->next;
        returnValue = nodeToPop->val;
        head->numOfElements--;
        free(nodeToPop);
    }
    else
    {
        returnValue = head->front->val;
        free(head->front);
        head->front = NULL;
        head->rear = NULL;
        head->numOfElements--;
    }
    return returnValue;
}

void printLevelOrder(Tree T)
{
    Queue Q = initiallizeQueue();
    Push(Q,T);
    while (Q->numOfElements != 0)
    {
        Tree temp = Pop(Q);
        if (temp->leftChild != NULL && temp->rightChild != NULL)
        {
            Push(Q, temp->leftChild);
            Push(Q, temp->rightChild);
        }
        else if (temp->leftChild != NULL)
        {
            Push(Q, temp->leftChild);
        }
        else if (temp->rightChild != NULL)
        {
            Push(Q, temp->rightChild);
        }
        printf("%d ", temp->key);
    }
}

int main(){
    int t;
    scanf("%d",&t);
    for (int v=0;v<t;v++){
        int N;
        scanf("%d",&N);
        Tree T = NULL;
        int inOrder[N];
        int preOrder[N];
        for (int i=0;i<N;i++){
            scanf("%d",&inOrder[i]);
        }
        for (int i=0;i<N;i++){
            scanf("%d",&preOrder[i]);
        }

        for (int i=0;i<N;i++){
            for (int j=0;j<N;j++){
                if (preOrder[i]==inOrder[j]){
                   T = Insert(T,preOrder[i],j);
                }
            }
        }
        printLevelOrder(T);
        printf("\n");
    }
}