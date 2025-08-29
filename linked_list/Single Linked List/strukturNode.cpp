#include <iostream>
using namespace std;

    //inisiasi SLL- Non Circular
    struct node {
        int data;
        struct node *next;
    };
    struct node *head, *last;
    typedef struct node Node;
int main (){
    Node *baru;
    baru = new Node;
    baru -> data = NULL;
    baru-> next = NULL;
    return 0;
}