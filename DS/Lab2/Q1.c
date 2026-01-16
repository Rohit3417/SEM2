#include<stdio.h>
#include<stdlib.h>

void printArr(int mainArr[],int count);
void insertAtEnd(int mainArr[],int count);
void insertAtBeg(int mainArr[],int count);
void insertAtpos(int mainArr[],int count);
void deleteAtEnd(int mainArr[],int count);
void deleteAtBeg(int mainArr[],int count);
void deleteAtpos(int mainArr[],int count);
void reverse(int mainArr[],int count);
void reversewtemp(int mainArr[],int count);

int main()
{
    int mainArr[20],count=0;
    printf("Enter the elements of main-array\n");
    for(int i=0;i<5;i++)
    {
        scanf("%d",&mainArr[i]);
        count++;
    }
    printArr(mainArr,count);
    insertAtEnd(mainArr,count);
    count++;
    printArr(mainArr,count);
    insertAtBeg(mainArr,count);
    count++;
    printArr(mainArr,count);
    insertAtpos(mainArr,count);
    count++;
    printArr(mainArr,count);
    deleteAtEnd(mainArr,count);
    count--;
    printArr(mainArr,count);
    deleteAtBeg(mainArr,count);
    count--;
    printArr(mainArr,count);
    deleteAtpos(mainArr,count);
    count--;
    printArr(mainArr,count);
    printf("\nReversing the array\n");
    reverse(mainArr,count);
    printArr(mainArr,count);
    reversewtemp(mainArr,count);
    printArr(mainArr,count);
}

void printArr(int mainArr[],int count)
{
    for(int i=0;i<count;i++)
    {
        printf("%d ",mainArr[i]);
    }
}

void insertAtEnd(int mainArr[],int count)
{
    int e1;
    printf("\nEnter an element to insert at the end of the string\n");
    scanf("%d",&e1);
    mainArr[count] = e1 ;
    
}

void insertAtBeg(int mainArr[],int count)
{
    int e1;
    printf("\nEnter an element to insert at the beginning of the string\n");
    scanf("%d",&e1);
    for(int i=count-1;i>=0;i--)
    {
        mainArr[i+1] = mainArr[i] ;
    }
    mainArr[0] = e1 ;
}

void insertAtpos(int mainArr[],int count)
{
    int e1,pos;
    printf("\nEnter an element to insert at the end of the string\n");
    scanf("%d",&e1);
    printf("Enter a position to insert at\n");
    scanf("%d",&pos);
    for(int i=count-1;i>=pos-1;i--)
    {
        mainArr[i+1] = mainArr[i] ;
    }
    mainArr[pos-1] = e1 ;
}

void deleteAtEnd(int mainArr[],int count)
{
    printf("\nDeleting at the end :");
    free((void*)mainArr[count-1]);
    printf("\n");
}

void deleteAtBeg(int mainArr[],int count)
{
    printf("\nDeleting at the beginning :");
    for(int i=0;i<count;i++)
    {
        mainArr[i] = mainArr[i+1];
    }
    free((void*)mainArr[count-1]);
    printf("\n");
}

void deleteAtpos(int mainArr[],int count)
{
    int pos;
    printf("\nEnter the position\n");
    scanf("%d",&pos);
    printf("\nDeleting at the given position :");
    for(int i=pos-1;i<count;i++)
    {
        mainArr[i] = mainArr[i+1] ;
    }
    free((void*)mainArr[count-1]);
    printf("\n");
}

void reverse(int mainArr[],int count)
{
    int temp;
    for(int i=0;i<count/2;i++)
    {
        temp = mainArr[i] ;
        mainArr[i] = mainArr[count-1-i];
        mainArr[count-1-i] = temp ;
    }
}

void reversewtemp(int mainArr[],int count)
{
    printf("\nRe-reversing the array\n");
    for(int i=0;i<count/2;i++)
    {
        mainArr[i] = mainArr[i] + mainArr[count-1-i] ;
        mainArr[count-1-i] = mainArr[i] - mainArr[count-1-i] ;
        mainArr[i] = mainArr[i] - mainArr[count-1-i] ;
    }
}