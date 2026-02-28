#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* random;

    Node(int x) {
        data = x;
        next = NULL;
        random = NULL;
    }
};

Node* cloneList(Node* head)
{
    if(head == NULL)
        return NULL;

    Node* temp = head;

    // Step 1: Insert cloned nodes in between
    while(temp != NULL)
    {
        Node* copy = new Node(temp->data);
        copy->next = temp->next;
        temp->next = copy;
        temp = copy->next;
    }

    // Step 2: Assign random pointers
    temp = head;
    while(temp != NULL)
    {
        if(temp->random != NULL)
            temp->next->random = temp->random->next;

        temp = temp->next->next;
    }

    // Step 3: Separate both lists
    temp = head;
    Node* cloneHead = head->next;

    while(temp != NULL)
    {
        Node* copy = temp->next;
        temp->next = copy->next;

        if(copy->next != NULL)
            copy->next = copy->next->next;

        temp = temp->next;
    }

    return cloneHead;
}

void printList(Node* head)
{
    while(head != NULL)
    {
        cout << "Data: " << head->data;
        if(head->random)
            cout << " Random: " << head->random->data;
        else
            cout << " Random: NULL";
        cout << endl;

        head = head->next;
    }
}

int main()
{
    // Create original list: 1 -> 2 -> 3
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);

    // Setting random pointers
    head->random = head->next->next;        // 1 → 3
    head->next->random = head;              // 2 → 1
    head->next->next->random = head->next;  // 3 → 2

    cout << "Original List:\n";
    printList(head);

    Node* cloned = cloneList(head);

    cout << "\nCloned List:\n";
    printList(cloned);

    return 0;
}