#include <iostream>
#include <string>
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
        qnode* tail;
        qnode* front;
        int max;
        int count;
        int sisa;
        string idProses;

        queue():  head(nullptr), tail(nullptr), front (nullptr), max(3), count(0), sisa(0) {}

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

        
        void enqueueFirst(int value, string idProses){
            qnode* newNode = new qnode(value);
            if (isFull()){
                cout << endl;
                cout << "TIDAK BISA INPUT LAGI!" << endl;
                return;
            }
            if (sameNum(value)){
                cout << endl;
                cout << "DATA ANTRIAN TIDAK BISA SAMA, COBA LAGI!" << endl << endl;
                return;
            }
            if (isEmpty()){
                head = newNode;
                tail = newNode;
                front = newNode;
            }else{
                head->prev = newNode;
                newNode->next = head;
                head = newNode;
            }
            count++;
        }
        void dequeueLast(){
            if (isEmpty()){
                cout << "Tidak bisa menghapus, queue kosong" << endl;
                return;
            }
            if (head->next == nullptr){
                cout << "Nomor pasien " << head->data << " dipersilakan masuk ke ruangan dokter." << endl;
                delete head;
                head = tail= nullptr;
            }else{
                int boxTail = tail->data;
                qnode* temp = tail;
                tail = tail->prev;
                tail->next = nullptr;
                delete temp;
            cout << "Nomor pasien " << boxTail << " dipersilakan masuk ke ruangan dokter." << endl;
            }  
            count--;
        }
        void enqueueAfter(int target, int value){
           if (isEmpty()){
                cout << "Tidak bisa input, queue tidak boleh kosong" << endl;
                return;
            }

            if (isFull()){
                cout << endl;
                cout << "TIDAK BISA INPUT LAGI!" << endl;
                return;
            }

            if (sameNum(value)){
                cout << endl;
                cout << "DATA ANTRIAN TIDAK BISA SAMA, COBA LAGI!" << endl << endl;
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
            count++;
        }

        void enqueueBefore(int target, int value){
            qnode* current = head;
            if (isEmpty()){
                cout << "Tidak bisa menghapus, queue kosong" << endl;
                return;
            }

            if (isFull()){
                cout << endl;
                cout << "TIDAK BISA INPUT LAGI!" << endl;
                return;
            }

            if (sameNum(value)){
                cout << endl;
                cout << "DATA ANTRIAN TIDAK BISA SAMA, COBA LAGI!" << endl << endl;
                return;
            }
            while (current != nullptr && current->data != target){
                current = current->next;
            }
            qnode* newNode = new qnode(value);
            newNode->next = current->next;
            newNode->prev = current;
            current->next = newNode;

           if(newNode->next != nullptr){
            newNode->next->prev = newNode;
            }
            count++;
        }
        
        void dequeueAfter(int target){
            if (isEmpty()){
                cout << "TIDAK BISA MENGHAPUS, QUEUE KOSONG" << endl;
                return;
            }
            qnode* current = head;
            while (current != nullptr && current->data != target){
                current = current->next;
            }
            if (current == nullptr ){
                cout << "Data tidak ditemukan" << endl;
                return;
            }
            qnode* temp = current->prev;
            current->prev= temp->prev;
            if (current->prev != nullptr){
                current->prev->next = current;
            }
            delete temp;
            count--;
        }
        void dequeueBefore(int target){
            qnode* current = head;
            if (isEmpty()){
                cout << "TIDAK BISA MENGHAPUS, QUEUE KOSONG" << endl;
                return;
            }
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
        void printListReverse(){
            qnode* current = tail;
            sisa = max - count;
            cout << "Isi queue: ";
            while(current != nullptr){
                cout << current->data << " | " ; 
                if (current ->prev != nullptr){
                    cout << "  ";
                }
                current = current -> prev;
            }
            cout << endl;
            cout << "Max: "<< max << endl; 
            cout << "Jumlah Antrean: "<< count << endl; 
            cout << "Sisa: "<< sisa << endl; 
            cout << endl;
        }

        void detailPrintList(){
            if (isEmpty()) {
                cout << "Queue kosong" << endl;
                return;
            }
            sisa = max - count;
            qnode* current = tail;
            cout << "Isi queue:" << endl;
            while (current != nullptr) {
                cout << "Front: " << front->data << endl;
                cout << "Rear: " << head->data << endl;
                cout<< "Rear prev: " << head->prev << endl;
                cout << "Alamat: " << current << endl;
                cout << "Nilai: " << current->data << endl;
                cout << "Alamat next: " << current->next << endl << endl;
                cout << "Max: " << max << endl;
                cout << "count: " << count << endl;
                cout << "sisa: " << sisa << endl << endl;
                current = current->prev;
            }
            cout << endl << "---------------------------------------" <<endl;
        }
        
        void setMax(int newMax){
            if (max < count){
                cout << "MAX TIDAK BOLEH LEBIH KECIL DARI JUMLAH CURRENT DATA." << endl;
                return;
            }
            max = newMax;
        }
    };
int main (){
     queue q;
    int pilihan, antrian, target;
    string id;
    do{
        cout << "----------------------------------------------------" << endl;
        cout << "|                   ADMIN KLINIK                    | " << endl;
        cout << "----------------------------------------------------" << endl;
        cout << "| 1.Enqueue First        " <<" |" << " 6.PrintListReverse      |" << endl;
        cout << "| 2.Dequeue Last         " <<" |" << " 7.Enqueue Before        |" << endl;
        cout << "| 3.Enqueue After        " << " |" <<" 8.Dequeue Before        |" << endl;
        cout << "| 4.Dequeue After        " << " |" <<" 9.Set newMax            |" << endl;
        cout << "| 5.detail Print List    " << " |" <<" 0.Exit                  |" << endl;
        cout << "----------------------------------------------------" << endl << endl;
        cout << "Pilih (contoh 1): ";
        cin >> pilihan;
        
        
        switch (pilihan){
            case 1:
                cout << "Masukan antrian: ";
                cin >> antrian;   
                cout << "Masukan id Proses: ";
                cin >> id;
                q.enqueueFirst(antrian, id);
                break;
            case 2:
                q.dequeueLast();
                break;
            case 3:
                cout << "Selipkan antrian setelah antrian: ";
                cin >> target;
                cout << "Masukkan antrian: ";
                cin >> antrian;
                q.enqueueAfter(target, antrian);
                break;
            case 4:
                cout << "Hapus antrian setelah antrian: ";
                cin >> target;
                q.dequeueAfter(target);
                break;
            case 5:
                q.detailPrintList();
                break;
            case 6:
                q.printListReverse();
                break;
            case 7:
                cout << "Selipkan antrian sebelum antrian: ";
                cin >> target;
                cout << "Masukkan antrian: ";
                cin >> antrian;
                q.enqueueBefore(target, antrian);
                break;
            case 8:
                cout << "Hapus antrian sebelum antrian: ";
                cin >> target;
                q.dequeueBefore(target);
                break;
            case 9:
                cout << "Masukkan jumlah max yang baru: ";
                cin >> antrian;
                q.setMax(antrian);
                break;
            case 0:
                cout << "keluar" << endl;
        }
    }while (pilihan != 0);
    return 0;
}