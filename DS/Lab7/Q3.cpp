#include<bits/stdc++.h>
using namespace std;

class Queue
{
    public:
    class node {
        public:
        int data;
        node*next;
        node(int value)
        {
            data = value;
            next = NULL;
        }
    };
    node*front=nullptr,*rear=nullptr;
    void enqueue(int x)
    {
        node *newnode = new node(x);
        if(front == NULL)
        {
            front = rear = newnode;
            rear->next = front;
        }
        else
        {
            rear->next = newnode;
            rear = newnode;
            rear->next = front;
        }
    }
    void dequeue()
    {
        if(front == NULL)
        {
            cout<<"Queue is empty";
        }
        else if(front->next == NULL)
        {
            free(front);
            rear = nullptr;
            front = nullptr;
        }
        else
        {
            node *temp;
            temp = front;
            front = front->next;
            free(temp);
        }
    }
    int Front()
    {
        if(front == NULL)
        {
            return 0;
        }
        else
        {
            return front->data;
        }
    }
    int Rear()
    {
        if(rear == NULL)
        {
            return 0;
        }
        else
        {
            return rear->data;
        }
    }
};

int main()
{
    Queue q;
    q.enqueue(14);
    q.enqueue(22);
    q.enqueue(-6);
    q.dequeue();
    q.dequeue();
    q.enqueue(9);
    cout<<"Front element"<<q.Front()<<endl;
    cout<<"Last elemenet"<<q.Rear()<<endl;

}