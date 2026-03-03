#include<stdio.h>
#include<stdlib.h>

//ROTATE DOUBLY LINKED LIST

struct node{
    int data;
    struct node *next;
    struct node *prev;
};

void display(struct node *head);
void rotate(struct node **head,int k);

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
    int k;
    printf("\nEnter a number to rotate that many times : ");
    scanf("%d",&k);
    rotate(&head,k);
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

void rotate(struct node **head,int k)
{
    int count = 0;
    struct node *temp;
    temp = *head;
    while(temp != 0)
    {
        temp = temp ->next;
        count++;
    }
    temp = *head;
    k = k%count;
    for(int i=0;i<k;i++)
    {
        
        while(temp->next != 0)
        {
            temp = temp->next;
        }
        temp->prev->next = 0;
        temp->prev = 0;
        temp->next = *head;
        *head = temp;
    }
}