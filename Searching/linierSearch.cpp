#include <iostream>
using namespace std;

    int liniearSearch(int arr[], int n, int x){
        bool found = false;
        for (int i = 0; i < n; i++){
            if (arr[i] == x){
                cout << "Elemen ketemu di index = " << i << endl;
                cout << "Elemen = " << arr[i] <<endl;
                found = true;
            }
            cout << "Cek elemen di index = " << i << endl;
        }
        if (!found){
            return -1;
        }
        return 0;
    }
int main (){
    system ("clear");
    int arr[] = {3, 5, 4, 2, 6, 6, 7, 0};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Jumlah elemen: " << n << endl;
    int x = 6;  
    int result = liniearSearch(arr, n, x);

    //Kalau tidak ada maka akan diasumsikan elemen juga tidak ada
    if (result == -1){
        cout << "Elemn tidak ditemukan" << endl;
    }
    return 0;
}