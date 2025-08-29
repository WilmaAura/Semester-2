#include <iostream>

using namespace std;
//insert after dan before
//uas double linked list queue
// Struktur Node untuk queue
struct Qnode {
    int data;
    Qnode* next;
}; typedef Qnode qnode;

// Struktur List untuk menyimpan head dan front dari queue
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
void Enqueue(int data) {        
    cout << "Enqueued: " << data << endl;
    if (isFull()){
        cout << "tidak boleh lagi" << endl;
    }
    else {
    Qnode* newNode = new Qnode;
    newNode->data = data;
    newNode->next = queue.head;
    
    if (IsEmpty()) {
        queue.head = newNode;
        queue.front = newNode;
        queue.rear = newNode;
    } else {
        queue.head = newNode;
        queue.rear = newNode;
    }
        queue.count++;
    }
   
}

void enqueueAfter(int target, int data){
    if (IsEmpty()){
        cout << "Tidak bisa karena tidak boleh kosong" << endl;
        return;
    }
    Qnode* temp = queue.head;
    while (temp != nullptr && temp->data != target){
            temp = temp->next; 
    }

    if (temp==nullptr){
        cout << "Target tidak ditemukan" << endl;
        return;
    }
    Qnode* newNode = new Qnode;
    newNode->data = data;
    newNode->next = temp->next;
    temp->next = newNode;
    queue.count++;
}

// Fungsi untuk dequeue (menghapus elemen dari akhir queue)
void Dequeue() {

    if (IsEmpty()) {
        cout << "Queue kosong, tidak ada yang di-dequeue" << endl;
        return;
    }


    if (queue.head->next == nullptr) { // Jika hanya ada satu elemen di queue
        cout << "Dequeued 1: " << queue.rear->data << endl;
        Qnode* temp = queue.head;
        queue.head = nullptr;
        queue.rear = nullptr;
        queue.front = nullptr;
    }
    else {
        Qnode* current = queue.head;
        while (current->next != nullptr) {
            queue.front = current;
            current = current->next;
        }
        Qnode* temp = current;
        cout << "Dequeued 2: " << current->data << endl;
        queue.front->next = nullptr;
        delete temp;
        queue.count--;
    }

}

void dequeAfter(int target){
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
    Enqueue(10);
    displayQueue();
    Enqueue(20);
    displayQueue();
    Enqueue(30);
    displayQueue();
    enqueueAfter(10, 330);
    displayQueue();
    
    displayAll();
    return 0;
}