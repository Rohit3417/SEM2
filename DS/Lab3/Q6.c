#include<stdio.h>
#include<stdlib.h>

//Floyd cycle detection fast and slow traversing and they must meet at one point

struct node{
    int data;
    struct node *next;
};

int cycleDetect(struct node *head);

int main()
{
    struct node *head,*newnode,*temp,*temp2;
    head = 0;
    int i=1 ;
    while(i<=7)
    {
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter data for node %d ",i);
        scanf("%d",&newnode->data);
        if(head == 0)
        {
            head = newnode;
            temp = head;
        }
        else{
            temp ->next = newnode;
            temp = temp ->next;
        }
        if(i==4)
        {
            temp2 = newnode ;
        }
        i++;
    }
    temp ->next = temp2;
    if(cycleDetect(head))
    {
        printf("Cycle is present");
    }
    else{
        printf("Cycle not present");
    }
}

int cycleDetect(struct node *head)
{
    struct node *slow,*fast;
    slow = head ;
    fast = head;
    while(fast!=0 && fast ->next != 0)
    {
        slow = slow ->next ;
        fast = fast->next->next ;
        if(slow == fast)
        {
            return 1;
        }
    }
    return 0;

}