#include<bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int> &arr)
{
    int size = arr.size(),temp,swap;
    for(int i=0;i<size;i++)
    {
        swap = 1;
        for(int j=i+1;j<size-i;j++)
        {
            if(arr[i]>arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                swap = 0;
            }
        }
        if(swap == 1)
        break;
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

    bubbleSort(arr);

    cout<<"\nAfter sorting : " ;
    for(int i = 0;i<size;i++)
    {
        cout<<arr[i]<<" "; 
    }
}