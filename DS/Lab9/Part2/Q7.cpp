#include<bits/stdc++.h>
using namespace std;
struct node {
    int data;
    struct node *next;
    node (int x)
    {
        data = x;
        next = NULL;
    }
};

void display(struct node *head)
{
    if(head == NULL)
    cout<<"0";
    else
    {
        while(head != NULL)
        {
            cout<<head->data<<" ";
            head = head->next;
        }
    }
}

int main()
{
    int arr[4];
    
    struct node *head[4] ;
    cout<<"Enter array elements"<<endl;
    for(int i=0;i<4;i++)
    {
        cin>>arr[i];
        head[i] = NULL;
    }

    for(int i=0;i<4;i++)
    {
        int index = arr[i] % 4 ;
        node *newnode = new node(arr[i]);
        node *temp[index];
        if(head[index] == NULL)
        {
            head[index] = newnode; 
            temp[index] = newnode;
        }
        else
        {
            temp[index]->next = newnode;
            temp[index] = newnode;
        }
    }

    cout<<"   index   :   Key"<<endl;

    for(int i=0;i<4;i++)
    {
        cout<<"   "<<i<<"          ";
        display(head[i]);
        cout<<"\n";
    }
}