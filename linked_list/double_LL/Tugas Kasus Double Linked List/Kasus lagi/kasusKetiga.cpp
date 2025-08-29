#include <iostream>
using namespace std;
struct Node {
        int data;
        Node* prev;
        Node* next;
    }; typedef Node node;

    node* createNode(int value){
        node* newNode = new node;
        newNode->data = value;
        newNode->next = nullptr;
        newNode->prev = nullptr;
        return newNode;
    }
    void insertFirst (node*& head, int value){
        node* newNode = createNode (value);
        if (head == nullptr){
            head = newNode;
        }else{
            newNode -> next = head;
            head-> prev = head;
            head = newNode;
        }
    }
     void insertAfter(node*&head, int target, int value ){
        node* current= head;

        while (current!= nullptr && current->data != target){
            current = current->next;
        }

        if (head == nullptr){
            cout << "Data kosong" << endl;
            return;
        }

        node* newNode = createNode(value);
        newNode->next = current->next;
        newNode->prev = current;
        current->next = newNode;

        if (newNode->next != 0){
            newNode->next->prev = newNode;
        }
    }


    void deleteFirst(node*&head){
        
        if (head == nullptr){
            cout << "Tidak ada node" << endl;
            return;
        }
        node* current = head;
        head = head->next;
        if (head != nullptr){
            head->prev = nullptr;
        }
        delete current;
    }

    void deleteAfter(node*& head, int target){
        if (head == nullptr){
            cout << "Tidak ada list" << endl;
            return; 
        }

        node* current = head; 
        while(current != nullptr && current->data != target){
            current = current->next;
        }
        
        if (current == nullptr || current->next == nullptr){
            cout << "List " << target << " tidak ada" << endl;
            return;
        }
        node* temp = current->next; 
        current->next = temp->next; //c
        if (current->next != nullptr){
            current->next->prev = current;
        }
        delete temp;
    }

    void insertLast (node* &head, int value){
        node* newNode = createNode(value);
        if (head == nullptr){
            head = newNode;
        }
        else {
            node* current = head;
            while (current->next != nullptr){
                current = current->next;
            }
            newNode->next = nullptr;
            newNode->prev = current;
            current->next = newNode; 
        }
    }

    void displayList(Node* head) {
        Node* current = head;
        cout << "Informasi tentang setiap node:" << endl;
        while (current != nullptr) {
            cout << "Alamat: " << current << endl;
            cout << "Nilai: " << current->data << endl;
            cout << "Alamat prev: " << current->prev << endl;
            cout << "Alamat next: " << current->next << endl << endl;
            current = current->next;
        }
        cout << "---------------------------------------" <<endl;
    }


int main (){
    node* head = nullptr;
    insertFirst(head, 20);
    insertFirst(head, 15);
    insertFirst(head, 10);
    displayList(head);

    insertAfter(head, 15, 17);
    displayList(head);

    deleteAfter(head, 15);
    displayList(head);

    insertLast(head, 25);
    displayList(head);


    return 0;
}