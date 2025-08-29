#include <iostream>

using namespace std;

int hitungLuasPersegi(int sisi) {
    return sisi * sisi;
}

int main() {
    int sisi;
    cout << "Masukkan panjang sisi persegi: ";
    cin >> sisi;

    int luas = hitungLuasPersegi(sisi);
    cout << "Luas persegi: " << luas << endl;
    return 0;
}
