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

        void enqueueLast(int value){
            qnode* newNode = new qnode(value);
            if (isFull()){
                cout << "Tidak boleh input lagi" << endl;
                return;
            }
            if (isEmpty()){
                head = newNode;
                front = newNode;
                tail = newNode;
            }
            else{
                tail->next = newNode;
                newNode->prev = tail;
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

        void enqueueFirst(int value){
            qnode* newNode = new qnode(value);
            if (isFull()){
                cout << "Tidak boleh input lagi" << endl;
                return;
            }
            if (isEmpty()){
                front = newNode;
                head = newNode;
                tail = newNode;
            }else{
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
            }
            count++;
        }

        void dequeueLast(){
            if (isEmpty()){
                cout << "Tidak bisa menghapus, queue kosong" << endl;
                return;
            }
           qnode* current = head;
            while (current != nullptr){
                current = current->next;
            }
            qnode* temp = current -> next;
            current->next = nullptr;
            delete temp;
            count--;
        }
        void enqueueAfter(int target, int value){
            qnode* current = head;
            if (isEmpty()){
                cout << "Tidak bisa menghapus, queue kosong" << endl;
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
        void enqueueBefore(int target, int value){
           if (isEmpty()){
                cout << "Tidak bisa menghapus, queue kosong" << endl;
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

        void dequeueBefore(int target){
            if (isEmpty()){
                cout << "Tidak bisa menghapus, queue kosong" << endl;
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

        void printListReverse(){
            qnode* current = tail;
            cout << "Isi queue: ";
            while(current != nullptr){
                cout << current->data << " | " << current->prev;
                if (current ->prev != nullptr){
                    cout << " <-> ";
                }
                current = current -> prev;
            }
            cout << endl;
            cout << "Max: "<< max << endl; 
            cout << "Jumlah Antrean: "<< count << endl; 
            cout << "Sisa: "<< sisa << endl; 
            cout << endl;
        }

    };

int main(){
    queue q;
    q.enqueueLast(1);
    q.enqueueLast(2);
    q.printList();
    q.dequeueFirst();
    q.printList();
    q.dequeueFirst();
    q.printList();

    q.enqueueLast(4);
    q.enqueueLast(5);
    q.enqueueBefore(4, 3);
    q.printList();

    cout << endl << endl;
    q.enqueueFirst(10);
    q.enqueueFirst(15);
    q.printListReverse();
    return 0;
}