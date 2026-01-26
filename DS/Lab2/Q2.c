#include<stdio.h>
int main()
{
    char days[][100] = {"Sun","Mon","Tue","Wed","Thu","Fri","Sat"};
    char months[][120] = {"January","February","March","April","May","June","July","August","September","October","November","December"};
    int daysinMonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

    int month, year;
    printf("Enter month (1-12): ");
    scanf("%d", &month);
    printf("Enter year: ");
    scanf("%d", &year);

    if( year%4 ==0 )
    {
        if(year%100  == 0 && year%400 != 0)
            daysinMonth[1]= 28 ;
            else
            daysinMonth[1]= 29 ;
          
    }
    int totalDays=1;
    for(int i=2001;i<year;i++)
    {
        if(i%4 == 0)
        {
            if(i%100  == 0 && i%400 != 0)
            totalDays += 365 ;
            else
            totalDays += 366 ;
        }
        else{
            totalDays += 365 ;
        }
    }
    for(int i=1;i<month;i++)
    {
        totalDays += daysinMonth[i-1] ; 
    }
    int firstDay = (totalDays)%7 ;
    for(int i=0;i<7;i++)
    {
        printf("%s ",days[i]);
    }
    printf("\n");
    int j=0;
    for(;j<firstDay;j++)
    {
        printf("    ");
    }
    
    for(int i=1;i<=daysinMonth[month-1];i++)
    {
        printf("%3d ",i);
        if((i+j)%7 == 0)
        printf("\n");
    }
}