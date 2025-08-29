#include <iostream>
using namespace std;

    //Pass by reference: jika ingin mengubah nilai variable aslinya misal (swap, update, dll)
    void swap (int &x){
        x = 10;

    }

    void swapNoReference(int x){
        x = 15;
    }

int main(){
    system ("clear");
    int a = 5;
    swap (a);
    cout << "Swap by reference: "<< a << endl;
    swapNoReference(a);
    cout << "Swap no reference: "<< a << endl;

    return 0;
}