#include<iostream>
using namespace std;
void print1(int n)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n-i;j++)
        {
            cout<<" ";
        }
        for(int j=1;j<=(2*i-1);j++)
        {
            cout<<"*";
        }
        
        cout<<"\n";
    }
}

void print2(int n)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<i;j++)
        {
            cout<<"_";
        }
        for(int j=1;j>=0;j--)
        {
            cout<<"*";
        }
        cout<<"\n";
    }
}

int main()
{
    int n;
    printf("Enter value of n :");
    cin>>n;
    print1(n);
    print2(n);
}