#include<bits/stdc++.h>
#include <unordered_map>
using namespace std;


int main(){
    
    vector<int>a(5);
    vector<int>b(5);
    cout<<"Enter elements of array A : "<<endl;
    for(int i=0;i<5;i++)
    {
        cin>>a[i];
    }
    cout<<"Enter elements of array B : "<<endl;
    for(int i=0;i<5;i++)
    {
        cin>>b[i];
    }

    map<int,int>mpp;
    
    for(int i=0;i<5;i++)
    {
        mpp[a[i]]++;
        mpp[b[i]]++;
    }
    for(int i=0;i<5;i++)
    {
        if(mpp[a[i]] >= 2)
        {
            cout<<a[i]<<" ";
            mpp.erase(a[i]);
        }
    }
    

}