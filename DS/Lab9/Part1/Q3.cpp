#include <bits/stdc++.h>
using namespace std;
int main()
{
     vector<int>a(5);
    vector<int>b(5);
    cout<<"Enter elements of array A : "<<endl;
    for(int i=0;i<5;i++)
    {
        cin>>a[i];
    }
    cout<<"Enter elements of array B : "<<endl;
    vector<int>temp;
    for(int i=0;i<5;i++)
    {
        cin>>b[i];
    }
    for(int i = 0;i<a.size();i++)
    {
        for(int j = 0;j<b.size();j++)
        {
            if(a[i] == b[j] && i!= j)
            {
                temp.push_back(a[i]);
            }
        }
    }
    for(int i = 0;i<temp.size();i++)
    {
        for(int j=i+1;j<temp.size();j++)
        {
            if(temp[i] == temp[j])
            {
                temp.erase(temp.begin()+j);
                j--;
            }
        }
    }
    cout<<"Intersection elements are : ";
    for(int i=0;i<temp.size();i++)
    {
        cout<<temp[i]<<" ";
    }
}