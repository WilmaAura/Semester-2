#include <iostream>
using namespace std;
    /* 
        Kasus:
        1. Insert last 8, 9, 11
        2. Insert first 7, 5
        3. Delete last
        4. Output: 5, 7, 8, 9
    */
    struct Node {
        int data;
        Node* prev;
        Node* next;
    }; typedef Node node;
    
    node* head = nullptr;
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
            head->prev = newNode;
            head = newNode;
        }
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

    void deleteLast(node*& head){
        if (head==nullptr){
            cout << "List kosong" <<endl;
            return;
        }
        if (head->next==nullptr){
            delete head;
            head = nullptr;
            return;
        }

        node* current = head;
        while (current->next->next!= nullptr){
            current = current->next;
        }

        node* temp = current->next; //menyimpan alamat node terakhir
        current->next = nullptr; 
        delete temp; 
    }

    void displayList (node* head){
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
    int main(){
        insertLast(head, 8);
        insertLast(head, 9);
        insertLast(head, 11);
        displayList(head);

        insertFirst(head, 7);
        insertFirst(head, 5);
        displayList(head);

        deleteLast(head);
        displayList(head);
    }