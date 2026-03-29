#include <bits/stdc++.h>
using namespace std;

int getMax(vector<int>&arr, int n) {
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

void countingSort(vector<int>&arr, int n, int exp) {
    int output[n];
    int count[10] = {0};

    // Count occurrences
    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    // Cumulative count
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build output (stable)
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copy back
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixSort(vector<int>&arr, int n) {
    int m = getMax(arr, n);

    for (int exp = 1; m / exp > 0; exp *= 10)
        countingSort(arr, n, exp);
}

int main() {
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

    radixSort(arr, size);

    cout<<"\nAfter sorting : " ;
    for(int i = 0;i<size;i++)
    {
        cout<<arr[i]<<" "; 
    }    

    

}