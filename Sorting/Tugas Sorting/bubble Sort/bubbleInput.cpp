#include <iostream>
#include <utility>
using namespace std;
    void printArr(int arr[], int n){
        for (int i = 0; i < n;i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    void bubbleSort(int arr [], int n){
        bool sorted;
        for (int i = 0; i < n -1; i++){ //Loop ntuk membandingkan elemen
            cout << "Langkah " << i + 1 << ":" << endl;
            for (int j = 0; j < n - i - 1; j++){
                if (arr[j] > arr[j+1]){ //jika elemen 1 lebih besar dari 2 maka akan di swap
                    swap(arr[j] , arr[j+1]);
                    printArr(arr, n);
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

int main (){
    system ("clear");
    const int max = 100; 
    int arr [max];
    int n;
    
    inputData(arr, n);
    
    cout << "Data sebelum disorting : ";
    printArr(arr, n);
    cout << endl << endl;

    cout << "Proses bubble sort: " << endl;
    bubbleSort(arr, n);

    cout << "Setelah disorting: ";
    printArr(arr, n);
    return 0;
}

