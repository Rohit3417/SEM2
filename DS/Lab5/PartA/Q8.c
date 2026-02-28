#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
    struct node *prev;
};

void display(struct node *head);
void swap(struct node **head,int pos1,int pos2);

int main()
{
    struct node *head,*newnode1,*newnode2,*newnode3;
    head = (struct node *)malloc(sizeof(struct node));
    newnode1 = (struct node *)malloc(sizeof(struct node));
    newnode2 = (struct node *)malloc(sizeof(struct node));
    newnode3 = (struct node *)malloc(sizeof(struct node));
    head->data = 10;
    newnode1->data = 20;
    newnode2->data = 30;
    newnode3->data = 40;
    head->next = newnode1;
    head->prev = 0;
    newnode1->next = newnode2;
    newnode1->prev = head;
    newnode2->next = newnode3;
    newnode2->prev = newnode1;
    newnode3->next = 0;
    newnode3->prev = newnode2;

    display(head);
    swap(&head,2,3);
    printf("\n");
    display(head);


}

void display(struct node *head)
{
    struct node *temp ;
    temp = head;
    while(temp != 0)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
}

void swap(struct node **head,int pos1,int pos2)
{
    struct node *temp1,*temp2,*temp3;
    temp1 = temp2 = *head;
    int i=1;
        while(i<pos1)
        {
            temp1 = temp1->next;
            i++;
        }
        i=1;
        while(i<pos2)
        {
            temp2 = temp2->next;
            i++;
        }
        if(temp1->next != temp2)
        {
            temp2->prev->next = temp1;
            temp1->next->prev = temp2;
            if(pos1 > 1){
                temp1->prev->next = temp2;
            }
            temp3 = temp1->next ;
            temp1->next = temp2->next ;
            temp2->next = temp3;
            temp3 = temp1->prev ;
            temp1->prev = temp2->prev;
            temp2->prev = temp3;
            if(pos1 == 1)
            *head = temp2;
        }
        else if(temp1 == *head )
        {   
            temp2->next->prev = temp1;
            temp1->next = temp2->next;
            temp2->next = temp1;
            temp2->prev = temp1->prev;
            temp1->prev = temp2;
            *head = temp2;
        }
        else
        {
            temp1->prev->next = temp2;
            temp2->next->prev = temp1;
            temp1->next = temp2->next ;
            temp2->next = temp1;
            temp2->prev = temp1->prev;
            temp1->prev = temp2;
        }
        
}