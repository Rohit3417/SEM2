#include<stdio.h>
#include<stdlib.h>

//COUNT NODES IN CLL

struct node{
    int data;
    struct node *next;
};

void display(struct node *head);
int count(struct node *head);


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

    display(head);
    int nodes = count(head);
    printf("Total number of nodes: %d" ,nodes);
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
    printf("%d\n",temp->data);
}

int count(struct node *head)
{
    int node = 1;
    struct node *temp ;
    temp = head;
    while(temp->next != head)
    {
        node++;
        temp = temp->next;
    }
    return node;
}