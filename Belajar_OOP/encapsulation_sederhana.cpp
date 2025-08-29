#include <iostream>
#include <tuple>
using namespace std;

class AkunBank{
    private:
    string nomorRekening, namaPemilik;
    double saldo;
    
    public:
    //setter
    void setNilaiPemilik(string rekeningOrang, string namaOrang, int saldoOrang ){ 

        nomorRekening = rekeningOrang;
        namaPemilik = namaOrang;
        saldo = saldoOrang;
    }
    //getter
    //tuple adalah tipe data yang dapat menampung berbagai tipe data
    tuple <string, string, double> getInfoPemilik(){
        return make_tuple(nomorRekening, namaPemilik, saldo);
    }
    
};
int main (){
    system("clear");
    AkunBank bank;
    bank.setNilaiPemilik ("987654", "WIlma", 90000 );
    tuple <string, string, double> data = bank.getInfoPemilik();
    cout << get<0>(data) << endl;
    cout << get<1>(data) << endl;
    cout << get<2>(data) << endl;
    
    return 0;
}