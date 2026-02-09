#include<stdio.h>
#include<stdlib.h>

struct node{
    int data ;
    struct node *next;
};

int search(struct node *head1,struct node *head2)
{
    struct node *temp1,*temp2;
    int temp =0;
    temp1 = head1;
    temp2 = head2;
    while(temp1!=0)
    {
        temp2 = head2;
        while(temp2!=0)
        {
            if(temp1->next == temp2->next && temp1->next !=0)
            {

                return 1;
            }
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
    return 0;
}

int main()
{
    struct node *head1,*head2;
    head1 = (struct node *)malloc(sizeof(struct node));
    head2 = (struct node *)malloc(sizeof(struct node));
    head1->data = 4;
    head2->data = 5;
    struct node *newnode1,*newnode2,*newnode3,*newnode4,*newnode5;
    newnode1 = (struct node *)malloc(sizeof(struct node));
    newnode2 = (struct node *)malloc(sizeof(struct node));
    newnode3 = (struct node *)malloc(sizeof(struct node));
    newnode4 = (struct node *)malloc(sizeof(struct node));
    newnode5 = (struct node *)malloc(sizeof(struct node));

    newnode1->data = 1;
    newnode2->data = 8;
    newnode3->data = 6;
    newnode4->data = 1;
    newnode5->data = 5;
    head1->next = newnode1;
    newnode1->next = newnode2;
    head2->next = newnode3;
    newnode3->next = newnode4;
    newnode4->next = 0;
    newnode2->next = newnode5;
    newnode5->next = 0;

    if(search(head1,head2))
    {
        printf("Intersection present\n");
    }
    else{
        printf("Intersection not present\n");
    }

}