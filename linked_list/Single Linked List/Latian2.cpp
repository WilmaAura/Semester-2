#include <iostream>
using namespace std;

    class node{
    public:
        int data;
        node* next;
        node *head, *tail;

        void printList(){
            node* temp = head;
            while (node *temp){

            }
        } 
    };

    
    
int main (){
    node n;
    system ("clear");
     
    node* head = new node ();
    node* second = new node();
    node* third = new node ();

    head->data = 1;
    head -> next = second;

    return 0;
}