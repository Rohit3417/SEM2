#include<stdio.h>
int main()
{
    int arr[3][3];
    int i,j;
    int *base = &arr[0][0] ;
    int size = sizeof(int) ; 
    printf("Base address = %d\n",base);
    printf("Enter the value of i and j in 'arr[i][j]' to check the memory address\n");
    scanf("%d%d",&i,&j);

    //Row major formula
    int *loc;
    loc = (void*)base + ((i)*3 + (j))*size ;
    printf("Location by RMO formula is %d\n",loc);
    

    //Column major formula;
    int *loc2 = (void*)base + ((j)*3 + i)*size ;
    printf("Location by CMO formula is %d\n",loc2);
    printf("Actual location is %d",&arr[i][j]);

}