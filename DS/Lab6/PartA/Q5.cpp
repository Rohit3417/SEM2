#include<bits/stdc++.h>
using namespace std;

struct node {
    char data;
    struct node *next;

};

struct node*top = NULL;

void push(char x)
{
    struct node *newnode;
    newnode = new node;
   
    newnode->data = x ;
    newnode->next = top;
    top = newnode;
}

void pop()
{
    struct node *temp;
    temp = top;
    top = top->next;
    delete temp;
}

char peek()
{
    return top->data;
}

bool empty()
{
    if(top == NULL)
    {
        return true;
    }
    else{
        return false;
    }
}

int ans(string s)
{
    
    int a,b,temp;
    for(int i = 0;i<s.size();i++)
    {
        if(isdigit(s[i]))
        {
            temp = s[i] - '0';
            push(temp);
        } 
        else 
        {
            a = peek();
            pop();
            b = peek();
            pop();
            if(s[i] == '+')
                push(b+a);
            else if(s[i] == '-')
                push(b-a);
            else if(s[i] == '*')
                push(b*a);
            else if(s[i] == '/')
                push(b/a);
            
        }
    }
    return peek();  
}

int main()
{
    string s;
    cout<<"Enter postfix expression : ";
    cin>>s;
    int a = ans(s);
    cout<<"Evaluated value : "<<a;
    return 0;
}
