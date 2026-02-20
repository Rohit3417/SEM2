#include<bits/stdc++.h>
using namespace std;

int precedence(char op)
{
    if(op == '+' || op == '-') return 1;
    if(op == '*' || op == '/') return 2;
    return 0;
}

string convert(string s)
{
    stack<char> store;
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
            store.push(s[i]);
        }

        // Closing bracket
        else if(s[i] == ')')
        {
            while(!store.empty() && store.top() != '(')
            {
                str += store.top();
                store.pop();
            }
            if(!store.empty())
                store.pop();
        }

        // Operator
        else
        {
            while(!store.empty() && precedence(store.top()) >= precedence(s[i]))
            {
                str += store.top();
                store.pop();
            }
            store.push(s[i]);
        }
    }

    // Remaining operators
    while(!store.empty())
    {
        str += store.top();
        store.pop();
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
