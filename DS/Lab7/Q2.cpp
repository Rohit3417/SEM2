#include <bits/stdc++.h>
using namespace std;

class Queue
{
public:
    class node
    {
    public:
        int data;
        int priority;
        node *next;
        node(int value, int prio)
        {
            data = value;
            priority = prio;
            next = NULL;
        }
    };
    node *head = nullptr;

    void push(int x, int prio)
    {
        node *newnode = new node(x, prio);
        if (head == NULL)
        {
            head = newnode;
        }
        else if (prio == 0)
        {
            newnode->next = head;
            head = newnode;
        }
        else
        {
            node *temp;
            temp = head;
            while (temp->next != NULL && prio > temp->next->priority )
            {
                temp = temp->next;
            }
            newnode->next = temp->next;
            temp->next = newnode;
        }
    }

    void pop()
    {
        if(head == NULL)
        {
            cout<<"Queue is empty";
        }
        else
        {
            node *temp;
            temp = head;
            head = head->next;
            free(temp);
        }
    }

    int top()
    {
        if(head == NULL)
        {
            return 0;
        }
        else{
            return head->data;
        }
    }
};

int main()
{
    Queue q;
    q.push(4,1);
    q.push(5,2);
    q.push(6,3);
    q.push(7,0);
    
    for(int i=0;i<5;i++)
    {
        cout<<q.top()<<endl;
        q.pop();
    }
        
      
    
}
