#include <iostream>
using namespace std;

    //komponen dari node
    struct node {
        int data;
        node* next; //alamat

    };
    node* head = nullptr; //nullptr menandakan list kosong

    int batasAntrian;
    //-> adalah cara akses pointer

    //menambahkan dari depan
    void insertFront (int value){
        node* newNode = new node; //membuat node baru
        newNode -> data = value; //Isi data
        newNode->next = head;
        head = newNode; //node baru menjadi node paling depan atau head
    }

    void insertBack(int value){
        node* newNode = new node;
        newNode -> data = value; //Isi data
        newNode -> next = nullptr; //karena dia dibelakang maka next harus = penanda akhir list yaitu nullptr

        //kondisi jika list masih kosong
        if (head == nullptr){
            head = newNode; //head diisi oleh new node
            return; 
        }
    
        node* temp = head; //mulai dari node pertama
        while (temp->next != nullptr){ //kalau masih ada data maka looping akan terus jalan
            temp = temp->next;
            }
            temp->next = newNode; //sambungkan ke node baru di bagian terakhir
    }

    void deleteValue(int value){

        //cek apakah list kosong atau tidak
        if (head == nullptr){
            cout << "List kosong" << endl;
            return; //kalau kosong langsung keluar
        }
        
        //Hapus data jika data di head
        if (head-> data == value){
            node* temp = head; //simpan alamat head di temp
            head = head->next; 
            delete temp; //hapus node lama
            cout << "Node dengan nilai: " << value << " dihapus" << endl;
            return;
        }

        //Hapus data selain di head
        node* temp = head; //pointer untuk menulusuri node satu per satu
        node* prev = nullptr; //menyimpan node sebelum temp

        while (temp != nullptr && temp->data != value){
            prev = temp;
            temp = temp -> next;
        }
        if (temp == nullptr){
            cout << "Data tidak ditemukan";
            return;
        }
        prev->next = temp->next;
        delete temp; 
        cout << "Node dengan nilai: " << value << " dihapus" << endl;
    }

    void printList(){
        node* temp = head;
        cout << "Print list: ";
        while (temp != nullptr){
            cout << temp -> data << " -> "; //menampilkan data
            temp = temp -> next;
        }
        cout << "NULL" << endl; //tail
    }
    
int main (){

    int pilihan, data;
    
    do {
        cout << "MENU SINGLE LINKED LIST" << endl;
        cout << "1. Tambah di depan" << endl;
        cout << "2. Tambah di belakang"<< endl;
        cout << "3. Tampilkan list" << endl;
        cout << "4. Delete value" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilih: ";
        cin >> pilihan;
            switch (pilihan){
            case 1:
                cout << "Masukkan data: ";
                cin >> data;
                insertFront(data);
                cout << endl;
                break;
            case 2:
                cout << "Masukkan data: ";
                cin >> data;
                insertBack(data);
                cout << endl;
                break;
            case 3:
                printList();
                cout << endl;
                break;

            case 4:
                cout << "Masukkan nilai yang ingin dihapus: ";
                cin >> data;
                deleteValue(data);
                cout << endl;
                break;
            case 0:
                cout << "Program done" << endl;
                break;
            default:
                cout << "Pilihan salah" << endl;
        }
        
    } while (pilihan != 0);
    return 0;
}