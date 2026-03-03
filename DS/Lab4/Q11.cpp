#include<iostream>
#include<vector>
using namespace std;

//MERGE SORTING K LISTS

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int data)
      {
        val = data;
        next = nullptr;
      }
 };
 
class Solution {
public:
    ListNode *merge(ListNode*l1,ListNode*l2)
    {
        ListNode dummy(-1);
        ListNode*temp = &dummy;
        dummy.val = -1;
        while(l1 != NULL && l2!= NULL)
        {
            if(l1->val <= l2->val)
            {
                temp->next = l1;
                l1 = l1->next;
            }
            else 
            {
                temp->next = l2;
                l2 = l2->next;
            }
            temp = temp->next  ;
        }
        if(l1 != NULL)
        {
            temp->next = l1;
        }
        else if(l2 != NULL)
        {
            temp->next = l2;
        }
        return dummy.next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0)
        {
            return NULL;
        }
        ListNode *head;
        head = lists[0];
        if(lists.size() == 1)
        {
            return head;
        }
        for(int i=1;i<lists.size();i++)
        {
            head = merge(head,lists[i]);
        }
        return head;
    }
};

int main()
{
    //List 1: 1 -> 4 -> 5 
    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(5);

    //  List 2: 1 -> 3 -> 4 
    ListNode* l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);

    //  List 3: 2 -> 6 
    ListNode* l3 = new ListNode(2);
    l3->next = new ListNode(6);

    // Put lists inside vector
    vector<ListNode*> lists;
    lists.push_back(l1);
    lists.push_back(l2);
    lists.push_back(l3);

    
    Solution obj;
    ListNode* result = obj.mergeKLists(lists);

    
    while(result != NULL)
    {
        cout << result->val << " ";
        result = result->next;
    }

    return 0;
}