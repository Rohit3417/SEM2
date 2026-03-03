#include<stdio.h>
#include<stdlib.h>

//REMOVE DUPLICATES FROM DLL

struct node{
    int data;
    struct node *next;
    struct node *prev;
};

void display(struct node *head);
void removeDuplicates(struct node **head);

int main()
{
    struct node *head,*newnode1,*newnode2,*newnode3;
    head = (struct node *)malloc(sizeof(struct node));
    newnode1 = (struct node *)malloc(sizeof(struct node));
    newnode2 = (struct node *)malloc(sizeof(struct node));
    newnode3 = (struct node *)malloc(sizeof(struct node));
    head->data = 5;
    newnode1->data = 2;
    newnode2->data = 4;
    newnode3->data = 2;
    head->next = newnode1;
    head->prev = 0;
    newnode1->next = newnode2;
    newnode1->prev = head;
    newnode2->next = newnode3;
    newnode2->prev = newnode1;
    newnode3->next = 0;
    newnode3->prev = newnode2;

    display(head);
    removeDuplicates(&head);
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

void removeDuplicates(struct node **head)
{
    struct node *temp1,*temp2;
    temp1 = *head;
    while(temp1 != 0)
    {
        temp2 = temp1->next;
        while(temp2 != 0)
        {
            if(temp1->data == temp2->data)
            {
                if(temp1 == *head && temp1->next != temp2)
                {
                    *head = temp1->next;
                    temp2->next->prev = temp2->prev;
                    temp2->prev->next = temp2->next;
                }
                else if(temp1->next == temp2 && temp1 == *head)
                {
                    *head = temp1->next->next;
                    temp2->next->prev = 0;
                }
                else if(temp2->next == 0)
                {
                    temp1->next->prev = temp1->prev;
                    temp1->prev->next = temp1->next;
                    temp2->prev->next = 0;
                }
                else
                {
                    temp1->next->prev = temp1->prev;
                    temp1->prev->next = temp1->next;
                    temp2->next->prev = temp2->prev;
                    temp2->prev->next = temp2->next;
                }
                
            }
           
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
}