#include <stdio.h>
#include <stdlib.h>

//MERGING TWO CLL

struct Node {
    int data;
    struct Node* next;
};

struct Node* insertEnd(struct Node* head, int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;

    
    if (head == NULL) {
        newNode->next = newNode;
        return newNode;
    }

    struct Node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = head;

    return head;
}

struct Node* mergeCircular(struct Node* head1, struct Node* head2) {
    if (head1 == NULL) 
    return head2;
    if (head2 == NULL) 
    return head1;

    struct Node* temp1 = head1;
    struct Node* temp2 = head2;

    
    while (temp1->next != head1) {
        temp1 = temp1->next;
    }

    
    while (temp2->next != head2) {
        temp2 = temp2->next;
    }

    
    temp1->next = head2;
    temp2->next = head1;

    return head1;
}

void printList(struct Node* head) {
    if (head == NULL) return;

    struct Node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
}

int main() {
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;

    // 1 -> 2 -> 3
    head1 = insertEnd(head1, 1);
    head1 = insertEnd(head1, 2);
    head1 = insertEnd(head1, 3);

    // 4 -> 5 -> 6
    head2 = insertEnd(head2, 4);
    head2 = insertEnd(head2, 5);
    head2 = insertEnd(head2, 6);

    printf("List 1: ");
    printList(head1);

    printf("\nList 2: ");
    printList(head2);

    // Merge
    struct Node* mergedHead = mergeCircular(head1, head2);

    printf("\nMerged Circular List: ");
    printList(mergedHead);

    return 0;
}