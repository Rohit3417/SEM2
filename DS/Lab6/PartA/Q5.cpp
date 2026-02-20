#include<bits/stdc++.h>
using namespace std;
int ans(string s)
{
    stack<int> store;
    int a,b,temp;
    for(int i = 0;i<s.size();i++)
    {
        if(isdigit(s[i]))
        {
            temp = s[i] - '0';
            store.push(temp);
        } 
        else 
        {
            a = store.top();
            store.pop();
            b = store.top();
            store.pop();
            if(s[i] == '+')
                store.push(b+a);
            else if(s[i] == '-')
                store.push(b-a);
            else if(s[i] == '*')
                store.push(b*a);
            else if(s[i] == '/')
                store.push(b/a);
            
        }
    }
    return store.top();  
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
