#include <iostream>
using namespace std;

class AkunBank{
    private:
    string nomorRekening, namaPemilik;
    double saldo;
    
    public:
    void setNilaiPemilik(string rekeningOrang, string namaOrang, int saldoOrang ){ 
        //Setter berfungsi untuk memberi nilai attribute yang diprivate karena attribute tersebut tidak bisa diber nilai langsugn
        nomorRekening = rekeningOrang;
        namaPemilik = namaOrang;
        saldo = saldoOrang;
    }

    //getter berfungsi untuk membaca datanya dari luar class
    string getNommorRekening (){
        return nomorRekening; // return akan mengembalikan nilai ke mainnya sehingga private bisa diakses di main
    }

    string getNamaPemilik(){
        return namaPemilik;
    }

    double getSaldo(){
        return saldo;
    }


};

int main (){
    system("clear");
    AkunBank bank;
    bank.setNilaiPemilik ("987654", "WIlma", 90000 );
    cout << "Nama Pemilik: " << bank.getNamaPemilik() << endl;
    cout << "Nomor Rekening: " << bank.getNommorRekening() << endl;
    cout << "Saldo: " << bank.getSaldo () << endl;
    return 0;
}