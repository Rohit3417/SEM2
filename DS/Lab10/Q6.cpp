#include<bits/stdc++.h>
using namespace std;

void heapify(vector<int>& arr, int n, int i)
{
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < n && arr[left] > arr[largest])
        largest = left;

    if(right < n && arr[right] > arr[largest])
        largest = right;

    if(largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int>& arr, int n)
{
    // Build max heap
    for(int i = n/2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Extract elements
    for(int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);   // move max to end
        heapify(arr, i, 0);     // heapify reduced heap
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

    heapSort(arr,size);

    cout<<"\nAfter sorting : " ;
    for(int i = 0;i<size;i++)
    {
        cout<<arr[i]<<" "; 
    }
}