#include <iostream>
using namespace std;
class node
{
    public :
        int data;
        node *next;
        node(int data, node* next = NULL){
            this->data = data;
            this->next = next;
        }

};
class list{


public:
    node* head;
    list() {
        head = NULL;
    }


    void insert(int data) {
        node* nn = new node(data, NULL);
        
        if (head == NULL) {
            head = nn;
        } else {
            node* temp = head;
            while ( temp->next != NULL) {
                temp = temp->next;
            }
            
            temp->next = nn;
        }
    }
    void insertAtPos(int data,int n) {
        node* nn = new node(data, NULL);
        int i=1;
        node* pre;
        if (head == NULL) {
            head = nn;
        } else {
            node* temp = head;
            while (i<n && temp->next != NULL) {
                pre=temp;
                temp = temp->next;
                i++;
            }
            nn->next = pre->next;
            pre->next = nn;
        }
    }


    void display() {
        node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    void reverse() {

        node * temp = head->next;
        node * now = head; 
        node * pre = NULL;
        while (temp != NULL) {
            now->next = pre;
            pre = now;
            now = temp;
            temp = temp->next;
        }
        now->next=pre;
        head = now;
    }

};

int main() {
    list e1;

   e1.insert(2);
   e1.insert(6);
   e1.insert(98);
   e1.insert(34);
   e1.display();

   cout<<endl;
   e1.reverse();
   e1.display();
   

    
return 0;
}