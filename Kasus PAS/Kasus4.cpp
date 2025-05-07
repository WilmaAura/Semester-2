#include <iostream>
using namespace std;

int main (){
    int i = 15; //misal alamatnya (0x123)
                //0x123 = 15
    int *p, *q; 
    
    cout << "Nilai awal: "<< i << endl;
    cout << "Alamat i = " << &i << endl;
    
    p = &i; // p = 0x123
    *p = 20; //Ubah nilai di alamat 0x123

    cout << "Nilai *p mengganti nilai i: " << *p << endl;

    i = 50; //Nilai i diubah menjadi 50
    if (i == 50){
        cout << "Setelah i diganti: " << i << " " << p << endl;
    }
    
    //konsepnya sama dengan p
    q = &i; 
    *q = 100;
    
    cout << "Nilai i: " << i << endl;
    cout << "Nilai q: " << q << " "<< endl; //q menyimpan alamat i
    cout << "Nilai p: " << p << endl;  //p menyimpan alamat i
    cout << "*p (Nilai i) = " << *p << " " << "*q (Nilai i) = " << *q;
    return 0;
}