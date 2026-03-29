#include<bits/stdc++.h>
using namespace std;
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

    for(int i = 0;i<4;i++)
    {
        int index = arr[i]%4;
        while(hashTable[index] != -1)
        {
            index = (index + i*i) % 4 ;
        }
        hashTable[index] = arr[i];
    }

    cout<<"  Index      key value"<<endl;
    for(int i=0;i<4;i++)
    {
        cout<<"   "<<i<<":        "<<hashTable[i]<<endl;

    }
}