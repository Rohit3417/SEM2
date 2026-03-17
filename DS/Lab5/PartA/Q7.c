#include<stdio.h>
#include<stdlib.h>

//MERGE SORT 2 LISTS

struct node{
    int data;
    struct node *next;
    struct node *prev;
};

void display(struct node *head);
void sort(struct node *l1,struct node *l2)
{
    struct node dummy;
    struct node *tail = &dummy;
    dummy.next = 0;
    while(l1 != 0 && l2 != 0)
    {
        if(l1->data <= l2->data)
        {
            tail->next = l1;
            l1 = l1->next  ;
        }
        else
        {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }
    if(l1 != 0)
    {
        tail->next = l1; 
    }
    else if (l2 != 0)
    {
        tail->next = l2;
    }
    printf("\n After sorting and merging : \n");
    display(dummy.next);
}

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

    struct node *head2,*newnode4,*newnode5,*newnode6;
    head2 = (struct node *)malloc(sizeof(struct node));
    newnode4 = (struct node *)malloc(sizeof(struct node));
    newnode5 = (struct node *)malloc(sizeof(struct node));
    newnode6 = (struct node *)malloc(sizeof(struct node));
    head2->data = 1;
    newnode4->data = 2;
    newnode5->data = 3;
    newnode6->data = 4;
    head2->next = newnode4;
    head2->prev = 0;
    newnode4->next = newnode5;
    newnode4->prev = head2;
    newnode5->next = newnode6;
    newnode5->prev = newnode4;
    newnode6->next = 0;
    newnode6->prev = newnode5;
    display(head);
    printf("\n");
    display(head2);
    sort(head,head2);
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