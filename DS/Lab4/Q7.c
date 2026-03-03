#include<stdio.h>
#include<stdlib.h>

//ROTATE THE LINKED LIST

struct node{
    int data ;
    struct node *next;
};

void display(struct node *head)
{
    while(head != 0)
    {
        printf("%d ",head->data);
        head = head -> next ;
    }
}

void pushBackToFront(struct node **head)
{
    struct node *tail;
    tail = *head;
    while(tail->next->next!=0)
    {
        tail = tail->next;
    }
    tail->next->next = *head ;
    *head = tail->next;
    tail->next = 0;
}

int main()
{
    int count=0;
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
        count++;
    }while(choice);
    display(head);
    int k;
    printf("Enter the value of k : ");
    scanf("%d",&k);
    k=k%count;
    for(int i=0;i<k;i++)
    {
        pushBackToFront(&head);
    }
    printf("\n");
    display(head);
}
