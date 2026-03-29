#include<bits/stdc++.h>
using namespace std;

int hash1(int key)
{
    return key%4;
}

int hash2(int key)
{
    return 1+key%(4-2) ;
}

int main()
{
    int arr[4];
    int hashTable[4];
    cout<<"Enter array elements"<<endl;
    for(int i=0;i<4;i++)
    {
        cin>>arr[i];
        hashTable[i] = -1;
    }

    for(int i=0;i<4;i++)
    {
        int index = hash1(arr[i]) + i*hash2(arr[i])%4 ;
        while(hashTable[index] != -1)
        {
            index = (index+i)%4;
        }
        hashTable[index] = arr[i] ;
    }

    cout<<"  Index      key value"<<endl;
    for(int i=0;i<4;i++)
    {
        cout<<"   "<<i<<":        "<<hashTable[i]<<endl;

    }
}