#include <iostream>
using namespace std;

class linkedList {
    private:
        struct Node{
            char data;
            Node *next;
        };
        typedef Node node;
        node *head;
        int batasAntrian = 0;
        
    public:
        node* createNode(char value){
            node* newNode = new node;
            newNode-> data = value;
            newNode->next = nullptr;
            return newNode;
        }

        linkedList(){ //cunstructor
             head = nullptr;
        }

        void insertFirst (char value){
            if (batasAntrian >= 10){
                cout << "Sudah batas maksimum";
                return;
            }
            node *newNode =  createNode (value);
            newNode->next = head;
            head = newNode;
            batasAntrian++;
        }

        void insertAfter (char target, char value){
            if (batasAntrian >= 10){
                cout << "Sudah batas maksimum";
                return;
            }
                
            if (head == nullptr){
                cout << "Node sebelumnya tidak boleh NULL" << endl;
                return;
            }
            node *temp = head;
            while (temp != nullptr &&temp->data != target ){
                temp = temp->next;
            }
            node *newNode = createNode (value);
            newNode->next = temp->next;
            temp->next = newNode;
            batasAntrian++;
        }

        void deleteAfter (char target){
            node *prev = head;

            //Looping mencari value
            while (prev != nullptr && prev->data!= target){
                prev = prev->next; 
            }

            if (prev!= nullptr && prev->next != nullptr){ //cek apakah harus 
                //jika prev tidak sama dengan null dan prev pointer tidak sama dengan null
                node *target = prev->next;
                prev->next = target->next;
                delete target;
            }
            else{
                cout << "Data: " << target << " telah dihapus" << endl;
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
            batasAntrian--;
        }

        void search (char value){
            node *temp = head;
            while (temp != nullptr){
                if (temp->data = value){
                    cout << "Data ditemukan di alamat: " << temp << endl;
                }
                else {
                    cout << "data tidak ditemukan" << endl;
                }
                temp = temp->next;
            }
        }
        void jumlahData(){
            cout << "Jumlah data: " << batasAntrian << endl;
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
            jumlahData();
        }
};

int main (){
    linkedList list;
    int pilihan;
    char data, target;
    do
    {
        cout << "--- Menu Linked list ---" << endl;
        cout << "1. Insert first" << endl;
        cout << "2. Print List" << endl;
        cout << "3. Insert After" << endl;
        cout << "4. Delete After" << endl;
        cout << "5. Search" << endl;
        cout << "6. Delete Last" << endl;
        cout << "0. out" << endl;
        cout << "Pilih angka (contoh 1):";
        cin >> pilihan;
        cout << endl;

        switch (pilihan){
            case 1:
                cout << "Masukkan data: ";
                cin >> data;
                list.insertFirst(data);
                break;
            case 2:
                list.printList();
                break;
            case 3:
                cout << "Masukkan data yang mau dimasukkan setelah: ";
                cin >> target;
                cout << "Masukkan data: ";
                cin >> data;
                list.insertAfter(target, data);
                break;
            case 4:
                cout << "Masukkan data yang mau didelete setelah: ";
                cin >> target;
                list.deleteAfter(target);
                break;
            case 5:
                cout << "Input data yang ingin dicari: ";
                cin >> data;
                list.search(data);
                break;
            case 6:
                list.deleteLast();
                break;
            case 0:
                cout << "Keluar" << endl;
            
                default:
                    cout << "Pilihan salah" << endl;
            }

    } while (pilihan != 0);

    return 0;
}