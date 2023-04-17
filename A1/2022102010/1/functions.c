#include "functions.h"

int ARR_LEN = 0;

void reverseString(char* str, int length)
{
    int start = 0;
    int end = length - 1;
    while (start < end)
    {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
    printf("%s\n", str);
}

int stringLength(char* str){
    int count = 0;
    for (int i=0;;i++){
        if (str[i] == '\0'){
            return count;
        }else{
            count++;
        }
    }
}


void addCount(char* str,int count, int* index){
    char typecastedstring[10];
    sprintf(typecastedstring,"%d",count);
    for (int j=0;j<stringLength(typecastedstring);j++){
        str[(*index)++] = typecastedstring[j];
    }
}

char* compressString(char* str, int length)
{
    char flag = str[0];
    char* resultString = (char *)malloc(sizeof(char)*(2*length+1));
    resultString[0] = str[0];
    int count = 1;
    int index = 1;
    for (int i=1;i<length;i++)
    {
        if (flag != str[i] ){
            addCount(resultString,count,&index);
            resultString[index++] = str[i];
            count = 1;
            flag = str[i];
        }
        else{
            count++;
        }
    }
    addCount(resultString,count,&index);
    resultString[index] = '\0';
    return resultString;
}

int* uniqueElements(int* arr,int length)
{
    int* flagArray = (int*)calloc(100001,sizeof(int));
    int* resultArray = (int*)malloc(sizeof(int)*length);
    int index = 0;
    for (int i=0;i<length;i++){
        if (flagArray[arr[i]]==0){
            resultArray[index++] = arr[i];
            flagArray[arr[i]] = 1;
        }
    }
    free(flagArray);
    ARR_LEN = index;
    int* result = (int*)realloc(resultArray,sizeof(int)*ARR_LEN);
    return result;
}

int** transpose(int** matrix, int NumRow, int NumCol)
{
    int** resultMatrix = (int**)malloc(sizeof(int *)*NumCol);
    for (int i=0;i<NumCol;i++){
        resultMatrix[i] = (int *)malloc(sizeof(int)*NumRow);
    }
    for (int i=0;i<NumRow;i++){
        for (int j=0;j<NumCol;j++){
            resultMatrix[j][i] = matrix[i][j];
        }
    }
    return resultMatrix;
}

int arrlenop3(){
    return ARR_LEN;
}
