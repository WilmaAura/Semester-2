#include <iostream>
using namespace std;

struct ListNode {
    char val;
    ListNode* prev;
    ListNode* next;
    ListNode* ph;
    ListNode(char x) : val(x), prev(nullptr), next(nullptr) {}
};

ListNode* ph = nullptr;

void preOrder(ListNode*&ph){
    if (ph!= nullptr){
        cout << " " << ph->val;
        preOrder(ph->prev);
        preOrder(ph->next);
    }
}

void inOrder (ListNode*&ph){
    if (ph != nullptr){
        inOrder(ph->prev);
        cout << " " << ph->val;
        inOrder (ph->next);
    }
}

void postOrder(ListNode* &ph){
    if (ph != nullptr){
        postOrder(ph->prev);
        postOrder(ph->next);
        cout << " " << ph->val;
    }
}
int main() {
    ListNode* head = new ListNode('H'); //root
    head->prev = new ListNode('A'); //child left
    head->next = new ListNode('K'); //child left
    head->prev->next = new ListNode('C'); //LEAF left
    head->prev->prev = new ListNode('B');
    
    head->prev->next->prev = new ListNode('F');
    head->prev->next->next = new ListNode('G');
    
    cout<< "root : "<< head->val << endl;
    cout<< "child 1 (left) : "<< head->prev->val << endl;
    cout<< "child 2 (right) : "<< head->next->val << endl;
    cout<< "leaf kanan 1 : "<< head->prev->next->val << endl;
    cout << "leaf kiri 1: " <<  head->prev->prev->val << endl;
    cout << "children C left: " <<  head->prev->next->prev->val << endl;
    cout << "children C right: " <<  head->prev->next->next->val << endl;
    
    preOrder(head);
    cout << endl;

    inOrder(head);
    cout << endl;
    
    postOrder(head);
    cout << endl;
    return 0;
}