#include<iostream>
using namespace std;
    /* 
        Kasus:
        1. Insert First 9, 8
        2. Delete First 
        3. Insert Last 10, 11, 12
        4. Output: 9, 10, 11, 12
    */

    struct Node {
        int data;
        Node* prev;
        Node* next;
    }; typedef Node node;
    node* head =nullptr;
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
int main (){
    insertFirst(head, 9);
    insertFirst(head, 8);
    displayList(head);

    deleteFirst(head);
    displayList(head);
    
    insertLast(head, 10);
    insertLast(head, 11);
    insertLast(head, 12);
    displayList(head);
    return 0;
}