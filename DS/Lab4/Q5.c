#include<stdio.h>
#include<stdlib.h>

//REVERSING NODES IN K GROUP

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

struct node * reverse(struct node *head,int k)
{
    int count=0;
    struct node *prev,*current,*nextnode,*temp;
    prev = nextnode = 0;
    current = head;
    while(current != NULL && count < k)
    {
        nextnode = current->next;
        current->next = prev;
        prev = current;
        current = nextnode;
        count++;
    }
    if(nextnode != NULL)
    {
        head->next = reverse(nextnode,k);
    }
    return prev;
}

int main()
{
    int count=0;
    struct node *newnode,*temp,*head;
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
    int k;
    printf("Enter number of nodes you want to reverse : ");
    scanf("%d",&k);
    head = reverse(head,k);
    display(head);
    
}