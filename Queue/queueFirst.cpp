#include <iostream>
using namespace std;

    struct Qnode{
        int data;
        Qnode* next;
    };typedef Qnode qnode;

    struct list{
        qnode* head;
        qnode* front;
        qnode* rear;

    };

    list queue = {nullptr, nullptr, nullptr}; //head, front, rear
    
    bool isEmpty(){
        return queue.head == nullptr;
    }
    bool isfull(){
        return false;
    }
    
    void enqueue(int value){
        qnode* newNode = new qnode;
        if (isEmpty()){
            queue.head = newNode;
            queue.front = newNode;
            queue.rear = newNode;
        }else {
            queue.head = newNode;
            queue.rear=newNode;
        }

    }

    void dequeue(){
        if (isEmpty()){
            cout << "Queue kosong" << endl;
            return;
        }
        if ()
    }

    void displayList(){

    }

int main(){         

    return 0;
}