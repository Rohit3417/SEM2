#include<stdio.h>
#include<stdlib.h>
//Reversing only a specific group of nodes from start

struct node{
    int data ;
    struct node *next;
};

void reverse(struct node **head,int count);
void display(struct node *head);

int main()
{
    struct node *head,*temp,*newnode;
    head = 0;
    int choice,count = 0;
    do
    {
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter data for new node : ");
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
        count++;
        scanf("%d",&choice);
    }while(choice);
    printf("Initial list : ");
    display(head);
    reverse(&head,count);
    display(head);
}

void reverse(struct node **head,int count)
{
    struct node *current,*prev,*nextnode,*temp,*temp2;
    prev = 0;
    int k,i,p;
    current = nextnode = *head;
    printf("Enter the no. of nodes that should be reversed :");
    scanf("%d",&k);
    int cond = count/k;
    printf("%d\n",cond);
    temp2 = current;
    for(int j=0;j<cond;j++)
    {
        
        i=1;
        while(i<=k)
        {
            if(current == *head)
            {
                temp = current;
            }
            nextnode = nextnode->next ;
            current ->next = prev ;
            prev = current ;
            current = nextnode;
            i++;
        }
        if(j==0)
        {
            *head = prev ;
            temp->next = current ;   
        }
        else
        {
            temp2->next = prev;
            temp2 = prev->next;
        }
        p=1;
        prev = current;
        while(p<=k)
        {
            prev = prev->next ;
            p++;
        }
         
    }
}

void display(struct node *head)
{
    if(head == 0)
    {
        printf("No node present\n");
    }
    else if (head->next == 0)
    {
        printf("Single node presnt\n");
    }
    else{
        struct node *temp;
        temp = head ;
        while(temp != 0)
        {
            printf("%d ",temp->data);
            temp = temp -> next ;
        }
        printf("\n");
    }
}