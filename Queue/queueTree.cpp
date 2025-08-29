#include <iostream>

using namespace std;

struct node{
    char data;
    node* next;
    node* prev;
};
    node* head = nullptr;
    node* tail = nullptr;

    node* createNode(char value){
        node* newNode = new node;
        newNode->data = value;
        newNode->next = nullptr;
        newNode->prev = nullptr;
        return newNode;
    }

int main (){
        node* head = createNode ('A');
        head->prev = createNode ('B');
        head->next = createNode('C');
        head->prev->prev = createNode ('D');
        head->prev->next = createNode ('E');
 return 0;   
}