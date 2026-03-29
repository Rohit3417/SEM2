#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[7];
    int hashTable[7] ;
    cout<<"Enter array elements"<<endl;
    for(int i=0;i<7;i++)
    {
        cin>>arr[i];
        hashTable[i] = -1;
    }
    
    for(int i=0;i<7;i++)
    {
        int j = arr[i]%7;   //Division method
        while(hashTable[j] != -1)
        {
            j = (j+1) %7;           //Linear probing
        }
        hashTable[j] = arr[i];
    }
    cout<<"  Index      key value"<<endl;
    for(int i=0;i<7;i++)
    {
        cout<<"   "<<i<<":        "<<hashTable[i]<<endl;

    }
}