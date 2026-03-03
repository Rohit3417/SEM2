#include<bits/stdc++.h>
using namespace std;

//FLATTEN LINKED LIST WITH BOTTOM AND NEXT POINTER AND SORT 

struct Node {
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

// Merge two sorted bottom lists
Node* merge(Node* a, Node* b)
{
    if(a == NULL) return b;
    if(b == NULL) return a;

    Node* result;

    if(a->data < b->data)
    {
        result = a;
        result->bottom = merge(a->bottom, b);
    }
    else
    {
        result = b;
        result->bottom = merge(a, b->bottom);
    }

    result->next = NULL;   // IMPORTANT
    return result;
}

// Flatten function
Node* flatten(Node* root)
{
    if(root == NULL || root->next == NULL)
        return root;

    // Recursively flatten remaining lists
    root->next = flatten(root->next);

    // Merge current list with next list
    root = merge(root, root->next);

    return root;
}

// Print using bottom pointer
void print(Node* root)
{
    while(root != NULL)
    {
        cout << root->data << " ";
        root = root->bottom;
    }
}

int main()
{
    // Creating sample structure manually

    Node* head = new Node(5);
    head->bottom = new Node(7);
    head->bottom->bottom = new Node(8);
    head->bottom->bottom->bottom = new Node(30);

    head->next = new Node(10);
    head->next->bottom = new Node(20);

    head->next->next = new Node(19);
    head->next->next->bottom = new Node(22);
    head->next->next->bottom->bottom = new Node(50);

    head->next->next->next = new Node(28);
    head->next->next->next->bottom = new Node(35);
    head->next->next->next->bottom->bottom = new Node(40);
    head->next->next->next->bottom->bottom->bottom = new Node(45);

    head = flatten(head);

    cout << "Flattened List: ";
    print(head);

    return 0;
}