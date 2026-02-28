#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node* random;

    Node(int val) {
        data = val;
        next = prev = random = NULL;
    }
};

// Function to print doubly linked list with random pointer
void printList(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << "Node: " << temp->data;

        if (temp->prev)
            cout << " | Prev: " << temp->prev->data;
        else
            cout << " | Prev: NULL";

        if (temp->next)
            cout << " | Next: " << temp->next->data;
        else
            cout << " | Next: NULL";

        if (temp->random)
            cout << " | Random: " << temp->random->data;
        else
            cout << " | Random: NULL";

        cout << endl;
        temp = temp->next;
    }
}

// Clone Function
Node* cloneDLL(Node* head) {
    if (!head) return NULL;

    Node* curr = head;

    // Step 1: Insert clone nodes
    while (curr) {
        Node* temp = new Node(curr->data);
        temp->next = curr->next;
        curr->next = temp;
        temp->prev = curr;
        if (temp->next)
            temp->next->prev = temp;
        curr = temp->next;
    }

    // Step 2: Copy random pointers
    curr = head;
    while (curr) {
        if (curr->random)
            curr->next->random = curr->random->next;
        curr = curr->next->next;
    }

    // Step 3: Separate cloned list
    curr = head;
    Node* cloneHead = head->next;

    while (curr) {
        Node* clone = curr->next;
        curr->next = clone->next;

        if (clone->next)
            clone->next = clone->next->next;

        curr = curr->next;
    }

    return cloneHead;
}

int main() {
    // Creating sample list: 1 <-> 2 <-> 3
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(3);
    head->next->next->prev = head->next;

    // Random connections
    head->random = head->next->next;        // 1 -> 3
    head->next->random = head;              // 2 -> 1
    head->next->next->random = head->next;  // 3 -> 2

    cout << "Original List:\n";
    printList(head);

    Node* cloned = cloneDLL(head);

    cout << "\nCloned List:\n";
    printList(cloned);

    return 0;
}