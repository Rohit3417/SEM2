#include<stdio.h>
#include<stdlib.h>
/*Undo operation in insertion at the beginning of a linked list is the removal of the newly inserted first node
by updating the head pointer back to its original position.*/

struct node{
    int data;
    struct node *next;
};

int display(struct node *head);
void InsertFront(struct node **head,int newData);
void undo(struct node **head);

int main()
{
     struct node *newnode,*temp,*head;
    head = 0;
    int choice,newData;
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
    display(head);
    printf("Enter data to insert at the beginning\n");
    scanf("%d",&newData);
    InsertFront(&head,newData);
    printf("New list : ");
    display(head);
    undo(&head);
    printf("After undoing the new list : ");
    display(head);
}

int display(struct node *head)
{
    int count = 0;
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

void InsertFront(struct node **head,int newData)
{
    struct node *temp,*newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    temp = *head ;
    newnode->data = newData ;
    newnode->next = *head;
    *head = newnode;
    
}

void undo(struct node **head)
{
    struct node *temp;
    temp = *head;
    *head = (*head) ->next ;
    free(temp);
}