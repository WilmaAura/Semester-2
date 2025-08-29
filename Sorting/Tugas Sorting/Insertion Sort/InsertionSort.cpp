#include <iostream>
using namespace std;
void insertionSort(int arr[], int n){
    //key memiliki fungsi untuk menyimpan nilai yang mau digeser ke kiri
    int key, i, j;
    for ( i = 1; i < n; i++){ //loop dimulai dari 1 karena akan membandingkan dengan j - 1
        key = arr [i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j]; //Geser array ke kanan
            j = j - 1; //Menggeser ke kiri 
        }
        arr[j+1] = key  ; //Ketika j+ 1 membandingkan dengan [j], [j-1], ...
        // maka akan disimpan di key 
        cout << "step " << i << " " << endl;
        //Jika Tidak menggunakan loop ini maka output sorting tidak muncul
        for (int k= 0; k < n; k++){
            cout << arr[k] << " ";
        }
        
        cout << endl;
    }
}

int main (){
    system ("clear");
    int arr[]= {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "Data sebelum sorting: ";
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    insertionSort(arr, n);
    return 0;
}