#include<stdio.h>
#include<stdlib.h>

//SPLIT CIRCULAR LIST INTO TWO

struct node{
    int data;
    struct node *next;
};

void display(struct node *head);
void split(struct node *head);

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
    newnode1->next = newnode2;
    newnode2->next = newnode3;
    newnode3->next = head;

    display(head);
    split(head);


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

void split(struct node *head)
{
    int count = 1;
    struct node *temp ;
    temp = head;
    while(temp->next != head)
    {
        temp = temp->next;
        count++;
    }
    temp = head;
    int i=1;
    printf("\nFirst half : ");
    while(i<=count/2)
    {
        printf("%d ",temp->data);
        temp = temp->next;
        i++;
    }
    printf("\nSecond half : ");
    
    while(temp != head)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
}