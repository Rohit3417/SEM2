#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};

void display(struct node *head);
int check(struct node *head);

int main()
{
    struct node *head,*newnode1,*newnode2,*newnode3;
    head = (struct node *)malloc(sizeof(struct node));
    newnode1 = (struct node *)malloc(sizeof(struct node));
    newnode2 = (struct node *)malloc(sizeof(struct node));
    newnode3 = (struct node *)malloc(sizeof(struct node));
    head->data = 30;
    newnode1->data = 20;
    newnode2->data = 30;
    newnode3->data = 40;
    head->next = newnode1;
    newnode1->next = newnode2;
    newnode2->next = newnode3;
    newnode3->next = head;

    display(head);
    if(check(head))
    {
        printf("\nCircular Link list is sorted");
    }
    else{
        printf("\nCircular link list is not sorted");
    }


}

void display(struct node *head)
{
    struct node *temp ;
    temp = head;
    while(temp->next != head)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("%d",temp->data);
}

int check(struct node *head)
{
    struct node *temp1,*temp2;
    temp1 = head;
    temp2 = head->next ;
    while(temp1->next != head && temp2 != head)
    {
        if(temp2->data < temp1->data)
        {
            return 0;
        }
        temp1 = temp1->next ;
        temp2 = temp2->next ;
    }
    return 1;
}