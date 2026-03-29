#include<bits/stdc++.h>
#include <unordered_map>
using namespace std;


int main(){
    
    vector<int>a(6);
    vector<int>b(4);
    cout<<"Enter elements of array A : "<<endl;
    for(int i=0;i<6;i++)
    {
        cin>>a[i];
    }
    cout<<"Enter elements of array B : "<<endl;
    for(int i=0;i<4;i++)
    {
        cin>>b[i];
    }
    map<int,int>mpp;
    int flag = 1;
    for (int i = 0; i < 6; i++)
    {
       mpp[a[i]]++;
    }
    for (int i = 0; i < 6; i++)
    {
       if(mpp[b[i]]==0)
       flag == 0;
    } 
    if(flag == 0)
    cout<<"false";
    else
    cout<<"true";
    return 0;
}
