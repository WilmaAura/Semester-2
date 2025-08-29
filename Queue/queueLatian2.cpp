#include <iostream>
using namespace std;
    struct qnode{
        int data;
        qnode* next;
        qnode* prev;
    };
    
    struct list{
        qnode* head;
        qnode* front;
        qnode* tail; 
        int max = 4;
        int count;
        int sisa;   
    };

    list queue = {nullptr, nullptr, nullptr};

    bool isEmpty(){
        return queue.front== nullptr;
    }

    bool isFull(){
        return queue.count >= queue.max;
    }

    qnode* createNode (int value){
        qnode* newNode = new qnode;
        newNode->data = value;
        newNode->next = nullptr;
        newNode->prev = nullptr;
        return newNode;
    }

     void enqueueLast (int value){
        if (isFull()){
            cout << "Tidak bisa insert lagi, sudah penuh!!" << endl;
        }
        else{
            qnode* newNode = createNode (value);
            if (isEmpty()){
                queue.head = newNode;
                queue.front = newNode;
                queue.tail = newNode;
            }
            else {
                queue.tail->next = newNode;
                newNode->prev = queue.tail;
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
            if (queue.front == nullptr){ 
                queue.tail = nullptr;
                queue.head= nullptr;
            } 
            else {
                queue.front->prev =nullptr;
                queue.head= queue.front; 
            }
            cout << "Dequeued: " << current->data;
            delete current;
            queue.count--;
        }
    }

    
    void enqueueAfter (int target, int value){
        if (isFull()){
            cout << "Tidak bisa insert lagi, sudah penuh!!" << endl;
            return;
        }
        if (isEmpty()){
            cout << "Tidak boleh kosong kalau mau enqueue after" << endl;
            return;
        }   
            qnode* temp = queue.head;
            while (temp!= nullptr && temp->data != target){
                temp= temp->next;
            }
            if (temp == nullptr) {
                cout << "Data " << target << " tidak ditemukan" << endl;
                return;
            }
            qnode* newNode = createNode(value);
            newNode->next = temp->next;
            newNode->prev = temp;
            temp->next = newNode;
            if (newNode->next != nullptr) {
                newNode->next->prev = newNode;
            } else {
                queue.tail = newNode;
            }
            queue.count++;
    }
        
        

void displayQueue() {
    queue.sisa = queue.max - queue.count;
    if (isEmpty()) {
        cout << "Queue kosong" << endl;
        return;
    }
    qnode* current = queue.head;
    cout << "Isi queue:" << endl;
    while (current != nullptr) {
        cout << "Front: " << queue.front->data << endl;
        cout << "Rear: " << queue.tail->data << endl;
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
int main (){
    enqueueLast(1);
    displayQueue();
    enqueueLast(4);
    displayQueue();
    enqueueLast(5);
    displayQueue();
    enqueueLast(6);
    displayQueue();
    displayAll();

    enqueueLast(9); 
    dequeueFirst();
    displayQueue();
    enqueueAfter(4, 9);
    displayAll();
    return 0;
}