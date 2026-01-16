#include<stdio.h>

void copyArr(int mainArr[],int subArr1[],int count);
void printArr(int mainArr[],int count);
void sort(int mainArr[],int count);
int sumwrecursion(int mainArr[],int count);
int sumurecursion(int mainArr[],int count);
void search(int mainArr[],int count);
void seperate(int mainArr[],int count,int subArr1[],int subArr2[]);

int main()
{
    int mainArr[20],subArr1[10],subArr2[10],countofsub1=0,countofsub2=0;
    printf("Enter elements of subArray 1\n");
    for(int i=0;i<5;i++)
    {
        scanf("%d",&subArr1[i]);
        countofsub1++;
    }
    printf("Enter elements of subArray 2\n");
    for(int i=0;i<5;i++)
    {
        scanf("%d",&subArr2[i]);
        countofsub2++;
    }
    int Tcount = countofsub1 + countofsub2;
    copyArr(mainArr,subArr1,countofsub1);
    printf("Sub-Array 1 is : ");
    printArr(subArr1,countofsub1);
    printf("\nMainArray is : ");
    printArr(mainArr,countofsub1);
    printf("\n");
    for(int i=countofsub1;i<Tcount;i++)
    {
        mainArr[i] = subArr2[i-countofsub1];
    }
    sort(mainArr,Tcount);
    printf("Sorted and merged main-Array is : ");
    printArr(mainArr,Tcount);
    printf("\nSum of elements of main-array is %d\n",sumwrecursion(mainArr,Tcount));
    printf("Sum of elements of main-array using recursion method is %d\n",sumwrecursion(mainArr,Tcount));
    search(mainArr,Tcount);
    seperate(mainArr,Tcount,subArr1,subArr2);
    printf("SubArray1 with even no. is : ");
    printArr(subArr1,countofsub1);
    printf("\n");
    printf("SubArray2 with odd no. is : ");
    printArr(subArr2,countofsub2);
}

void copyArr(int mainArr[],int subArr1[],int countofsub1)
{
    for(int i=0;i<countofsub1;i++)
    {
        mainArr[i] = subArr1[i] ;
    }
}

void printArr(int mainArr[],int count)
{
    for(int i=0;i<count;i++)
    {
        printf("%d ",mainArr[i]);
    }
}

void sort(int mainArr[],int count)
{
    int temp;
    for(int i=0;i<count;i++)
    {
        for(int j=0;j<count;j++)
        {
            if(mainArr[i]<mainArr[j])
            {
                temp = mainArr[i];
                mainArr[i] = mainArr[j] ;
                mainArr[j] = temp ;
            }
        }
    }
}

int sumwrecursion(int mainArr[],int count)
{
    int sum = 0 ;
    for(int i=0;i<count;i++)
    {
        sum += mainArr[i] ;
    }
    return sum;
}

int sumurecursion(int mainArr[],int count)
{
    if(count < 0)
    {
        return mainArr[0] ;
    }
    else{
        return mainArr[count-1] + sumurecursion(mainArr,count-1) ;
    }   
}

void search(int mainArr[],int count)
{
    int e1,temp=0;
    printf("Enter an element to search in the main-Array\n");
    scanf("%d",&e1);
    for(int i=0;i<count;i++)
    {
        if(e1 == mainArr[i])
        {
            printf("Element found at position %d\n",i+1);
            temp=1;
            break;
        }
    }
    if(temp==0)
    printf("Element not found in the main-array\n");
}

void seperate(int mainArr[],int count,int subArr1[],int subArr2[])
{
    int j=0,k=0;
    for(int i=0;i<count;i++)
    {
        if(mainArr[i]%2 == 0)
        {
            subArr1[j] = mainArr[i] ;
            j++;
        }
        else{
            subArr2[k] = mainArr[i] ;
            k++;
        }
    }
}