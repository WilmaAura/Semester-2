#include <iostream>
//INSET LAST DELETE FIRST
using namespace std;
struct Qnode {
    string data;
    Qnode* next;
}; typedef Qnode qnode;

struct List {
    Qnode* head;//buat manggil
    Qnode* front;
    Qnode* rear;
    int max = 4;
    int count;
    int sisa = max - count;
};

// Inisialisasi queue
List queue = {nullptr, nullptr, nullptr}; //head, front, rear

// Fungsi untuk mengecek apakah queue kosong
bool IsEmpty() {
    return queue.head == nullptr;
}

bool isFull(){
    return queue.count>=queue.max;
}
// Fungsi untuk mengecek apakah queue penuh (tidak relevan untuk linked list, jadi selalu false

// Fungsi untuk enqueue (menambahkan elemen di awal queue)
void Enqueue(string nama) {        
    if (isFull()){
        cout << "tidak boleh lagi" << endl;
    }
    else {
    Qnode* newNode = new Qnode;
    newNode->data = nama;
    newNode->next = nullptr;

    if (IsEmpty()) {
        queue.head = newNode;
        queue.front = newNode;
        queue.rear = newNode;
    } else {
        Qnode* current = queue.head;
        while(current->next != nullptr){
            current = current->next;
        }
        current->next = newNode;
        queue.rear = newNode;
    }
    cout << "Enqueued: " << nama << endl;
        queue.count++;
    }
   
}

void enqueueAfter(string target, string nama){
    if (IsEmpty()){
        cout << "Tidak bisa karena tidak boleh kosong" << endl;
        return;
    }
    if (isFull()){
        cout << "tidak boleh lagi" << endl;
    }else{
        Qnode* temp = queue.head;
    while (temp != nullptr && temp->data != target){
            temp = temp->next; 
    }

    if (temp==nullptr){
        cout << "Target tidak ditemukan" << endl;
        return;
    }
    Qnode* newNode = new Qnode;
    newNode->data = nama;
    newNode->next = temp->next;
    temp->next = newNode;
    queue.count++;
    }
    
}

// Fungsi untuk dequeue (menghapus elemen dari akhir queue)
void Dequeue() {

    if (IsEmpty()) {
        cout << "Queue kosong, tidak ada yang di-dequeue" << endl;
        return;
    }
    Qnode* temp = queue.head;
    queue.head = queue.head->next;
    if (queue.head == nullptr) { // Jika queue menjadi kosong setelah dequeue
        queue.rear = nullptr;
        queue.front = nullptr;
    }else{
        queue.front = queue.head;
    }
    cout << "Dequeued: " << temp->data << endl;
    delete temp;
    queue.count--;
}

void dequeAfter(string target){
    Qnode* temp = queue.head;
    while(temp!= nullptr && temp->data != target){
        temp = temp->next;
    }
    Qnode* current = temp->next;
    
}

// Fungsi untuk menampilkan isi queue
void displayQueue() {
    queue.sisa = queue.max - queue.count;
    if (IsEmpty()) {
        cout << "Queue kosong" << endl;
        return;
    }
    Qnode* current = queue.head;
    cout << "Isi queue:" << endl;
    while (current != nullptr) {
        cout << "Front: " << queue.front->data << endl;
        cout << "Rear: " << queue.rear->data << endl;
        cout << "Alamat: " << current << endl;
        cout << "Nilai: " << current->data << endl;
        cout << "Alamat next: " << current->next << endl << endl;
        cout << "Max: " << queue.max << endl;
        cout << "count: " << queue.count << endl;
        cout << "sisa: " << queue.sisa << endl;
        current = current->next;
    }
    cout << endl << "---------------------------------------" <<endl;
}

void displayAll(){
    qnode* current = queue.head;
    cout << "List akhir: ";
    while(current != nullptr){
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}
int main() {
    // Memastikan queue kosong
    if (IsEmpty()) {
        cout << "Queue baru saja diinisialisasi dan kosong." << endl;
    } 
    // Enqueue beberapa elemen ke dalam queue
    Enqueue("Rama");
    displayQueue();
    Enqueue("Adi");
    displayQueue();
    Enqueue("Saputra");
    displayQueue();
    Enqueue("Saputri");
    displayQueue();
    Enqueue("ILMI");
    displayQueue();
    Dequeue();

    enqueueAfter("Adi", "Ilmi");
    
    
    displayQueue();

    displayAll();

    

    
    return 0;
}