#include<iostream>
#include<math.h>
using namespace std;

void print1(int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout << "* ";
        }
        cout <<"\n" ;
    }
}

void print2(int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0; j<=i;j++)
        {
            cout << "* " ;
        }
        cout << "\n" ;
    }
}

void print3(int n)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            cout << j << " " ;
        }
        cout << "\n" ;
    }
}

void print(int n)
{
    for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n - i; j++) {
                printf("%3s ", " ");
            }
            for (int j = 1; j <= i; j++) {
                // System.out.print(((int) Math.pow(2, j - 1)) + " ");
                printf("%3d ",(int)pow(2, j - 1));
            }
            for (int j = i - 2; j >= 0 && i != 1; j--) {
                printf("%3d ", (int)pow(2, j));
            }
            printf("\n");
        }
}

void print4(int n)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            cout<<i;
        }
        cout<<"\n" ;
    }
}

void print5(int n)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=n;j>=i;j--)
        {
            cout<<"*";
        }
        cout<<"\n";
    }
}

void print6(int n)
{
    for(int i=n;i>=1;i--)
    {
        for(int j=1;j<=i;j++)
        {
            cout<<j;
        }
        cout<<"\n";
    }
}

int main()
{
    int n;
    cout << "Enter n" <<"\n" ;
    cin >> n ;
    print1(n);
    print2(n);
    print3(n);
    print(n);
    print4(n); 
    print5(n); 
    print6(n);  
}
