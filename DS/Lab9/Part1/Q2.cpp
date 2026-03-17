#include <bits/stdc++.h>
using namespace std;

int maxDistance(vector<int>arr)
{
    int size = arr.size();
    int max = 0;
    for(int i=0;i<size;i++)
    {
        for(int j=size-1;j>i;j--)
        {
            if(arr[i] == arr[j])
            {
                if(max < j-i)
                {
                    max = j-i;
                }
                else{
                    continue;
                }
            }
        }
    }
    return max;
}

int main()
{
    vector<int>arr(6);
    cout<<"Enter the elements of array : "<<endl;
    for(int i = 0;i<6;i++)
    {   
        cin>>arr[i];
    }
    int max = maxDistance(arr);
    cout<<"Max distance is "<<max;
}