#include<stdio.h>
#include<stdlib.h>


//MERGE SORT OF LINKED LIST

struct node {
    int data;
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
            l1 = l1->next ;
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
    display(dummy.next);
}

int main()
{
    struct node *head1,*head2,*newnode1,*newnode2,*newnode3,*newnode4;
    head1 = (struct node *)malloc(sizeof(struct node));
    head2 = (struct node *)malloc(sizeof(struct node));
    newnode1 = (struct node *)malloc(sizeof(struct node));
    newnode2 = (struct node *)malloc(sizeof(struct node));
    newnode3 = (struct node *)malloc(sizeof(struct node));
    newnode4 = (struct node *)malloc(sizeof(struct node));
    head1->data = 1;
    head2->data = 2;
    newnode1->data = 4;
    newnode2->data = 8;
    newnode3->data = 3;
    newnode4->data = 9;
    head1->next = newnode1;
    newnode1->next = newnode2;
    newnode2->next = 0;
    head2->next = newnode3;
    newnode3->next = newnode4;
    newnode4->next = 0;

    printf("List 1 : ");
    display(head1);
    printf("\n");
    printf("List2 : ");
    display(head2);
    printf("\nSorted and merged list is : ");
    sort(head1,head2);
}