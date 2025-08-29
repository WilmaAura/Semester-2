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
        while (current->next->next != nullptr){
            current = current->next;
        }
        
        node* temp = current->next; //menyimpan alamat node terakhir
        current->next = nullptr; 
        delete temp; 
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

int main() {
    node* head = nullptr;

    
    insertFirst(head, 3);
    displayList(head);

    
    insertFirst(head, 2);
    displayList(head);

    
    insertFirst(head, 1);
    displayList(head);

    
    insertAfter(head, 2, 99);
    displayList(head);

    
    deleteLast(head);
    displayList(head);

    return 0;
}
