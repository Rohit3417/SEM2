#include<bits/stdc++.h>
using namespace std;

int count(vector<int>arr,int target)
{
    int count1 = 0;
    for(int i=0;i<arr.size();i++)
    {
        for(int j=i+1;j<arr.size();j++)
        {
            if(arr[i] + arr[j] == target)
            {
                count1++;
            }
        }
    }
    return count1;
}

int main()
{
    vector<int>arr(5);
    cout<<"Enter the elements of array"<<endl;
    for(int i=0;i<5;i++)
    {
        cin>>arr[i];
    }
    int target;
    cout<<"Enter target value : ";
    cin>>target;
    cout<<"Number of pairs whose sum is equal to target value : "<<count(arr,target);
    return 0;
}