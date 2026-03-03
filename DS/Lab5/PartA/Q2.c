#include<stdio.h>
#include<stdlib.h>

//FINDING PAIR SUCH THAT THEIR SUM = TARGET GIVEN

struct node{
    int data;
    struct node *next;
    struct node *prev;
};

void display(struct node *head);
void check(struct node *head,int sum);

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
    newnode3->data = 10;
    head->next = newnode1;
    head->prev = 0;
    newnode1->next = newnode2;
    newnode1->prev = head;
    newnode2->next = newnode3;
    newnode2->prev = newnode1;
    newnode3->next = 0;
    newnode3->prev = newnode2;

    int sum;
    display(head);
    printf("\nEnter sum : ");
    scanf("%d",&sum);
    check(head,sum);
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

void check(struct node *head,int sum)
{
    struct node *temp1,*temp2;
    temp1 = head;
    int c = 0;
    while(temp1 != 0)
    {
        temp2 = temp1->next;
        while(temp2 != 0)
        {
            if(temp1->data + temp2->data == sum)
            {
                printf("%d,%d\n",temp1->data,temp2->data);
                c = 1;
            }
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
    if(c == 0)
    {
        printf("No such pair found\n");
    }
}