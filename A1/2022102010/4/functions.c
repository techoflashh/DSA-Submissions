#include "functions.h"

int LEN_LL = 0;

PtrNode initializeLinkedList()
{
    PtrNode L = (PtrNode)malloc(sizeof(struct Node));
    L->NextNode = L;
    L->PrevNode = L;
    return L;
}

sMatrix initializeMatrix()
{
    sMatrix S = (sMatrix)malloc(sizeof(struct Matrix));
    S->Next = S;
    S->Prev = S;
    return S;
}

PtrNode2 initializeAddLL()
{
    PtrNode2 L = (PtrNode2)malloc(sizeof(struct structForAdd));
    L->Next = L;
    L->Prev = L;
    return L;
}

void InsertElementInRow(PtrNode Head, int col, int val)
{
    PtrNode p = (PtrNode)malloc(sizeof(struct Node));
    p->val = val;
    p->col = col;
    p->NextNode = Head;
    Head->PrevNode->NextNode = p;
    p->PrevNode = Head->PrevNode;
    Head->PrevNode = p;
}

void insertElementsForTRA(PtrNode2 Head, int row, int col, int val)
{
    PtrNode2 p = (PtrNode2)malloc(sizeof(struct structForAdd));
    p->col = col;
    p->row = row;
    p->val = val;
    p->Next = Head->Next;
    p->Prev = Head;
    Head->Next->Prev = p;
    Head->Next = p;
}

void insertElementsForADD(PtrNode2 Head, int row, int col, int val)
{
    PtrNode2 p = (PtrNode2)malloc(sizeof(struct structForAdd));
    p->col = col;
    p->row = row;
    p->val = val;
    p->Next = Head;
    p->Prev = Head->Prev;
    Head->Prev->Next = p;
    Head->Prev = p;
}

void InsertRow(sMatrix Head, int row, PtrNode rowHead)
{
    sMatrix S = (sMatrix)malloc(sizeof(struct Matrix));
    S->row = row;
    S->HeadofRow = rowHead;
    S->Next = Head;
    Head->Prev->Next = S;
    S->Prev = Head->Prev;
    Head->Prev = S;
}

PtrNode2 splitInTwo(PtrNode2 listHead)
{
    PtrNode2 firstHalf = listHead;
    PtrNode2 secondHalf = listHead;
    while (secondHalf->Next != NULL && secondHalf->Next->Next != NULL)
    {
        firstHalf = firstHalf->Next;
        secondHalf = secondHalf->Next->Next;
    }
    PtrNode2 HeadofSecondHalf = firstHalf->Next;
    firstHalf->Next = NULL;
    return HeadofSecondHalf;
}

PtrNode2 mergeTwoHalves(PtrNode2 firstHalf, PtrNode2 secondHalf)
{
    if (firstHalf == NULL)
    {
        return secondHalf;
    }
    if (secondHalf == NULL)
    {
        return firstHalf;
    }
    if (firstHalf->row < secondHalf->row)
    {
        firstHalf->Next = mergeTwoHalves(firstHalf->Next, secondHalf);
        firstHalf->Next->Prev = firstHalf;
        firstHalf->Prev = NULL;
        return firstHalf;
    }
    else
    {
        secondHalf->Next = mergeTwoHalves(firstHalf, secondHalf->Next);
        secondHalf->Next->Prev = secondHalf;
        secondHalf->Prev = NULL;
        return secondHalf;
    }
}

PtrNode2 mergeSort(PtrNode2 listHead)
{
    if (listHead == NULL || listHead->Next == NULL)
    {
        return listHead;
    }
    PtrNode2 secondHalf = splitInTwo(listHead);
    PtrNode2 firstHalf = mergeSort(listHead);
    secondHalf = mergeSort(secondHalf);
    return mergeTwoHalves(firstHalf, secondHalf);
}

sMatrix findRow(sMatrix S, int row)
{
    sMatrix HeadCopy = S;
    HeadCopy = HeadCopy->Next;
    sMatrix temp = S;
    while (HeadCopy->row != row)
    {
        HeadCopy = HeadCopy->Next;
        temp = temp->Next;
        if (HeadCopy == S)
        {
            return NULL;
        }
    }
    return HeadCopy;
}

void PrintADD(PtrNode2 Head)
{
    PtrNode2 HeadCopy = Head;
    while (HeadCopy->Next != Head)
    {
        HeadCopy = HeadCopy->Next;
        printf("%d %d %d\n", HeadCopy->row, HeadCopy->col, HeadCopy->val);
    }
}

void PrintMatrix(sMatrix Head)
{
    sMatrix HeadCopy = Head;
    while (HeadCopy->Next != Head)
    {
        HeadCopy = HeadCopy->Next;
        PtrNode RowCopy = HeadCopy->HeadofRow;
        while (RowCopy->NextNode != HeadCopy->HeadofRow)
        {
            RowCopy = RowCopy->NextNode;
            printf("%d %d %d\n", HeadCopy->row, RowCopy->col, RowCopy->val);
        }
    }
}

