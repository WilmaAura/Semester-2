#include <iostream>
using namespace std;

    /* 
        Kasus:
        1. Insert first 3, 2, 1
        2. Insert after 3, dengan angka 4
        3. Delete first
        4. Output: 2,3,4
    */
    struct Node {
        int data;
        Node* prev;
        Node* next;
    }; typedef Node node;
    node* head;
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

        if (newNode->next != nullptr){
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
    insertFirst(head, 3);
    insertFirst(head, 2);
    insertFirst(head, 1);
    displayList(head);

    insertAfter(head, 3, 4);
    displayList(head);

    deleteFirst(head);
    displayList(head);
    return 0;
}