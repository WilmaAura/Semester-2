#include <iostream>
using namespace std;

class Qnode{
    public:
        int data;
        Qnode* next;
        Qnode* prev;
        Qnode(int value): data(value), next(nullptr), prev(nullptr) {}      
    }; typedef Qnode qnode ;

    class queue{
    public:
        qnode* head;
        qnode* front;
        qnode* tail;
        int max;
        int count;
        int sisa;

        queue(): head(nullptr), front(nullptr), tail(nullptr), max(4), count(0), sisa(0) {}

        bool isEmpty(){
            return  head == nullptr;
        }

        bool isFull(){
            return count >= max;
        }

        bool sameNum(int value){
            qnode* temp = head;
            while (temp != nullptr){
                if (temp->data == value){
                    return true;
                }
                temp = temp->next;
            }
            return false;
        }

        void enqueueLast(int value){
            qnode* newNode = new qnode(value);
            if (isFull()){
                cout << endl;
                cout << "TIDAK BISA INPUT LAGI" << endl << endl;
                return;
            }
            if (sameNum(value)){
                cout << endl;
                cout << "DATA QUEUE TIDAK BISA SAMA, COBA LAGI!" << endl << endl;
                   return;
            }
            if (isEmpty()){
                head = newNode;
                front = newNode;
                tail = newNode;
            }else{
                newNode->prev = tail;
                tail->next = newNode;
                tail = newNode;
            }
            count++;
        }

        void dequeueFirst(){
            if (isEmpty()){
                cout << "Tidak bisa menghapus, queue kosong" << endl;
                return;
            }
            if (head->next == nullptr){
                delete head;
                head = tail = front = nullptr;
            }else{
                qnode* current = head;
                head = head->next;
                if(head != nullptr){
                    head->prev = nullptr;
                }
                delete current;
            }
            count--;
        }
        
        void enqueueBefore(int target, int value){
           if (isEmpty()){
                cout << "Tidak bisa menghapus, queue kosong" << endl;
                return;
            }
            if (isFull()){
                cout << endl;
                cout << "TIDAK BISA INPUT LAGI" << endl << endl;
                return;
            }
            if (sameNum(value)){
                cout << endl;
                cout << "DATA QUEUE TIDAK BISA SAMA, COBA LAGI!" << endl << endl;
                return;
            }

            qnode* current = head;
            while (current != nullptr && current->data != target){
                current = current -> next;
            }
            qnode* newNode = new qnode(value);
            newNode->prev = current->prev;
            newNode->next = current;
            if (current->prev != nullptr){
                newNode->prev->next = newNode;
            }
            else{
                head = newNode;
            }
            current->prev = newNode;
        }
        void dequeueAfter(int target){
            qnode* current = head;
            while (current != nullptr && current->data != target){
                current = current->next;
            }
            if (current == nullptr ){
                cout << "Data tidak ditemukan" << endl;
                return;
            }
            qnode* temp = current->next;
            current->next = temp->next;
            if (current->next != nullptr){
                current->next->prev = current;
            }else{
                current->next = nullptr;
            }
            delete temp;
        }   
        void printList (){
            sisa = max - count;
            qnode* current = head;
            cout << "Isi queue: ";
            while (current != nullptr){
                cout << current->data << " | " << current->next;
                if (current->next != nullptr){
                    cout << " <-> ";
                }
                current = current->next;
            }
            cout << endl;
            cout << "Max: "<< max << endl; 
            cout << "Jumlah Antrean: "<< count << endl; 
            cout << "Sisa: "<< sisa << endl; 
            cout << endl;
        }
        void setMax(int newMax){
                if (max < count){
                    cout << "MAX TIDAK BOLEH LEBIH KECIL DARI JUMLAH CURRENT DATA." << endl;
                    return;
                }
                max = newMax;
            }
    };

    

int main(){
    queue q;
    int pilihan, antrian, target;
    do{
        cout << "----------------------------------------------------" << endl;
        cout << "|                   ADMIN KLINIK                   |" << endl;
        cout << "----------------------------------------------------" << endl;
        cout << "| 1.Enqueue Last         " << " |" << " 6.Enqueue Before       |" << endl;
        cout << "| 2.Dequeue First        " << " |" << " 7.Dequeue Before       |" << endl;
        cout << "| 3.Enqueue After        " << " |" << " 8.Set newMax           |" << endl;
        cout << "| 4.Dequeue After        " << " |" << " 0.Exit                 |" << endl;
        cout << "| 5.PrintList            " << " |" << "                        |" << endl;
        cout << "----------------------------------------------------" << endl << endl;
        cout << "Pilih (contoh 1): ";
        cin >> pilihan;
       
        switch (pilihan){
            case 1:
                cout << "Masukan antrian: ";
                cin >> antrian;   
                q.enqueueLast(antrian);
                break;
            case 2:
                q.dequeueFirst();
                break;
            case 3:
                cout << "Selipkan antrian sebelum antrian: ";
                cin >> target;
                cout << "Masukkan antrian: ";
                cin >> antrian;
                q.enqueueBefore(target, antrian);
                break;
            case 4:
                cout << "Hapus antrian setelah antrian: ";
                cin >> target;
                q.dequeueAfter(target);
                break;
            case 5:
                q.printList();
                break;
            case 0:
                cout << "keluar" << endl;
        }
    }while (pilihan != 0);
    return 0;
}