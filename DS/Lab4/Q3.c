#include<stdio.h>
#include<stdlib.h>
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

 

int main()
{
    int count=0;
    struct node *newnode,*temp,*head,*temp2,*temp3;
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
    temp=head ;
    
    while(temp!=0)
    {
        temp2 = temp->next;
        temp3 = temp;
        while(temp2 != 0)
        {
            if(temp2->data == temp->data)
            {
                 temp3->next = temp2->next ;
                 temp2 = temp2->next; 
            }
            else{
                temp3 = temp2;
                temp2 = temp2->next ;
            }

        }
        temp = temp->next ;
    }
    printf("After removing repeated numbers\n");
    display(head);
}