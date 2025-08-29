#include <iostream>
using namespace std;
    int jam;
    float upah;
        
    float upahReguler (int jam, float upah){
        float upahReguler = jam * upah; //Rumus upah reguler 
        if (jam >= 30){ //jika lembur lebih dari atau sama dengan 30 jam
            upahReguler= upahReguler +upahReguler * 0.4; //akan mendapat tambahan 40% dari upah reguler
        } else{
            upahReguler= upahReguler + upahReguler* 0.2; //kalaau kurang dari 30 jam, akan mendapat 20% saja
        }
        return upahReguler; //mengembalikan nilai atau menyimpan nilai upahReg
    }
    
    float overpay(int jam, float upah){ // tiap fungsi memiliki parameter jam dan upah untuk menampung data kedua variable tersebut
        return abs(jam - 30) * upah * 0.3; //rumus overpay sesuai soal
    }

    float totalUpah(int jam, float upah){
        float  upahReg = upahReguler(jam, upah); //panggil fungsi upahReguler lalu simpan di variable upahReg
        float overPay = overpay(jam, upah); //ini juga sama
        return upahReg + overPay; //Lalu total upah = upah reguler + overPay sesuai soal
    }

int main (){
    cout << "------------------------------------------------"<< endl;
    cout << "       MENGHITUNG UPAH LEMBUR KARYAWAN         " << endl;
    cout << "------------------------------------------------"<< endl;
    cout << "Masukkan jam kerja karyawan: "; cin >> jam;
    cout << "Masukkan upah Karyawan: "; cin >> upah;
    cout << "Upah reguler: " << upahReguler(jam, upah) << endl;
    cout << "Overpay: " << overpay (jam, upah) << endl; 
    cout << "Total Upah: " << totalUpah(jam, upah);
    
     
    return 0;
}