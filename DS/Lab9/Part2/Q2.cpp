#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[7];
    int hashTable[7];
    cout<<"Enter array elements"<<endl;
    for(int i=0;i<7;i++)
    {
        cin>>arr[i];
        hashTable[i] = -1;
    }
    float A = 0.618f;
    for(int i=0;i<7;i++)
    {
        double temp = arr[i]*A;
        double fractional = temp - floor(temp);
        int index = (int)7*fractional;  
        while(hashTable[index] != -1)
        {
            index = (index+1)%7;
        }
        hashTable[index] = arr[i];
    }

    cout<<"  Index      key value"<<endl;
    for(int i=0;i<7;i++)
    {
        cout<<"   "<<i<<":        "<<hashTable[i]<<endl;

    }
}