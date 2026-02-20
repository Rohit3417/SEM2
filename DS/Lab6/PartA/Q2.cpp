#include <bits/stdc++.h>
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
    struct node *temp;
    char x;
    
    if(top == NULL)
    {
        cout << "Stack is empty";
        return '\0';
    }
    
    temp = top;
    x = temp->data;
    top = top->next;
    delete temp;
    
    return x;
}

int main()
{
    string str;
    
    cout << "Enter string : ";
    cin >> str;
    
    // push all characters
    for(int i = 0; i < str.size(); i++)
    {
        push(str[i]);
    }
    
    cout << "Given string is : " << str << endl;
    
    // pop and reverse string
    for(int i = 0; i < str.size(); i++)
    {
        str[i] = pop();
    }
    
    cout << "After reversing the string : " << str << endl;
    
    return 0;
}
