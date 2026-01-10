//TO Calculate Max,Min,Average and perform Linear search.
#include<stdio.h>
int main()
{
    int num;
    printf("Enter number of elements :");
    scanf("%d",&num);
    int arr[num];
    int i,j;
    printf("Enter elements of array\n");
    for(i=0;i<num;i++)
    {
        scanf("%d",&arr[i]);
    }
    int max = arr[0],min = arr[1],sum=0;
    float avg;
    for(i=0;i<num;i++)
    {
        if(max<arr[i])        
            max = arr[i] ;
        if(min>arr[i])
            min = arr[i] ;
        sum = sum +arr[i] ;        
    }
    avg = sum / num ;
    printf("Max is %d and Min is %d,Average is %.2f\n",max,min,avg);
    int Snum,temp=0;
    printf("Enter a number to search if it is present in array or not\n");
    scanf("%d",&Snum);
    for(i=0;i<num;i++)
    {
        if(Snum == arr[i])
        {
            printf("Number is present");
            temp = 1;
            break;
        }
    }
    if(temp == 0)
    printf("Not found");
}