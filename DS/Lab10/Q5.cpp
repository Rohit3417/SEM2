#include<bits/stdc++.h>
using namespace std;
int Partition(vector<int>&arr,int p,int r);
void QuickSort(vector<int>&arr,int p,int r)
{
    if(p<r)
    {
        int q = Partition(arr,p,r);
        QuickSort(arr,p,q-1);
        QuickSort(arr,q+1,r);
    }
}

int Partition(vector<int>&arr,int p,int r)
{
    int j;
    int x = arr[r];
    int i = p-1,temp;
    for(j=p;j<r;j++)
    {
        if(arr[j]<=x)
        {
            i = i+1;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    temp = arr[i+1];
    arr[i+1] = arr[r];
    arr[r] = temp;
    return i+1; 
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

    QuickSort(arr,0,size-1);    

    cout<<"\nAfter sorting : " ;
    for(int i = 0;i<size;i++)
    {
        cout<<arr[i]<<" "; 
    }
}