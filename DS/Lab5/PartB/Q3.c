#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};

void display(struct node *head);
struct node* insert(struct node **head,int num,int pos);

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

    int num,pos;
    display(head);
    printf("\nEnter a number to insert and its position : ");
    scanf("%d %d",&num,&pos);
    
    printf("After insertion : ");
    display(insert(&head,num,pos));

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

struct node* insert(struct node **head,int num,int pos)
{
    int count = 1;
    struct node *temp,*newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = num;
    newnode->next = 0;
    temp = *head;
    while(temp->next != *head)
    {
        temp = temp->next ;
        count++;
    }
    if (pos == count)
    {
        temp->next = newnode;
        newnode->next = *head ;
        return *head;
    }
    else if (pos == 1)
    {
        newnode->next = *head;
        *head = newnode;
        temp->next = *head;
        return *head;
    }
    else
    {
        temp = *head ;
        int i = 1;
        if(pos > count || pos == 0)
        {
            printf("Invalid position\n");
            return *head;
        }
        
        while(i<pos-1)
        {
            temp = temp->next ;
            i++;
        }
        newnode ->next = temp->next;
        temp->next = newnode;
        return *head;
    }
}   
