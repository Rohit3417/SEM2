    #include <stdio.h>
#include <stdlib.h>
#include <limits.h>

//MAX SUM SUBLIST

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Create new node
struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Insert at end
void insertEnd(struct Node** head, int val) {
    struct Node* newNode = createNode(val);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

// Print list
void printList(struct Node* head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Maximum Sum Sublist Function
void maxSumSublist(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    int max_sum = INT_MIN;
    int curr_sum = 0;

    struct Node* start = head;
    struct Node* end = head;
    struct Node* temp_start = head;

    struct Node* curr = head;

    while (curr) {
        curr_sum += curr->data;

        if (curr_sum > max_sum) {
            max_sum = curr_sum;
            start = temp_start;
            end = curr;
        }

        if (curr_sum < 0) {
            curr_sum = 0;
            temp_start = curr->next;
        }

        curr = curr->next;
    }

    printf("\nMaximum Sum = %d\n", max_sum);
    printf("Sublist: ");

    struct Node* temp = start;
    while (temp != end->next) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int n, value;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        insertEnd(&head, value);
    }

    printf("\nDoubly Linked List:\n");
    printList(head);

    maxSumSublist(head);

    return 0;
}