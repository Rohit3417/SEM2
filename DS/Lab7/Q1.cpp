#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node*next;
    Node(int value)
    {
        data = value;
        next = NULL;
    }
};

class Queue
{
    public:
    Node *front = nullptr,*rear = nullptr;
    void Enqueue(int x)
    {
        Node *newnode = new Node(x);
        if(front == rear && rear == NULL)
        {
            rear = front = newnode;
        }
        else
        {
            rear->next = newnode;
            rear = newnode;
        }
    } 
    
    void Dequeue()
    {
        if(front == NULL)
        {
            cout<<"Queue is empty";
        }
        else
        {
            Node *temp;
            temp = front;
            front = front->next ;
            free(temp);
        }
    }

    bool isEmpty()
    {
        if(front == rear && rear == NULL)
        {
            return true;
        }
        else{
            return false;
        }
    }

    int Front()
    {
        if(front == NULL)
        {
            cout<<"Queue is Empty";
        }
        else{
            return front->data;
        }
    }
};

int main()
{
    Queue q;
    q.Enqueue(2);
    q.Enqueue(4);
    q.Enqueue(6);
    q.Enqueue(7);
    q.Enqueue(9);
    
    q.Dequeue();
    cout<<"Front element : "<<q.Front()<<"\n";    
    if(!q.isEmpty())
    {
        cout<<"Not empty";
    }
    else{
        cout<<"Empty";
    }
}