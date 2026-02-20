#include<bits/stdc++.h>
using namespace std;
class Stack
{
    public:
    class node {
        public:
        int data;
        struct node *next;
        node(int value)
        {
            data = value;
            next = NULL;
        }
    };
    struct node *head = nullptr,*temp2;
    void push(int x)
    {
        node* temp = new node(x);
        if(head == NULL)
        {
            head = temp;
            
        }
        else                                                            //head = top
        {
            temp->next = head;
            head = temp;
        }
    }
    void pop()
    {
        if(head == NULL)
        {
            cout<<"stack overflow ";
        }
        else if(head->next ==NULL)
        {
            cout<<"Poped value : "<<head->data;
            free(head);
        }
        else{
            cout<<"Poped value : "<<head->data;
            temp2 = head;
            head = head ->next;
            free(temp2);
        }
    }
    void peek()
    {
        cout<<"Peek value in the stack is : "<<head->data ;
    }
    void isEmpty()
    {
        if(head == NULL)
        {
            cout<<"True";
        }
        else
        {
            cout<<"False";
        }
    }
};

int main()
{
    Stack a;
    a.push(10);
    a.push(30);
    a.pop();
}