#include<bits/stdc++.h>
using namespace std;

int precedance(char op)
{
    if(op == '+' || op == '-')
    return 1;
    if(op == '*' || op == '/')
    return 2;
    return 0;
}

string convert(string s)
{
    stack<char>store;
    
    string str = "";
    int i =0,temp = 0;
    for(;i<s.size();i++)
    {
        if(s[i] == '(')
        {
            store.push(s[i]);
        }
        else if (s[i] >='A' && s[i] <='Z' || s[i] >='a' && s[i] <='z')
        {
            str += s[i];
            
        }
        else if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
        {
            if(precedance(store.top())<precedance(s[i]))
            {
                store.push(s[i]);
            }
            else{
                while(precedance(store.top()) >= precedance(s[i]))
                {
                    str += store.top();
                    
                    store.pop();
                }
                store.push(s[i]);
            }
        }
        else if(s[i] == ')')
        {
            while(store.top() != '(' && !store.empty())
            {
                str += store.top();
                
                store.pop();
            }
            if(!store.empty())
            store.pop();
        }
    }
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
    cout<<"Enter the infix expression : ";
    cin>>s;
    cout << convert(s);

}