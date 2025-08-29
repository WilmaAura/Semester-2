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
            int minIndex = i; //menganggap elemen paling kecil
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
int main(){
    system ("clear");
    int arr[] = {1, 5, 4, 2 ,0};
    int n = sizeof(arr)/sizeof(arr[0]); 

        cout << "Data sebelum disorting: ";
    printArray(arr, n); 

    cout << endl;
    selectionSort(arr, n);

    cout << "Setelah disorting: ";
    printArray(arr, n);
    return 0;
}
