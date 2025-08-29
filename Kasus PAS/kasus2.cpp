#include <iostream>
using namespace std;

    struct nilai{  
        int x;
        int y;
    }; typedef nilai n; //mengganti nama struct nilai menjadi n
    

int main (){
    n n1; //bikin deklarasi dari struct n yaitu n1
    nilai n2; //nilai masih bisa digunakan walaupun sudah diganti namanya menjadi n
    n1.x = 5;
    n1.y = 10;
    cout << "Nilai dari struct dengan typedef= " << n1.x << " " << n1.y << endl;
    n2.x = 12;
    n2.y = 15;
    cout << "Nilai dari struct tidak menggunakan typedef= " << n2.x << " " <<n2.y << endl;
    
    //typedef digunakan untuk mempersingkat code
    return 0;
}