#include<stdio.h>

void separate(int mainArr[],int subArr1[],int subArr2[]);

int main()
{
    int mainArr[20],subArr1[10],subArr2[10];
    printf("enter elements of the mainArray\n");
    for(int i=0;i<5;i++)
    {
        scanf("%d",&mainArr[i]);
    }
    separate(mainArr,subArr1,subArr2);
}

void separate(int mainArr[],int subArr1[],int subArr2[])
{
    int j=0,k=0;
    for(int i=0;i<5;i++)
    {
        if(mainArr[i] < 0)
        {
            subArr1[j] = mainArr[i] ;
            j++;
        }
        else{
            subArr2[k] = mainArr[i] ;
            k++;
        }
    }
    printf("The negative elements are : ");
    for(int i=0;i<j;i++)
    {
        printf("%d ",subArr1[i]);
    }
    printf("\nThe positive elements are : ");
    for(int i=0;i<k;i++)
    {
        printf("%d ",subArr2[i]);
    }
}