#include <iostream>
using namespace std;

struct Stack
{
    int data;
    Stack *next;
};
typedef struct Stack stack;

stack *TOP = nullptr;

bool isEmpty()
{
    return TOP == nullptr;
}

void push(int value)
{
    stack *newNode = new stack;
    newNode->data = value;
    newNode->next = TOP;
    TOP = newNode;
    cout << "Pushed: " << value << endl; 
    cout << "TOP: " << TOP->data << endl;
}

void pop()
{
    if (isEmpty())
    {
        cout << "Tidak ada element" << endl;
        return;
    }

    stack *current = TOP;
    TOP = TOP->next;
    cout << "POP: " << current->data << endl;
    if (TOP != nullptr)
    {
        cout << "TOP: " << TOP->data << endl;
    }
    else
    {
        cout << "Stack kosong" << endl;
    }
    delete current;
}

void displayList()
{
    if (isEmpty())
    {
        cout << "Stack kosong" << endl;
        return;
    }
    Stack *current = TOP;
    cout << "Isi stack:" << endl;
    while (current != nullptr)
    {
        cout << current->data << ",";
        // cout << "Alamat: " << current << endl;
        // cout << "Nilai: " << current->data << endl;
        // cout << "Alamat next: " << current->next << endl << endl;
        current = current->next;
    }
    cout << endl
         << "---------------------------------------" << endl;
}
int main()
{
    if (isEmpty())
    {
        cout << "Stack baru saja kosong" << endl;
    }
    push(1);
    push(2);
    push(3);
    displayList();

    pop();
    displayList();
    return 0;
}