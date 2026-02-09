#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};

void display(struct node *head);
void delete(struct node **head,int k);

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
    
    int k;
    printf("\nEnter value of K : ");
    scanf("%d",&k);
    delete(&head,k);
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

void delete(struct node **head,int k)
{
    struct node *temp1,*temp2;
    temp1 = *head;
    temp2 = 0;
    while(temp2!= *head)
    {
        int i=1;
        while(i<k)
        {
            temp2 = temp1;
            temp1 = temp1->next;
            i++;
        }
        temp2->next = temp1->next;
        temp1 = temp1->next ;
        *head = temp1;
    }
}