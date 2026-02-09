#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int d)
    {
        data = d;
        next = NULL;
    }
};

class List
{
    Node *head;
    Node *tail;

public:
    List()
    {
        head = tail = NULL;
    }

    void pushFront(int d)
    {
        Node *newNode = new Node(d);
        if (head == NULL)
        {
            head = tail = newNode;
            return;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }

    void pushBack(int d)
    {
        Node *newNode = new Node(d);
        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void popFront()
    {
        if (head == NULL)
        {
            cout << "LL is empty";
        }
        else
        {
            Node *temp = head;
            head = head->next;
            temp->next = NULL;
            delete temp;
        }
    }

    void printLL()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }

    void popBack()
    {
        if (head == NULL)
        {
            return;
        }
        Node *temp = head;
        while (temp->next != tail)
        {
            temp = temp->next;
        }
        temp->next = NULL;
        delete tail;
        tail = temp;
    }

    void insert(int d, int p)
    {
        if (p < 0)
        {
            return;
        }
        if (p == 0)
        {
            pushFront(d);
            return;
        }
        Node *temp = head;
        for (int i = 0; i < p - 1; i++)
        {
            if (temp == NULL)
            {
                return;
            }
            temp = temp->next;
        }
        Node *newNode = new Node(d);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    int search(int d)
    {
        int p = 0;
        Node *temp = head;
        while (temp->data != d)
        {
            if (temp->next == NULL)
            {
                return -1;
            }
            temp = temp->next;
            p++;
        }
        return p;
    }

    void reverse()
    {
        Node *prev = NULL;
        Node *curr = head;
        Node *next = NULL;

        while (curr != NULL)
        {
            next = curr->next;
            curr->next = prev;

            prev = curr;
            curr = next;
        }
        head=prev; 
    }
};

int main()
{
    List ll;
    ll.pushFront(1);
    ll.pushFront(2);
    ll.pushFront(3);
    // ll.pushBack(4);
    // ll.popFront();
    // ll.popBack();
    ll.insert(4, 0);
    if (ll.search(4) == -1)
    {
        cout << "not found" << endl;
    }
    else
    {
        cout << "at index " << ll.search(4) << endl;
    }

    ll.printLL();
    cout<<"\n";
    ll.reverse();
    ll.printLL();

    return 0;
}