#include <iostream>
using namespace std;
    struct qnode{
        string data;
        qnode* next;
        qnode* prev;
    };
    
    struct list{
        qnode* front;
        qnode* tail; 
        int max = 4;
        int count;
        int sisa;   
    };

    list queue = {nullptr, nullptr};

    bool isEmpty(){
        return queue.front== nullptr;
    }

    bool isFull(){
        return queue.count >= queue.max;
    }

    qnode* createNode (string value){
        qnode* newNode = new qnode;
        newNode->data = value;
        newNode->next = nullptr;
        newNode->prev = nullptr;
        return newNode;
    }

    void enequeueLast ( string value){
        if (isFull()){
            cout << "Tidak bisa insert lagi, sudah penuh!!" << endl;
        }
        else{
            qnode* newNode = createNode (value);
            if (isEmpty()){
                queue.front = newNode;
                queue.tail = newNode;
            }
            else {
                qnode* current = queue.front;
                while(current!=nullptr){
                    current = current->next;
                }
                current->next = newNode;
                queue.tail = newNode;
            }
            queue.count++;
        }

    }

    void dequeueFirst(){
        if(isEmpty()){
            cout << "List kosong tidak bisa dequeue" << endl;
            return;
        }  
        else{
            qnode* current = queue.front;
            queue.front= queue.front->next;
            if (queue.front == nullptr){ //jika setelah dequeue kosong
                queue.tail = nullptr;
            } 
            else {
                queue.front= queue.front->next; 
            }
            cout << "Dequeued: " << current->data;
            delete current;
            queue.count--;
        }
    }

    void enqueueFirst(string value){
        if (isFull()){
            cout << "Tidak bisa insert lagi, sudah penuh!!" << endl;
        }
        else{
            qnode* newNode = createNode(value);
            if (isEmpty()){
                queue.front = newNode;
                queue.tail = newNode;
            }
            else{
                queue.tail = newNode;
            }
            cout << "Enqueue: " << endl;
            queue.count++;
        }
    }

    void dequeueLast(){
        if (isEmpty()){
             cout << "List kosong tidak bisa dequeue" << endl;
            return;
        }
        else{
            qnode* current= queue.front;
            while (current->next->next != nullptr){
                current = current->next;
            }
            qnode* temp = current->next;
            current->next = nullptr;
            delete temp;  
            queue.count--; 
        }
    }

    
    void enqueueAfter (string value, string target){
        if (isEmpty()){
            cout << "Tidak boleh kosong kalau mau enqueue after" << endl;
            return;
        }   
        else {
            qnode* temp = queue.front;
            while (temp!= nullptr && temp->data != target){
                temp= temp->next;
            }
            qnode* newNode = createNode(value);
            newNode->next = temp->next;
            newNode->prev = temp;
            newNode->next = newNode;
            if (newNode->next != nullptr){
                newNode->next->prev = newNode;
            }else{
                newNode->next = nullptr;
            }
        }
        cout << "Enqueue: " << endl;
        queue.count++;
    }
    void dequeueAfter(string target){
        if (isEmpty()){
            cout << "Tidak ada yang dihapus" << endl;
            return;
        }
        else{
            qnode* current= queue.front;
            while (current!= nullptr && current->data != target){
                current = current->next;
            }

            if (current->next== nullptr || current == nullptr){
                cout << "Target tidak ditemukan" << endl;
                return;
            }
            qnode* temp = current->next;
            current->next =  temp->next;
            if (current->next != nullptr){
                current->next->prev = current;
            }else{
                 current->next = nullptr;
            }
            delete temp;
            cout << "Enqueue: " << endl;
            queue.count--;
        }
    }

    void printList (){
        qnode* current = queue.front;
        cout << "Daftar Antrian: " << endl;
        while (current!= nullptr){
            cout << "Nilai: " << current->data << endl;
            current= current->next;
        }
    }
    
int main (){
    int pilihan;
    string nama;
    do {
        cout << "Menu Queue" << endl;
        cout << "------------------------" << endl;
        cout << "1. Enqueue Last, Dequeue first" << endl;
        cout << "2. Enqueue First, Deqeue last" << endl;
        cout << "3. Enqueue After" << endl;
        cout << "4. Dequeue After" << endl;
        cout << "5. Enqueue Before"  << endl;
        cout << "6. Dequeue Before" << endl;
        cout << "7. Print List" << endl;
        cout << "0. Exit" << endl;
        cout << "Input (contoh 1): "; cin >> pilihan;
        switch (pilihan){
            case 1: 
                char pil;
                cout << "Masukkan Nama: "; getline(cin, nama);
                cout << endl;
                enequeueLast(nama);
                cout << "Ketik (Y/y) jika ingin dequeue, ketik (N/n) jika tidak: ";
                cin >> pil;
                if (pil == 'Y' || pil == 'y'){
                    dequeueFirst();
                }
                break;
                /* else {
                    cout << "Masukkan Nama: "; getline(cin, nama);
                    enequeueLast(nama);   
                } */
            case 7:
                printList();
                
        }
    } while (pilihan!= 0);
    return 0; 
}