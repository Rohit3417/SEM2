#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
}; 

void displayNode(struct node*head)
{   int count=0;
    struct node*temp;
    temp = head ;
    while(temp != 0)
    {
        printf("%d ",temp->data);
        count++;
        temp = temp -> next ;
    }
    printf("\nNo. of nodes = %d\n",count);
}

void insert(struct node*head)        //Inserting at a given position
{
    int i=1,pos;
    struct node*temp,*temp2,*newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    temp = head ;
    printf("Enter position to insert\n");
    scanf("%d",&pos);
    printf("Enter data for that node\n");
    scanf("%d",&newnode->data);
    while(i<pos)
    {
        temp2 = temp ;
        temp = temp -> next ;
        i++;
    }
    temp2 -> next = newnode ;
    newnode -> next = temp ;
}

void delete(struct node*head)        //Deleting a node at given position
{
    struct node*temp,*temp2;
    int i=1,pos;
    printf("Enter position to delete\n");
    scanf("%d",&pos);
    temp = head;
    while(i<pos)
    {
        temp2 = temp;
        temp = temp -> next ;
        i++;
    }
    temp2 -> next = temp -> next ;
    free(temp);
}

int main()
{
    struct node *head,*fnode,*temp;
    head = 0;
    int choice = 1,count=0;
    while(choice)
    {
        fnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter data\n");
        scanf("%d",&fnode->data);
        fnode->next = 0;
        if(head == 0)
        {
            head = fnode ;
            temp = fnode;
        }
        else
        {
            temp->next = fnode;
            temp = fnode ;
        }
        printf("Do you want to continue (1/0)");
        scanf("%d",&choice);
    }
    displayNode(head);
    delete(head);
    displayNode(head);
}