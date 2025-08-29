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
            int batasAntrian;
            
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

            void insertLast (char value){
                node *newNode = createNode (value);
                newNode->data = value;
                newNode->next = nullptr;

                if (head==nullptr){ //jika data masih kosong maka otomatis menjadi head
                    head = newNode;
                    return;
                }
                node *temp = head;
                while (temp->next != nullptr){
                    temp = temp->next;
                }
                temp->next = newNode;
                batasAntrian++;
            }

            void insertAfter (char target, char value){
                
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

            void deleteFirst(){
                if (head == nullptr){
                    cout << "List kosong" << endl;
                    return;
                }
                node *temp = head;
                head = head->next;
                delete temp;
                batasAntrian--;
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
                cout << "Jumlah data: " << batasAntrian;
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
    int main()
    {
     
        linkedList list;
        int pilihan;
        char data, target;
        do
        {
            cout << "--- Menu Linked list ---" << endl;
            cout << "1. Insert first" << endl;
            cout << "2. Print List" << endl;
            cout << "3. Insert Last" << endl;
            cout << "4. Insert After" << endl;
            cout << "5. Delete First" << endl;
            cout << "6. Delete After" << endl;
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
                    cout << "Masukkan data:";
                    cin >> data;
                    list.insertLast(data);
                    break;
                case 4:
                    cout << "Masukkan data yang mau dimasukkan setelah: ";
                    cin >> target;
                    cout << "Masukkan data: ";
                    cin >> data;
                    list.insertAfter(target, data);
                    break;
                case 5:
                    list.deleteFirst();
                case 6:
                    cout << "Masukkan data yang mau didelete setelah: ";
                    cin >> target;
                    list.deleteAfter(target);
                    break;
                case 7:
                    cout << "Input data yang ingin dicari: ";
                    cin >> data;
                    list.search(data);
                case 0:
                    cout << "Keluar" << endl;
                
                    default:
                        cout << "Pilihan salah" << endl;
                }

        } while (pilihan != 0);
        return 0;
    }