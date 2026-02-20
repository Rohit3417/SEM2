#include<bits/stdc++.h>
using namespace std;
//retrival of minimum element in O(1) time;
//Maintain an auxilary stack
class Stack{
    public:
    int top1 = -1,top2=-1;
    int arr1[10],arr2[10];
    void push(int x)
    {
        top1++;
        arr1[top1] = x;
        if(top1 >= 10 || top2 >= 10)
        {
            cout<<"Stack overflow" ;
            
        }
        else if(top1==0)
        {
            top2++;
            arr2[top2] = x;
        }
        else{
            if(arr1[top1]<arr2[top2])
            {
                top2++;
                arr2[top2] = arr1[top1];
            }
        }
    }
    void pop()
    {
        if(arr1[top1] == arr2[top2])
        {
            top1--;
            top2--;
        }
        else{
            top1--;
        }
    }
    void getmin()
    {
        cout<<"Minimum value is " << arr2[top2]<<endl;
    }
};

int main()
{
    Stack a;
    a.push(6);
    a.push(2);
    a.push(9);
    a.getmin();
    a.pop();
    a.pop();
    a.getmin();

}