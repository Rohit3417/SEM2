//Method 2
#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node *next;
    node(int val)
    {
        data = val;
        next = NULL;
    }
};
node *front = nullptr,*rear = nullptr;
class Queue{
    public:
    
    void Enqueue(int x)
    {
        node *newnode = new node(x);
        if(front == NULL)
        {
            front = newnode;
            rear = front;
        }
        else{
            rear->next = newnode;
            rear = newnode;
        }
    } 
    
    void Dequeue()
    {
        if(front == NULL)
        {
            cout<<"Queue is empty";
            exit(0);
        }
        else
        {
            node *temp;
            temp = front;
            front = front->next;
            delete temp;
        }
    }

    int top()
    {
        if(front == NULL)
        {
            cout<<"\nQueue is now empty";
            return 0;
        }
        return front->data;
    }

    bool isEmpty()
    {
        return front == NULL;
    }
};

void reverse(Queue q)
{
        if(q.isEmpty())
        {
            return;
        }
        int x = q.top();
        q.Dequeue();
        reverse(q);
        q.Enqueue(x);

}

int main()
{
    Queue q ;
    q.Enqueue(1);
    q.Enqueue(2);
    q.Enqueue(3);
    q.Enqueue(4);
    reverse(q);
    cout<<"Revesed queue is : ";
   for(int i=0;i<4;i++)
   {
    cout<<q.top()<<" ";
    q.Dequeue();
   }
   return 0;
}