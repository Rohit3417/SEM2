#include<bits/stdc++.h>
using namespace std;
//Implementaton of queue using array
int arr[10];
int front=-1,rear=-1;
class Queue{
    public:
    void Enqueue(int x)
    {
        if(rear>=10)
        {
            cout<<"Queue is full";
            return;
        }
        if(front == -1)
        {
            front++;
            rear++;
        }
        else{
            rear++;
        }
        arr[rear] = x;
    }

    void Dequeue()
    {
        if(rear == front)
        {
            rear--;
        }
        front++;
    }

    int top()
    {
        return arr[front];
    }

};

int main()
{   
    Queue q;
    q.Enqueue(1);
    q.Enqueue(2);
    q.Enqueue(3);
    q.Enqueue(4);
    int count = rear-front +1;
    cout<<"Number of elements in queue before removing : "<<count<<endl;
    for(int i=0;i<4;i++)
    {
        cout<<q.top()<<" ";
        q.Dequeue();
    }
    count = rear-front +1;
    cout<<"\nAfter removing : "<<count;
   
}