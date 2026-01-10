#include<stdio.h>
int main()
{
    //ROW MAJOR ORDER
    int arr[5][5];
    int i,j;
    for(i=0;i<2;i++)
    {
        printf("Enter elements of row %d\n",i+1);
        for(j=0;j<3;j++)
        {
        scanf("%d",&arr[i][j]);
        }
    }
    printf("Array is given in ROW MAJOR as :\n");
    for(i=0;i<2;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%d ",arr[i][j]);
        }
    }
    printf("\n");
    printf("Array is given in COLUMN MAJOR as :\n");
     for(i=0;i<3;i++)
    {
        for(j=0;j<2;j++)
        {
            printf("%d ",arr[j][i]);
        }
    }
}
