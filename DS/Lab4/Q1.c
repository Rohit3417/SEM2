#include<stdio.h>
#include<stdlib.h>

//FIND THE MIDDLE ELEMENT OF LINKED LIST

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

int Middle(struct node *head,int count)
{
    int i=1;
    int condition = (count/2 + 1) ;
    struct node *temp;
    temp = head;
    while(i<condition)
    {
        temp = temp -> next ;
        i++;
    }
    return temp->data ;
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
    printf("\nTotal nodes = %d\n",count);
    printf("Middle element is : %d",Middle(head,count));
}