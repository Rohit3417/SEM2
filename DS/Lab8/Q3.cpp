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
            exit;
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

void findMinMax(Queue q)
{
    vector<int>temp;
    int min = q.top(),max = q.top();
    while(!q.isEmpty())
    {
        if(min>=q.top())
        {
            min = q.top();
        }
        if(max <= q.top())
        {
            max = q.top();
        }
        temp.push_back(q.top());
        q.Dequeue();
    }
    for(int i=0;i<temp.size();i++)
    {
        q.Enqueue(temp[i]);
    }
    cout<<"Max element is : "<<max<<endl;
    cout<<"Min element is : "<<min<<endl;
}

int main()
{
    Queue q ;
    q.Enqueue(4);
    q.Enqueue(1);
    q.Enqueue(9);
    q.Enqueue(7);
    findMinMax(q);
    cout<<q.top();
}