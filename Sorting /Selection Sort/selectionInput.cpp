#include <iostream>
#include <utility>
using namespace std;
    void printArray (int arr[], int n){
        for (int i = 0; i < n; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }


    void selectionSort(int arr[], int n){
        for (int i = 0; i < n-1; i++ ){ //loop untuk setiap elemen
            int minIndex = i; 
            for (int j = i+1; j < n; j++){ 
                if (arr[j] < arr[minIndex]){ //mengecek apakah ada elemen yang lebih kecil dari elemen yang dianggap paling kecil
                    minIndex = j; //update indeks elemen terkecil
                }
            }
            if (minIndex != i){ //ada elemen yang lebih kecil di posisi lain
                cout << "   Tukar " << arr[i] << " dan " << arr[minIndex] << ": ";
                swap (arr[i], arr[minIndex]);
                printArray(arr, n);
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

int main(){
    system ("clear");
    
    const int max = 100; 
    int arr [max];
    int n;
    
    inputData(arr, n);
    
    cout << "Data sebelum disorting: ";
    printArray(arr, n); 

    cout << endl;
    selectionSort(arr, n);

    cout << "Setelah disorting: ";
    printArray(arr, n);
    return 0;
}
