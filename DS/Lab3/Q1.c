#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next ;
};

int display(struct node *head);
void insertAthead(struct node **head);
void insertAtend(struct node *head);
void deleteByValue(struct node *head);
void deleteByPos(struct node *head,int);
void SearchValue(struct node *head);
void reverse(struct node *head);

int main()
{
    int count;
    struct node *newnode,*temp,*head;
    head = 0;
    int choice;
    do
    {
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter data for new node\n");
        scanf("%d",&newnode->data);
        if(head == 0)
        {
            head = newnode;
            temp = head ;
        }
        else
        {
            temp->next = newnode ;
            temp = newnode;
        }
        temp->next = 0;
        printf("Do you want to enter one more node\n");
        scanf("%d",&choice);
    }while(choice);
    printf("The single list node is : ");
    display(head);
    insertAthead(&head);
    display(head);
    insertAtend(head);
    deleteByValue(head);
    deleteByPos(head,count);
    SearchValue(head);
    printf("Reversing the nodes\n");
    reverse(head);
}

int display(struct node *head)
{
    int count =0;
    struct node *temp;
    temp = head ;
    while(temp != 0)
    {
        printf("%d ",temp->data);
        temp = temp -> next ;
        count++;
    }
    printf("\n");
    return count;
}

void insertAthead(struct node **head)
{
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter data for newnode to insert at head : ");
    scanf("%d",&newnode->data);
    newnode->next = *head ;
    *head = newnode ;
    printf("After insertion the list is as : ");
    
}

void insertAtend(struct node *head)
{
    struct node *newnode,*temp;
    temp = head ;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter data for newnode to insert at End : ");
    scanf("%d",&newnode->data);
    while(temp->next != 0)
    {
        temp = temp->next ;
    }
    temp->next = newnode;
    newnode->next = 0 ;
    display(head);
}

void deleteByValue(struct node *head)
{
    struct node *temp,*temp2;
    temp = head;
    int value;
    printf("Enter an element to search and delete its 1st occurence : ");
    scanf("%d",&value);
    if(temp->data == value)
    {
        head = temp->next ;
        free(temp);
        display(head);
    }
    else{
        while(temp->data != value)
        {
           temp2 = temp;
           temp = temp ->next;
        }
        if(temp == 0)
        {
           printf("No such value in the list\n");
        }
        else{
        temp2->next = temp ->next ;
        free(temp);
        display(head);
        }
    }
}

void deleteByPos(struct node *head,int count)
{
    struct node *temp1,*temp2;
    temp1 = head ;
    int pos,i=1;
    printf("Enter a positon to delete a node at that position :");
    scanf("%d",&pos);
    if(pos > count)
    {
        printf("Invalid position\n");
    }
    else
    {
        while(i<pos)
        {
            temp2 = temp1;                  //temp2 is previous one
            temp1 = temp1 -> next ;
            i++;
        }
        temp2 -> next = temp1 ->next ;
        free(temp1);
    }
    display(head);
}

void SearchValue(struct node *head)
{
    struct node *temp;
    temp = head ;
    int value,flag=0;
    printf("Enter a data to search :");
    scanf("%d",&value);
    while(temp->data != value)
    {
        temp = temp ->next;
    }
    if(temp == 0)
    {
        printf("Element not found\n");
    }
    else{
        printf("Element present\n");
    }
}

void reverse(struct node *head)
{
    struct node *nextnode,*current,*prev; 
    prev = 0;        
    current = head ;
    nextnode = head ;
    while(nextnode != 0)
    {
        nextnode = nextnode->next ;
        current -> next = prev ;
        prev = current ;
        current = nextnode;
    }
    head = prev;
    display(head);

}