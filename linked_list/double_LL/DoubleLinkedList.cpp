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

    void insertBefore(node*&head, int target, int value){
        if (head==nullptr){
            cout << "Kosong" << endl;
            return;
        }
        node* current = head;
        while(current!=nullptr && current->data!=target){
            current = current ->next;
        }
        if (head == nullptr){
            cout << "Data kosong" << endl;
            return;
        }
        node* newNode = createNode(value);
        newNode->prev = current->prev;
        newNode->next = current;
        if (current->prev != nullptr){
            current->prev->next = newNode;
        }
        else{
            head = newNode;
        }
        current->prev = newNode;
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
        else{
            current->next = nullptr;
        }
        delete temp;
    }

    void deleteBefore(node*&head, int target){
        if (head==nullptr){
            cout << "List kosong tidak bisa di delete" << endl;
            return;
        }
        node* current = head;
        while (current != nullptr && current->data != target){
            current = current->next;
        }

        if (current == nullptr){
            cout << "Target tidak ditemukan" << endl;
            return;
        }

        if (current->prev == nullptr){
            cout << "Tidak ada ";
        }

        node* temp = current->prev;
        current->prev = temp->prev;
        if (current->prev!=nullptr){
            current->prev->next= current;
        }
        else {
            head = current;
        }
        delete temp;
    }

    void printList (node* head){
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
    system ("clear");
    node* head = nullptr;
    int pilihan, value, target;
    while (pilihan != 0){
        cout << "Menu pilihan Double Linked list" << endl;
        cout << "1. Insert First" << endl;
        cout << "2. Insert After" << endl;
        cout << "3. Insert Last" << endl;
        cout << "4. Delete First" << endl;
        cout << "5. Delete After" << endl;
        cout << "6. Delete Last" << endl;
        cout << "7. Print List" << endl;
        cout << "8. Insert Before" << endl;
        cout << "9. Delete Before" << endl;
        cout << "0. Keluar" << endl;
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
            case 8: 
                cout << "Masukkan angka yang ingin dimasukkan sebelum angka: "; cin >>target;
                cout << "Masukkan angka yang ingin dimasukkan: "; cin >> value;
                insertBefore(head, target, value);
                break;
            case 9:
                cout << "Masukkan angka yang mau dihapus sebelum angka: "; cin >> target;
                deleteBefore(head, target);
                break;
            case 0:
                cout << "Keluar" << endl;
        }


    }
    return 0;
}