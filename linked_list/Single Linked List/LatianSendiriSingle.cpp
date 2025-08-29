#include <iostream>
using namespace std;

    struct Node{
        char data;
        Node* next;
    };
    typedef struct Node node;

    node* head = nullptr;
    node* last = nullptr;
    int batasAntrian = 0;

    node* createNode(char value){
        node* newNode = new node;
        newNode->data= value;
        newNode-> next = nullptr;
        return newNode;
    }

    void jumlahData(){ 
        cout << "Jumlah data: " << batasAntrian << endl;
    }

    void insertFirst(char value){
        if (batasAntrian >= 10){
            cout << "Sudah batas maksimum";
            return;
        }
        node* newNode = createNode(value);
        newNode->next = head; //pointer newNode akan menunjuk ke head
        head = newNode;
        batasAntrian++;
    }

    void insertLast(char value){
        if (batasAntrian >= 10){
            cout << "Sudah batas maksimum";
            return;
        }

        node* newNode = createNode(value);
        newNode->next = nullptr;
        
        if (head == nullptr){
            head = newNode;
            return; //keluar
        }
        node* temp = head;
        while (temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = newNode;
        batasAntrian++;        
    }
    
    void insertAfter(node* prevNode, char value){
        if (batasAntrian >= 10){
            cout << "Sudah batas maksimum";
            return;
        }

        if (head == nullptr){
            cout << "Node sebelumnya tidak boleh NULL." << endl;
            return;
        }

        node* newNode = createNode(value);
        newNode->next = prevNode->next; 
        //misal a -> b -> c mau disisipkan dengan x setelah b
        //maka a -> b -> x -> c -> NULL
        //  newNode -> next = prevNode->next adalah x yang menunjuk ke node c
        prevNode->next = newNode;
        batasAntrian++;
    }
    void deleteFirst(){
        if (head == nullptr){
            cout << "list kosong" << endl;
            return;
        }

        if (head){
            node* temp = head; 
            head = head->next; 
            delete temp;
        }
        batasAntrian--;
    }
    void deleteValue(char value){
        if (head == nullptr){
            cout << "List kosong" << endl;
            return;
        }

        //Hapus data jika value di head
        if (head->data == value){
            node* temp = head;
            head = head->next;
            delete temp;
            cout << "Node dengan value: " << value << " dihapus" << endl;
            return;
        }


        //Hapus data selain di head
        node* prev = head;
        node* current = head->next;
        while (current != nullptr && current->data != value){
            prev = current; 
            current = current->next;
        }

        if (current == nullptr){
            cout << "Data tidak ditemukan";
            return;
        }
        prev->next = current->next;
        delete current;
        cout << "Data dengan value: " << value << " telah dihapus." << endl;
        batasAntrian--;
    }

    void deleteAfter(node* head, char value){
        node *prev = head;
        while (prev !=nullptr && prev->data != value){
            prev = prev->next;
            cout << prev;
        }
        if (prev != nullptr && prev->next != nullptr){ //cek data yang mau dihapus masih ada data atau tidak setelah node tersebut
            node *target = prev->next; //data disimpan di pointer prev
            prev->next = target->next;
            delete target;
        }
        else {
            cout << "Data " << value << " telah dihapus." << endl;
        }
        batasAntrian--;
    }
    void deleteLast(){
        
        if (head == nullptr)
        {
            cout << "Tidak ada list" << endl;
            return;
        }

        if (head->next == nullptr){ //delete data jika hanya satu list
            delete head;
            head = nullptr; //artinya list sekarang kosong
            return;
        }

        node *temp = head; //temp digunakan untuk traversal(penjelajahan list)
        node *prev = nullptr; //menyimpan node sebelum temp
        while (temp->next != nullptr){ //looping sampai node terakhir
            prev = temp; 
            temp = temp->next;
        }
        delete temp;

        if (prev!= nullptr){ //jika data lebih dari satu
            prev->next = nullptr; //pointer node sebelum temp menjadi nullptr
        }
        else {
            head = nullptr; //list kosong
        }
    }

    void printList(){
        if (head ==nullptr){
            cout << "List kosong" << endl;
            return;
        }

        node* temp = head; //mulai dari awal
        cout << "Isi list: ";
        while (temp != nullptr){
            cout << temp->data << " | " << temp->next << " -> ";
            temp = temp->next;
        }
        cout << endl;
        cout << "Alamat head: " << head << endl;
    }

int main (){
    int pilihan;
    char data;
    while (pilihan != 0)  {
        cout << "Menu single linked list" << endl;
        cout << "--------------------------" << endl;
        cout << "1. Insert First " << endl;
        cout << "2. Insert Last" << endl;
        cout << "3. Delete First" << endl;
        cout << "4. Print List" << endl;
        cout << "5. Insert After " << endl;
        cout << "6. Menampilkan jumlah data " << endl;
        cout << "7. Delete Value " << endl;
        cout << "8. Delete After " << endl;
        cout << "9. Delete Last " << endl;
        cout << "0. Out" << endl;
        cout << "Pilih (contoh 1): ";
        cin >> pilihan;
        switch (pilihan){

            case 1:
                cout << "Masukkan data: "; cin >> data;
                insertFirst(data);
                break;
            case 2:
                cout << "Masukkan data: "; cin >> data;
                insertLast(data);
                break;
            case 3:
                deleteFirst();
                break;
            case 4:
                printList();
                break;
            case 5:{
                char target;
                cout << "Masukkan data node yang mau disisipkan setelah: ";
                cin >> target;       
                cout << "Masukkan data: "; 
                cin >> data;

                node* temp = head;
                while (temp != nullptr && temp->data != target){
                    temp = temp->next;
                } 
                if (temp == nullptr){
                    cout << "List kosong " << endl;
                }
                else {
                    insertAfter(temp, data);
                }
                break;
            }
            case 6:
                jumlahData();
                break;
            
            case 7:
                cout << "Data yang ingin dihapus: "; cin >> data;
                deleteValue(data);
                break;
            
            case 8:
                char target;
                cout << "Masukkan data node yang mau dihapus setelah: ";
                cin >> target;
                node *temp = head;
                while(temp != nullptr && temp->data != target){
                    temp = temp->next;
                }
                if (head == nullptr){
                    cout << "List Kosong" << endl;
                }
                else {
                    deleteAfter(temp, data);
                }
                case 9:
                    deleteLast();
                }
    }
    return 0;
}