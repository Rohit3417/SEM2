#include<bits/stdc++.h>
using namespace std;


struct node
{
    char data;
    struct node *next;
};

struct node *top = NULL;


void push(char x)
{
    struct node *temp;
    temp = new node;
    temp->data = x;
    temp->next = top;
    top = temp;
}


char pop()
{
    if(top == NULL)
        return '\0';

    struct node *temp = top;
    char x = temp->data;
    top = top->next;
    delete temp;
    return x;
}


char peek()
{
    if(top == NULL)
        return '\0';
    return top->data;
}

bool isEmpty()
{
    return top == NULL;
}


bool check(string s)
{
    if(s.size() == 0 || s.size() == 1)
        return false;

    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == '(' || s[i] == '[' || s[i] == '{')
        {
            push(s[i]);
        }

        else if(s[i] == ')')
        {
            if(peek() == '(')
                pop();
            else
                return false;
        }

        else if(s[i] == ']')
        {
            if(peek() == '[')
                pop();
            else
                return false;
        }

        else if(s[i] == '}')
        {
            if(peek() == '{')
                pop();
            else
                return false;
        }

        else if(s[i] >= 'a' && s[i] <= 'z' ||
                s[i] == '+' || s[i] == '-' ||
                s[i] == '*' || s[i] == '/' ||
                s[i] == '%' || s[i] >='A' && s[i] <='Z')
        {
            continue;
        }

        else
        {
            return false;
        }
    }

    if(isEmpty())
        return true;
    else
        return false;
}


int main()
{
    string s;

    cout << "Enter the string of brackets : ";
    cin >> s;

    if(check(s))
        cout << "Balanced";
    else
        cout << "Unbalanced";

    return 0;
}
