#include<stdio.h>
#include<stdlib.h>

//REVERSE THE CLL

struct node{
    int data;
    struct node *next;
};

void display(struct node *head);
void reverse(struct node **head);

int main()
{
    struct node *head,*newnode1,*newnode2,*newnode3;
    head = (struct node *)malloc(sizeof(struct node));
    newnode1 = (struct node *)malloc(sizeof(struct node));
    newnode2 = (struct node *)malloc(sizeof(struct node));
    newnode3 = (struct node *)malloc(sizeof(struct node));
    head->data = 10;
    newnode1->data = 20;
    newnode2->data = 30;
    newnode3->data = 20;
    head->next = newnode1;
    newnode1->next = newnode2;
    newnode2->next = newnode3;
    newnode3->next = head;

    display(head);
    reverse(&head);
    printf("\n");
    display(head);


}

void display(struct node *head)
{
    struct node *temp ;
    temp = head;
    while(temp->next != head)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("%d",temp->data);
}

void reverse(struct node **head)
{
    struct node *temp,*prev,*current,*nextnode;
    current = nextnode = *head;
    prev = 0;
    while(current->next != *head)
    {
        nextnode = nextnode->next;
        current->next = prev ;
        prev = current;
        current = nextnode;
    }
    nextnode->next->next = current;
    current->next = prev;
    *head = current;
}           