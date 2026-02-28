//Method 1
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

class Queue{
    public:
    node *front = nullptr,*rear = nullptr;
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
        if(front == NULL)
        {
            return true;
        }
        else{
            return false;
        }
    }
};

void reverse(Queue &q)
{
    stack<int>temp;
    while(!q.isEmpty())
    {
        temp.push(q.top());
        q.Dequeue();
    }
    while(!temp.empty())
    {
        q.Enqueue(temp.top());
        temp.pop();
    }
}

int main()
{
    Queue q ;
    q.Enqueue(1);
    q.Enqueue(2);
    q.Enqueue(3);
    q.Enqueue(4);
    reverse(q);
   cout<<"Revesed queue is : " ;
    while(!q.isEmpty())
   {
    cout<<q.top()<<" ";
    q.Dequeue();
   }
}