sMatrix TRA(PtrNode2 listHead)
{
    sMatrix result = initializeMatrix();
    listHead->Prev->Next = NULL;
    listHead = listHead->Next;
    listHead->Prev = NULL;
    listHead = mergeSort(listHead);
    int rowCache = -1;
    PtrNode rowHeadCache;
    while (listHead != NULL)
    {

        if (rowCache != listHead->row)
        {
            rowCache = listHead->row;
            PtrNode rowToInsert = initializeLinkedList();
            rowHeadCache = rowToInsert;
            InsertRow(result, rowCache, rowHeadCache);
        }
        InsertElementInRow(rowHeadCache, listHead->col, listHead->val);
        listHead = listHead->Next;
    }
    return result;
}

PtrNode2 ADD(PtrNode2 S1, PtrNode2 S2)
{
    LEN_LL = 0;
    PtrNode2 result = initializeAddLL();
    PtrNode2 HeadCopy1 = S1->Next;
    PtrNode2 HeadCopy2 = S2->Next;
    while (HeadCopy1 !=S1 || HeadCopy2 != S2){
        if (HeadCopy1 == S1){
            while (HeadCopy2 != S2)
            {
                insertElementsForADD(result,HeadCopy2->row,HeadCopy2->col,HeadCopy2->val);
                LEN_LL++;
                HeadCopy2 = HeadCopy2->Next;
            }
            break;
        }else if (HeadCopy2 == S2){
            while (HeadCopy1 != S1){
                insertElementsForADD(result,HeadCopy1->row,HeadCopy1->col,HeadCopy1->val);
                LEN_LL++;
                HeadCopy1 = HeadCopy1->Next;
            }
            break;
        }

        int row1 = HeadCopy1->row;
        int row2 = HeadCopy2->row;
        int col1 = HeadCopy1->col;
        int col2 = HeadCopy2->col;

        if (row1 < row2){
            insertElementsForADD(result,HeadCopy1->row,HeadCopy1->col,HeadCopy1->val);
            LEN_LL++;
            HeadCopy1 = HeadCopy1->Next;
        }else if(row2 < row1){
            insertElementsForADD(result,HeadCopy2->row,HeadCopy2->col,HeadCopy2->val);
            LEN_LL++;
            HeadCopy2 = HeadCopy2->Next;
        }else {
            if (col1<col2){
                insertElementsForADD(result,HeadCopy1->row,HeadCopy1->col,HeadCopy1->val);
                LEN_LL++;
                HeadCopy1 = HeadCopy1->Next;
            }
            else if(col2<col1){
                insertElementsForADD(result,HeadCopy2->row,HeadCopy2->col,HeadCopy2->val);
                LEN_LL++;
                HeadCopy2 = HeadCopy2->Next;
            }
            else{
                int sum = HeadCopy1->val + HeadCopy2->val;
                if (sum !=0){
                    insertElementsForADD(result,HeadCopy2->row,HeadCopy2->col,sum);
                    LEN_LL++;
                }
                HeadCopy2 = HeadCopy2->Next;
                HeadCopy1 = HeadCopy1->Next;
            }
        }
    }
    return result;
}

sMatrix MUL(sMatrix S1, PtrNode2 S)
{
    LEN_LL = 0;
    sMatrix result = initializeMatrix();
    sMatrix MatrixHead1 = S1;
    MatrixHead1 = MatrixHead1->Next;
    sMatrix S2 = TRA(S);
    while (MatrixHead1 != S1)
    {
        int row = MatrixHead1->row;
        sMatrix MatrixHead2 = S2;
        MatrixHead2 = MatrixHead2->Next;
        sMatrix tempResultRow = findRow(result, row);
        PtrNode tempRowtoPassed;
        if (tempResultRow == NULL || tempResultRow == result)
        {
            PtrNode tempResultRow = initializeLinkedList();
            InsertRow(result, row, tempResultRow);
            tempRowtoPassed = tempResultRow;
        }
        else
        {
            tempRowtoPassed = tempResultRow->HeadofRow;
        }
        while (MatrixHead2 != S2)
        {
            int col = MatrixHead2->row;
            PtrNode tempRowHead1 = MatrixHead1->HeadofRow;
            tempRowHead1 = tempRowHead1->NextNode;
            PtrNode tempRowHead2 = MatrixHead2->HeadofRow;
            tempRowHead2 = tempRowHead2->NextNode;
            int tempProduct = 0;
            while (tempRowHead1 != MatrixHead1->HeadofRow && tempRowHead2 != MatrixHead2->HeadofRow)
            {
                int col1 = tempRowHead1->col;
                int col2 = tempRowHead2->col;
                if (col1 == col2)
                {
                    tempProduct += tempRowHead1->val * tempRowHead2->val;
                    tempRowHead1 = tempRowHead1->NextNode;
                    tempRowHead2 = tempRowHead2->NextNode;
                }
                else if (col2 < col1)
                {
                    tempRowHead2 = tempRowHead2->NextNode;
                }
                else
                {
                    tempRowHead1 = tempRowHead1->NextNode;
                }
            }

            if (tempProduct != 0)
            {
                InsertElementInRow(tempRowtoPassed, col, tempProduct);
                LEN_LL++;
            }
            MatrixHead2 = MatrixHead2->Next;
        }
        MatrixHead1 = MatrixHead1->Next;
    }
    return result;
}

int lenLL()
{
    return LEN_LL;
}
