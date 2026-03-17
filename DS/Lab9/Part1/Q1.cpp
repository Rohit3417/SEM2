#include <bits/stdc++.h>
using namespace std;

bool check(vector<int>a,vector<int>b)
{
    for(int i = 0;i<b.size();i++)
    {
        int temp = 0;
        for(int j=0;j<a.size();j++)
        {
            if(b[i] == a[j])
            {
                temp = 1;
                break;
            }
        }
        if(temp == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    vector<int>a(7);
    vector<int>b(5);
    cout<<"Enter elements of array A : "<<endl;
    for(int i=0;i<7;i++)
    {
        cin>>a[i];
    }
    cout<<"Enter elements of array B : "<<endl;
    for(int i=0;i<5;i++)
    {
        cin>>b[i];
    }
    if(check(a,b))
    {
        cout<<"true";
    }
    else
    {
        cout<<"false";
    }

}