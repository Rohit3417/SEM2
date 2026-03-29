#include<bits/stdc++.h>
using namespace std;

int findMid(int square)
{
    int temp = square,digits=0;
    while(temp != 0)
    {
        digits ++;
        temp = temp/10;
    }
    int i=0;
    temp = 0;

    while(i<=digits/2)
    {
        if(i >= digits/2 - 1)
        {
            temp = temp*10 + square % 10;
        }
        square = square/10;
        i++;
    }
    square = 0;
    while(temp != 0)
    {
        int q = temp %10;
        square = 10*square + q;
        temp = temp/10;
    }
    return square;
}

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

    for(int i = 0;i<7;i++)
    {
        int square = arr[i]*arr[i];
        int mid = findMid(square);
        int index = mid%7;

        while(hashTable[index] != -1)
        {
            index = (index + 1) % 7 ;
        }
        hashTable[index] = arr[i];
    }

    cout<<"  Index      key value"<<endl;
    for(int i=0;i<7;i++)
    {
        cout<<"   "<<i<<":        "<<hashTable[i]<<endl;

    }
}