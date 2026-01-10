/*to declare primitive and nonprimitive data types and display the
values of variables, their memory addresses, and their sizes for similar and dissimilar
data types.*/
#include<stdio.h>
int main()
{
    //PRIMITIVE Data Types
    int a=1;
    float b=2;
    double c=3;
    char d='A' ;
    //NON-PRIMITIVE Data Types
    int arr[5] = {1,2,3,4,5};
    char str[] = "Hello" ;

    printf("PRIMITIVE Type\n");

    printf("VALUES : integer = %d,float = %.2f,double = %.4lf,character = %c\n",a,b,c,d);
    printf("ADDRESS : integer = %d,float = %d,double = %d,character = %d\n",&a,&b,&c,&d);
    printf("SIZE : integer = %d,float = %d,double = %d,character = %d\n",sizeof(a),sizeof(b),sizeof(c),sizeof(d));

    printf("NON-PRIMITIVE Type\n");

    printf("Array elements : ");
    for(int i=0;i<5;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("|| Array ADDRESS : ");
    for(int i=0;i<5;i++)
    {
        printf("%d ",&arr[i]);
    }
    printf("|| Size of array %d\n",sizeof(arr));
    printf("String is %s || ADDRESS is %d || string SIZE %d(Counting null character)\n",str,&str,sizeof(str));


}