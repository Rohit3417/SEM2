#include<bits/stdc++.h>
using namespace std;

int precedence(char op)
{
    if(op == '+' || op == '-') return 1;
    if(op == '*' || op == '/') return 2;
    return 0;
}

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
string convert(string s)
{
    
    string str = "";

    for(int i = 0; i < s.size(); i++)
    {
        // Operand
        if(isalpha(s[i]))
        {
            str += s[i];
        }

        // Opening bracket
        else if(s[i] == '(')
        {
            push(s[i]);
        }

        // Closing bracket
        else if(s[i] == ')')
        {
            while(!empty() && peek() != '(')
            {
                str += peek();
                pop();
            }
            if(!empty())
                pop();
        }

        // Operator
        else
        {
            while(!empty() && precedence(peek()) >= precedence(s[i]))
            {
                str += peek();
                pop();
            }
            push(s[i]);
        }
    }

    // Remaining operators
    while(!empty())
    {
        str += peek();
        pop();
    }

    return str;
}

int main()
{
    string s;
    cout << "Enter the infix expression : ";
    cin >> s;

    cout << "Postfix Expression : " << convert(s);
}
