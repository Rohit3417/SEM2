#include<bits/stdc++.h>
using namespace std;

void InsertionSort(vector<int>&arr)
{
    int temp;
    for(int i = 0;i<arr.size();i++)
    {
        int j = i;
        while(j>0 && arr[j-1] > arr[j])
        {
            temp = arr[j-1];
            arr[j-1] = arr[j];
            arr[j] = temp;
            j--;
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

    InsertionSort(arr);

    cout<<"\nAfter sorting : " ;
    for(int i = 0;i<size;i++)
    {
        cout<<arr[i]<<" "; 
    }
}