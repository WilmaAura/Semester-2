#include <iostream>
using namespace std;

    int luasPersegi(int n){
        return n*n; //mengembalikan nilai atau menyimpan nilai n dikali n
    }
    
    bool ganjil(int n){ //fungsi menentukan biilangan ganjil
        if (n % 2 != 0){  // jika n dibagi 2 tidak sama dengan 0 maka return true
            return true;
        }
        else{
            return false;
        }
    }
    bool genap (int n){
        if (n%2 == 0){ //jika n dibagi 2 sama dengan 0 maka return true
            return true;
        }
        else{
            return false;
        }
    }

    int sum_n (int n){ //fungsi membuat deret bilangan
        cout << "Deret bilangan: ";
        for (int i= 1; i <= n; i++){
            cout << i << " ";
        }
        return 0; 
    } 
    
    int avg_n (int n){
        int temp = sum_n(n);
        return temp;
    }

int main (){
    int pilihan;
    int bilangan;
    do { //looping
        cout << "Mengolah bilangan menggunakan fungsi" << endl;
        cout << "1. Luas persegi" << endl;
        cout << "2. Nilai Genap dan ganjil" << endl;
        cout << "3. Deret bilangan bulat" << endl;
        cout << "4. Keluar" << endl;
        cout << "Pilih = ";
        cin >> pilihan;
        cout << endl;
        if (pilihan == 1){ //pilihan sama dengan 1 memilih luas persegi
            cout << "Masukkan sisi persegi = "; cin >> bilangan; 
            cout << "Luas persegi= " <<luasPersegi(bilangan) << endl; //dipanggil fungsi luasPersegi diisi inputan bilangan
        }
        else if(pilihan == 2){ //menentukan bilangan genap atau ganjil
            cout << "Masukkan bilangan: "; cin >> bilangan;
            if (genap(bilangan)){ //fungsi genap dipanggil 
                cout << "Bilangan genap" << endl;
            }
            else{
                cout << "Bilangan ganjil" << endl;
            }
        }
        else if (pilihan == 3){ 
            cout << "Masukkan batas deret bilangan: "; cin >> bilangan;
            sum_n(bilangan); //sama
            cout << endl;
        }
        else if(pilihan == 4) { //kalau mau menghentikan program pilih 4
            return-1; //program berhenti
        }
    } while (pilihan != 4); //berhenti jika pilihan tidak sama dengan 4
    return 0;
}