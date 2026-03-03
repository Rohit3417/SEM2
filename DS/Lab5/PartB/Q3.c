#include<stdio.h>
#include<stdlib.h>

//INSERTING AN ELEMENT INTO SORTED LIST AT CORRECT POSITION

struct node{
    int data;
    struct node *next;
};

void display(struct node *head);
void insert(struct node **head,int num);

int main()
{
    struct node *head,*newnode1,*newnode2,*newnode3;
    head = (struct node *)malloc(sizeof(struct node));
    newnode1 = (struct node *)malloc(sizeof(struct node));
    newnode2 = (struct node *)malloc(sizeof(struct node));
    newnode3 = (struct node *)malloc(sizeof(struct node));
    head->data = 1;
    newnode1->data = 3;
    newnode2->data = 5;
    newnode3->data = 7;
    head->next = newnode1;
    newnode1->next = newnode2;
    newnode2->next = newnode3;
    newnode3->next = head;

    int num;
    display(head);
    printf("\nEnter a number to insert into the sorted list ");
    scanf("%d",&num);
    
    printf("After insertion : ");
    insert(&head,num);
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

void insert(struct node **head,int num)
{
    
    struct node *temp,*newnode,*temp2;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = num;
    newnode->next = 0;
    temp = temp2 = *head;
    while(num > temp->data && temp2->next != *head)
    {
        temp2 = temp;
        temp = temp->next ;
    }
   
    if(temp == *head && temp2->next != *head)
    {
        newnode->next = temp2;
        *head = newnode;
        while(temp->next != temp2)
        {
            temp = temp->next;
        }
        temp->next = *head;
    }
    else if(temp2->next != *head)
    {
        newnode->next = temp2->next;
        temp2->next = newnode;
    } 
    else{
        temp2->next = newnode;
        newnode->next = *head;
    }
    
}   
