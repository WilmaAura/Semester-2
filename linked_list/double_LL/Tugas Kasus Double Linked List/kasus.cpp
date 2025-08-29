#include <iostream>
using namespace std;
    /* 
    Kasus1: 
        1. Input first: 1 -> 2 -> 3
        2. Lalu delete angka 3
        3. Insert last angka 4
        4. lalu insert after 2 dengan angka 7
        5. output akhir 1 -> 2 -> 7 -> 4
    */

    /* 
    kasus 2
        1. Input last: 3 -> 2 -> 1
        2. insert after 3 dengan angka 8
        3. delete first
        4. Insert first 9
        5, Output akhir: 9 -> 8 -> 2 -> 1
    */
    
    /* 
    kasus 3
        1. Input first: 8->9->10
        2. Delete after 8 
        3. Insert last 11
        4. Output akhir: 8->10->11
    */
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

    void printList (node* head){ //tidak mengubah nilai head
        cout << "Informasi tentang setiap node: " << endl;
        node* temp = head;
        cout << "List: ";
        while (temp != nullptr){
            cout  << temp->prev<< " | " <<temp->data << " | " << temp->next << " -> ";
            temp= temp->next;
         }
         cout << endl;
         cout << "----------------------------------" << endl;

    }

int main (){
    system ("clear");
    node* head = nullptr;
    int pilihan, value, target;
    while (pilihan != 0){
        cout << "Menu pilihan Double Linked list" << endl;
        cout << "1. Insert First        |       5. Delete After " << endl;
        cout << "2. Insert After        |       6. Delete Last " << endl;
        cout << "3. Insert Last         |       7. Print List" << endl;
        cout << "4. Delete First        |       0. Keluar " << endl;
        cout <<"Pilih (contoh 1): ";cin >> pilihan;
        switch (pilihan){
            case 1:
                cout << "Masukkan angka: "; cin >> value;
                insertFirst(head, value);
                break;
            case 2:
                cout << "Masukkan angka yang ingin dimasukkan setelah angka: "; cin >>target;
                cout << "Masukkan angka yang ingin dimasukkan: "; cin >> value;
                insertAfter(head, target, value);
                break;
            case 3:
                cout << "Masukkan angka: "; cin >> value;
                insertLast(head, value);
                break;
            case 4:
                deleteFirst(head);
                break;
            case 5:
                cout << "Masukkan angka yang mau dihapus setelah angka: "; cin >> target;
                deleteAfter(head, target);
                break;
            case 6:
                deleteLast(head);
                break;
            case 7:
                printList(head);
                break;
            case 0:
                cout << "Keluar" << endl;
        }


    }
    return 0;
}