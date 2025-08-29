#include <iostream>
#include <utility>  // Untuk menggunakan fungsi swap bawaan
#include <vector>
using namespace std;

// Fungsi prosedur untuk menampilkan array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";  // Cetak setiap elemen array
    }
    cout << endl;
}

// Fungsi prosedur untuk melakukan Bubble Sort dan menampilkan step perpindahan
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {          // Loop untuk setiap elemen
        cout << "Langkah " << i+1 << ":" << endl;
        for (int j = 0; j < n-i-1; j++) {    // Loop untuk membandingkan elemen
            if (arr[j] < arr[j+1]) {         // Jika elemen saat ini lebih besar dari elemen berikutnya
                cout << "   Tukar " << arr[j] << " dan " << arr[j+1] << ": ";
                swap(arr[j], arr[j+1]);      // Tukar elemen menggunakan swap bawaan
                printArray(arr, n);         // Tampilkan array setelah penukaran
            }
            else {
                cout << "  Tidak ditukar " << arr[j] << " dan " << arr[j+1] << ": ";
                printArray(arr, n);
            }
        }
    }
}

void inputData (int arr[], int &n){
    cout << "Masukkan jumlah elemen array: " ;
    cin >> n;

    cout << "Masukkan  " << n << " angka sekaligus (pisah pakai spasi): ";
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
}

int main() {
    int arr[] = {7,3,9,4,2};  // Array yang akan diurutkan
    int n = sizeof(arr)/sizeof(arr[0]);         // Hitung ukuran array

    cout << "Array sebelum diurutkan: ";
    printArray(arr, n);  // Tampilkan array sebelum diurutkan

    cout << "\nProses Bubble Sort ASC:\n";
    bubbleSort(arr, n);  // Panggil fungsi Bubble Sort

    cout << "\nArray setelah diurutkan: ";
    printArray(arr, n);  // Tampilkan array setelah diurutkan

    return 0;
}