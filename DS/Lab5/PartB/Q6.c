#include<stdio.h>
#include<stdlib.h>

//CIRCULAR TO LINEAR LINKED LIST CONVERSION 

struct node{
    int data;
    struct node *next;
};

void displayCircular(struct node *head);
void displayLinear(struct node *head);
void convert(struct node **head);

int main()
{
    struct node *head,*newnode1,*newnode2,*newnode3,*newnode4;
    head = (struct node *)malloc(sizeof(struct node));
    newnode1 = (struct node *)malloc(sizeof(struct node));
    newnode2 = (struct node *)malloc(sizeof(struct node));
    newnode3 = (struct node *)malloc(sizeof(struct node));
    newnode4 = (struct node *)malloc(sizeof(struct node));
    head->data = 10;
    newnode1->data = 20;
    newnode2->data = 30;
    newnode3->data = 40;
    newnode4->data = 50;
    head->next = newnode1;
    newnode1->next = newnode2;
    newnode2->next = newnode3;
    newnode3->next = newnode4;
    newnode4->next = head;

    displayCircular(head);
    convert(&head);
    displayLinear(head);

}

void displayCircular(struct node *head)
{
    struct node *temp ;
    temp = head;
    while(temp->next != head)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("%d\n",temp->data);
}

void convert(struct node **head)
{
    struct node *temp;
    temp = *head;
    while(temp->next != *head)
    {
        temp = temp->next;
    }
    temp->next = 0;
}

void displayLinear(struct node *head)
{
    struct node *temp;
    temp = head;
    while(temp != 0)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    
}