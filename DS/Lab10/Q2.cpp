#include<bits/stdc++.h>
using namespace std;

void selectionSort(vector<int>&arr)
{
    int temp;
    for(int i=0;i<arr.size();i++)
    {
        for(int j=i+1;j<arr.size();j++)
        {
            if(arr[i]>arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main()
{
    int size;
    cout<<"Enter the size of array"<<endl;
    cin>>size;
    vector<int>arr(size);
    cout<<"Enter the elements of array : "<<endl;
    for(int i =0;i<size;i++)
    {
        cin>>arr[i];
    }

    cout<<"Before sorting : " ;
    for(int i = 0;i<size;i++)
    {
        cout<<arr[i]<<" "; 
    }

    selectionSort(arr);

    cout<<"\nAfter sorting : " ;
    for(int i = 0;i<size;i++)
    {
        cout<<arr[i]<<" "; 
    }
}