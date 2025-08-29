#include <iostream> 
using namespace std;

int main(){
    system ("clear");
    int x = 1; //nilai var x
    int* xPtr; //deklarasi pointer ke integer
    xPtr = &x; //xPtr menyimpan alamat x
    cout << "Nilai x = " << x <<endl; //menampilkan x secara langsung
    cout << "Nilai x = " << *xPtr << endl; //Menampilkan nilai x dari pointer, pakai *xPtr (dereference)
    cout << "Alamat x = " << &x << endl;
    cout << "Alamat x = " << xPtr << endl;
    cout << "Nilai yang disimpan pada alamat ";
    cout << xPtr << " adalah " << *xPtr;
    return 0;
}
