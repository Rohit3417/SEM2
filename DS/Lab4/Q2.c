#include<stdio.h>
#include<stdlib.h>

//CYCLE DETECTION

struct node{
    int data ;
    struct node *next;
};

// void display(struct node *head)
// {
//     while(head != 0)
//     {
//         printf("%d ",head->data);
//         head = head -> next ;
//     }
// }

int CycleDetect(struct node *head)
{
    struct node *fast,*slow;
    fast = head;
    slow = head ;
    while(fast!=0 && fast->next != 0)
    {
        slow = slow->next ;
        fast = fast->next->next ;
        if(fast == slow)
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    int count=0;
    struct node *newnode,*temp,*head,*temp2;
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
            temp2 = temp;
            temp->next = newnode ;
            temp = newnode;
        }
        temp->next = 0;
        printf("Do you want to enter one more node\n");
        scanf("%d",&choice);
        count++;
    }while(choice);
    temp->next = temp2 ;
    
    printf("Total nodes = %d\n",count);
    if(CycleDetect(head))
    {
        printf("Cycle present\n");
    }
    else
    {
        printf("Cycle not present\n");
    }
}
