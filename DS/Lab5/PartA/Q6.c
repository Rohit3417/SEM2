#include<stdio.h>
#include<stdlib.h>

//CHECK FOR PALINDROME IN DLL

struct node{
    int data;
    struct node *next;
    struct node *prev;
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
    head->data = 1;
    newnode1->data = 2;
    newnode2->data = 2;
    newnode3->data = 1;
    head->next = newnode1;
    head->prev = 0;
    newnode1->next = newnode2;
    newnode1->prev = head;
    newnode2->next = newnode3;
    newnode2->prev = newnode1;
    newnode3->next = 0;
    newnode3->prev = newnode2;

    display(head);
    if(check(head))
    {
        printf("\nPalindrome");
    }
    else{
        printf("\nNot palindrome");
    }


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

int check(struct node *head)
{
    struct node *tail;
    int count = 1;
    tail = head;
    while(tail->next != 0)
    {
        tail = tail->next;
        count++;
    }
    count /= 2;
    for(int i=0;i<count;i++)
    {
        if(head->data != tail->data)
        {
            return 0;
        }
        head = head ->next;
        tail = tail->prev;
    }
    return 1;

}