#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    char data;
    node *next;
    node *prev;
    node(char val)
    {
        data = val;
        next = NULL;
        prev = NULL;
    }
};
node *front=nullptr,*rear = nullptr;
class Queue{
    public:
    void Insertfront(char x)
    {
        node *newnode = new node(x);
        if(front == NULL)
        {
            front = rear = newnode;
        }
        else
        {
            newnode->next = front;
            front ->prev  = newnode;
            front = newnode;
        }
    }

    void Insertrear(char x)
    {
        node *newnode = new node(x);
        if(rear == NULL)
        {
            front = rear = newnode;
        }
        else
        {
            rear->next = newnode;
            newnode->prev = rear;
            rear = newnode;
        }
    }

    void deletefront()
    {
        if(front == rear)
        {
            front = rear = NULL;
        }
        else if(front == NULL)
        {
            cout<<"Queue Underflow";
            return;
        }
        else
        {
            node *temp;
            temp = front;
            front = front->next;   
        }
    }

    void deleterear()
    {
        if(front == rear)
        {
            front = rear = NULL ;
        }
        else if(rear == NULL)
        {
            cout<<"Queue Underflow" ;
            return ;
        }
        else
        {
            node *temp;
            temp = rear;
            rear = rear->prev;
            delete(temp);
        }
    }

    char topfront()
    {
        if(front == NULL)
        return '\0';
        return front->data;
    }

    char toprear()
    {
        if(rear == NULL)
        return '\0';
        return rear->data;
    }

    bool isEmpty()
    {
        if(!front)
        return true;
        else 
        return false;
    }
};


bool check(Queue &q)
{
    int temp = 0;
    while(!q.isEmpty())
    {
        if(q.topfront() != q.toprear())
        {
            temp = 1;
            break;
        }
        q.deletefront();
        q.deleterear();
    }
    if(temp == 0)
    {
        return true;
    }
    else{
        return false;
    }
}
int main()
{
    Queue q;
    q.Insertrear('m');
    q.Insertrear('a');
    q.Insertrear('d');
    q.Insertrear('a');
    q.Insertrear('m');
    if(check(q))
    {
        cout<<"Palindrome";
    }
    else{
        cout<<"Not Palindrome" ;
    }

}