#include<bits/stdc++.h>
using namespace std;

void mergeArray(vector<int>&arr,int low,int mid,int high);
void mergeSort(vector<int>&arr,int low,int high)
{
    int mid = (low+high)/2;
    if(low>=high)
        return ;
    mergeSort(arr,low,mid);
    mergeSort(arr,mid+1,high);
    mergeArray(arr,low,mid,high);
}   

void mergeArray(vector<int>&arr,int low,int mid,int high)
{
    int left = low,right = mid + 1;
    vector<int>temp;
    while(left<=mid && right<=high)
    {
        if(arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
        }
    }

    while(left<=mid)
    {
        temp.push_back(arr[left]);
        left++;
    }
    while(right<=high)
    {
        temp.push_back(arr[right]);
        right++;
    }
    for(int i = low;i<=high;i++)
    {
        arr[i] = temp[i-low];
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

    mergeSort(arr,0,size-1);

    cout<<"\nAfter sorting : " ;
    for(int i = 0;i<size;i++)
    {
        cout<<arr[i]<<" "; 
    }
}