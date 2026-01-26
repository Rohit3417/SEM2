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
        head = head->next ;
    }
    printf("\n");
}

void delete(struct node *head,int count)
{
    struct node *temp,*temp2;
    
    int pos ;
    printf("Enter position to to delete from the end :");
    scanf("%d",&pos);
    if(pos>count)
    {
        printf("Invalid position \n");
        return;
    }
    int i=1,condition = count - pos;
    temp = head ;

    while(i<=condition)
    {
        temp2 = temp ;
        temp = temp->next ;
        i++;
    }
    temp2->next = temp->next ;
    free(temp);
}

int main()
{
    struct node *newnode,*tail,*head;
    int choice,count = 0;
    do{
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter data : ");
        scanf("%d",&newnode->data);
        if(head == 0)
        {
            head = newnode;
            tail = newnode ;
            count++;
        }
        else{
            tail->next = newnode ;
            tail = newnode ;
            count++;                                 //count = no. of node created
        }
        tail->next = 0;
        printf("Do you want to enter one more data : (1/0)");
        scanf("%d",&choice);
    }while(choice);
    display(head);
    delete(head,count);
    display(head);

}