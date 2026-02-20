#include<bits/stdc++.h>
#include<vector>
using namespace std;

    int arr[10],top=-1;
    
    void push(int x)
    {
        if(top != sizeof(arr)-1)
        {
            top++;
            arr[top] = x; 
        }
        else{
            cout<<"Stack overflow\n";
        }
    }
    void pop()
    {
        top--;
    }
    void peek()
    {
        cout<<"Top element is "<< arr[top]<<"\n";
    }
    bool isEmpty()
    {
        if(top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool isFull()
    {
        if(top == sizeof(arr)-1)
        {
            return true;
        }
        else{
            return false;
        }
    }
    void display()
    {
        for(int i = 0;i<=top;i++)
        {
            cout<<arr[i] <<" " ;
        }
        cout<<"\n" ;
    }

int main()
{
    push(30);
    push(10);
    push(100);
    peek();
    pop();
    display();
}