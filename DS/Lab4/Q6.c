#include<stdio.h>
#include<stdlib.h>

//CHECKING FOR PALINDROME

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

struct node *reverse(struct node *head)
{
    struct node *prev,*current,*nextnode;
    prev = 0;
    current = nextnode = head ;
    while(current  != 0)
    {
        nextnode = nextnode ->next;
        current->next = prev ;
        prev = current;
        current = nextnode;
    }
    head = prev ;
    return head ;
}

int check(struct node *head,struct node *head2)
{
    while(head != 0 && head2 != 0)
    {
        if(head->data != head2->data)
        {
            return 0;
        }
        head = head -> next ;
        head2 = head2 -> next ;
    }
    return 1;
}

int main()
{
    int count=0;
    struct node *newnode,*temp,*head,*head2;
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
    head2 = reverse(head);
    display(head2);
    // display(head);
    if(check(head,head2))
    {
        printf("\nPalindrome");
    }
    else
    printf("\nNot palindrome");
}