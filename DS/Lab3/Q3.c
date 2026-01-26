#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

int display(struct node *head);
void insertAtend(struct node **tail);

int main()
{
    struct node *newnode,*tail,*head;
    head = 0;
    int choice,newData;
    do
    {
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter data for new node : ");
        scanf("%d",&newnode->data);
        if(head == 0)
        {
            head = newnode;
            tail = head ;
        }
        else
        {
            tail->next = newnode ;
            tail = newnode;
        }
        tail->next = 0;
        printf("Do you want to enter one more node\n");
        scanf("%d",&choice);
    }while(choice);
    display(head);
    insertAtend(&tail);
    printf("New list is given as : ");
    display(head);
}

int display(struct node *head)
{
    if(head == 0)
    {
        printf("No node present\n");
    }
    else if (head->next == 0)
    {
        printf("Single node presnt\n");
    }
    else{
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
}

void insertAtend(struct node **tail)
{
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter data to insert at the end :");
    scanf("%d",&newnode->data);
    (*tail)->next = newnode;
    newnode->next = 0;
}