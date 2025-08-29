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

    void enqueueFirst(int value){
        if (isFull()){
            cout << "Tidak bisa insert lagi, sudah penuh!!" << endl;
        }
        else{
            qnode* newNode = createNode(value);
            if (isEmpty()){
                queue.head= newNode;
                queue.front = newNode;
                queue.tail = newNode;
            }
            else{
                newNode->next = queue.head;
                queue.head->prev = newNode;
                queue.head = newNode;
            }
            queue.count++;
        }
    }
    void dequeueLast(){
        if (isEmpty()){
             cout << "List kosong tidak bisa dequeue" << endl;
            return;
        }
        else{
           if(queue.head->next==nullptr){
            delete queue.head;
            queue.head = nullptr;
            queue.tail = nullptr;
            queue.front = nullptr;
            queue.count--;
            return;
        }
        }
            qnode* current= queue.head;
            while (current->next->next != nullptr){
                current = current->next;
            }
            qnode* temp = current->next;
            current->next = nullptr;
            delete temp;  
            queue.count--; 
        }
    


    void enqueueAfter (int target,int value){
        if (isEmpty()){
            cout << "Tidak boleh kosong kalau mau enqueue after" << endl;
            return;
        }   
        else {
            qnode* temp = queue.head;
            while (temp!= nullptr && temp->data != target){
                temp= temp->next;
            }
            if (queue.head==nullptr){
                cout << "Data kosong" << endl;
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
        }
        queue.count++;
    }
    void displayQueue() {
        queue.sisa = queue.max - queue.count;
        if (isEmpty()) {
            cout << "Queue kosong" << endl;
            return;
        }
        qnode* current = queue.head     ;
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
            current = current->prev;
        }
        cout << endl << "---------------------------------------" <<endl;
    }

    void displayAll(){
    qnode* current = queue.head;
    cout << "List akhir: ";
    while(current != nullptr){
        cout << current->data << " ";
        current = current->prev;
    }
    cout << endl;
    }

int main (){
    enqueueFirst(1);
    displayQueue();
    cout << endl;
    enqueueFirst(4);
    displayQueue();
    cout << endl;

    enqueueFirst(5);
    displayQueue();
    cout << endl;

    enqueueFirst(6);
    displayQueue();
    cout << endl;
    displayAll();

    enqueueFirst(9);
    dequeueLast();
    displayQueue();
    enqueueAfter(4, 9);
    displayQueue();
    displayAll();
    return 0;
}