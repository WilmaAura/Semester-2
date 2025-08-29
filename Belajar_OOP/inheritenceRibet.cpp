#include <iostream>
#include <tuple>

using namespace std;

class akunBank{
    protected:
    string nomorRekening, namaPemilik;
    double saldo;
    public:

    void setAkunBank(string rekeningOrang, string namaOrang, double saldoOrang){
        nomorRekening = rekeningOrang;
        namaPemilik = namaOrang;
        saldo = saldoOrang;

    }
    tuple <string, string, double> getAkunBank(){
        return make_tuple (nomorRekening, namaPemilik, saldo);
    }
};

class akunTabungan: public akunBank{

};

int main (){
    system("clear");
    tuple <string, string, double>
    
    return 0;
}