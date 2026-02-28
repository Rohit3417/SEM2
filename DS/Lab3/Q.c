#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next;
};


void display(struct node *head)
{
    
    struct node *temp;
    temp = head ;
    while(temp != 0)
    {
        printf("%d ",temp->data);
        temp = temp -> next ;
        
    }
    printf("\n");
    
}

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
    struct node *temp1,*temp2,*temp3;
    temp1 = head;
    count = 1;
    while(temp1 != 0)
    {
        
        if(temp1->data%2 == 0 && temp1 != head)
        {
            temp2 ->next = temp1->next ;
            if(count == 1)
            {
                temp1->next = head;
                head = temp1;
                temp3 = head;
            }
            else{
                temp1->next = temp3->next ;
                temp3->next = temp1;
                temp3 = temp3->next;
            }
            count++;
        }
        temp2 = temp1;
        temp1 = temp1->next ;
    }
    printf("\n");
    display(head);
}