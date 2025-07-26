#include <iostream>
using namespace std;
    struct Stack{
        int data;
        Stack* next;
    };typedef struct Stack stack;

    stack* TOP = nullptr;
    bool isEmpty(){
        return TOP == nullptr;
    }
    void push(int value){
        stack* newNode= new stack;
        newNode->data = value;
        newNode->next = nullptr;
        if (isEmpty()){
            TOP = newNode;
        }else{
            stack* current = TOP;
            while (current->next != nullptr){
                current = current->next;
            }
            current->next = newNode;
        }
    }
    // 1, 2 ,3 ,4 
    void pop(){
        if (isEmpty()){
            cout << "Tidak bisa hapus, stack kosong" << endl;
            return;
        }
        if (TOP->next == nullptr){
            cout << "Popped: " << TOP << endl;
            delete TOP;
            TOP =nullptr;
        }
        else{
            stack* current = TOP;
            while (current->next->next!= nullptr){
                current= current->next;
            } 
            delete current->next;
            current->next = nullptr;
        }
    }

    void displayStack(){
        stack* current = TOP;
        cout << "Data stack: ";
        while(current != nullptr){
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
        cout << "TOP: " << TOP->data << endl;
        cout << "--------------------------" << endl;
    }
int main (){
    push(9);
    push(1);
    displayStack();

    pop();
    displayStack();

    push(9);
    push(2);
    displayStack();
    return 0;
}