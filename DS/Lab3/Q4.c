#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int data;
    struct node *next;
};

void insert(struct node **head);
int display(struct node *head);
void delete(struct node **head);

int main()
{
    struct node *newnode,*temp,*head;
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
    insert(&head);
    printf("After insertion: ");
    display(head);
    delete(&head);
    printf("After deletion the list is : ");
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

void insert(struct node **head)        
{
    int i=1,pos;
    struct node*temp,*temp2,*newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    temp = *head ;
    printf("Enter position to insert\n");
    scanf("%d",&pos);
    printf("Enter data for that node\n");
    scanf("%d",&newnode->data);
    if(pos == 1)
    {
        newnode->next = temp;
        *head = newnode;
    }
    else{
        while(i<pos)
        {
            temp2 = temp ;
            temp = temp -> next ;
            i++;
        }
        temp2 -> next = newnode ;
        newnode -> next = temp ;
    }
}

void delete(struct node**head)        //Deleting a node at given position
{
    struct node*temp,*temp2;
    int i=1,pos;
    printf("Enter position to delete\n");
    scanf("%d",&pos);
    temp = *head;
    if(pos == 1){
        *head = temp ->next ;
        free(temp);
    }
    else{
        while(i<pos)
        {
            temp2 = temp;
            temp = temp -> next ;
            i++;
        }
        temp2 -> next = temp -> next ;
        free(temp);
    }
}