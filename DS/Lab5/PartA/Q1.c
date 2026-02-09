#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
    struct node *prev;
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
    newnode3->data = 40;
    head->next = newnode1;
    head->prev = 0;
    newnode1->next = newnode2;
    newnode1->prev = head;
    newnode2->next = newnode3;
    newnode2->prev = newnode1;
    newnode3->next = 0;
    newnode3->prev = newnode2;

    display(head);
    reverse(&head);
    printf("\n");
    display(head);


}

void display(struct node *head)
{
    struct node *temp ;
    temp = head;
    while(temp != 0)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
}

void reverse(struct node **head)
{
    struct node *temp,*temp2;
    temp = *head;
    while(temp->next != 0)
    {
        
        temp2 = temp->next ;
        temp->next = temp->prev ;
        temp->prev = temp2;
        temp = temp2;
    }
    temp2 = temp->next;
    temp->next = temp->prev;
    temp->prev = temp2;
    *head = temp; 
}