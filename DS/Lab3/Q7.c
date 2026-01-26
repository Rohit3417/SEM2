#include<stdio.h>
#include<stdlib.h>
//Reversing only a specific group of nodes from start

struct node{
    int data ;
    struct node *next;
};

void reverse(struct node **head);
void display(struct node *head);

int main()
{
    struct node *head,*temp,*newnode;
    head = 0;
    int choice;
    do
    {
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter data for new node : ");
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
    printf("Initial list : ");
    display(head);
    reverse(&head);
    display(head);
}

void reverse(struct node **head)
{
    struct node *current,*prev,*nextnode,*temp;
    prev = 0;
    int k,i=1;
    current = nextnode = *head;
    printf("Enter the no. of nodes that should be reversed :");
    scanf("%d",&k);
    while(i<=k)
    {
        if(current == *head)
        {
            temp = current;
        }
        nextnode = nextnode->next ;
        current ->next = prev ;
        prev = current ;
        current = nextnode;
        i++;
    }*head = prev ;
    temp->next = current ;
}

void display(struct node *head)
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
        struct node *temp;
        temp = head ;
        while(temp != 0)
        {
            printf("%d ",temp->data);
            temp = temp -> next ;
        }
        printf("\n");
    }
}