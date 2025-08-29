#include <iostream>
#include <utility>
using namespace std;
//bubble sort digunakan untuk mengurutkan data ascending atau descending dengan cara membandingkan nilai sebelahnya

void printArr(int arr[], int elemen){
    for (int i = 0; i < elemen; i++){
        cout << arr [i]<< " "; 
    
    }
    cout << endl;
}

void bubbleSort(int arr[], int elemen){
    int tukar;
    for (int i = 0; i < elemen - 1; i++){
        for (int j = 0; j < elemen - i - 1; j++){
            if (arr [j] > arr [j+ 1]){
                tukar = arr [j];
                arr [j] = arr [j+1];
                arr [j + 1] = tukar;
            printArr(arr, elemen);              
            }
        }
    }
}
int main(){
    system ("clear");
    int arr [] = {3, 5, 2, 4, 6, 5, 1};
    int elemen = sizeof(arr)/sizeof(arr[0]); //menghitung jumlah elemen

    //array sebelum disorting 
    printArr (arr, elemen);
    bubbleSort(arr, elemen);

    return 0;
}