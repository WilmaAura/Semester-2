#include <iostream>
using namespace std;

//Proses penggabungan
//merge = menggabungkan

void merge(int arr[], int left, int mid, int right){
    int n1 = mid - left + 1; //Untuk divide data ke kiri
    int n2 = right - mid; //Untuk divide data ke kanan
    //those code referring to the index

    //Buat array sementara untuk bagian kiri dan kanan
    int L[n1], R[n2];

    //Salin data ke array sementara
    for (int i = 0; i < n1; i++){
        L[i] = arr[left + i]; //hasil L[i] = {5, 10, 15}
    }
    for (int j = 0; j < n2; j++){
        R[j] = arr[mid + 1 + j]; //hasil R[j] = {20, 25}
    }
    //
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2){
        if (L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        }
        else {
           arr[k] = R[j];
            j++;
        }
        k++; //Untuk pindah ke elemen selanjutnya
    }
    //Salin sisa elemen dari bagian kiri (jika ada)
    while (i <n1){
        arr[k]= L[i];
        i++;
        k++;
    }
    // Salin sisa elemen dari bagian kanan (jika ada)
    while (j < n2){
        arr[k] = R[j];
        j++;
        k++;
    }

    //show array after merge
    cout << "Merged: ";
    for (int x = left; x <= right; x++){
        cout << arr[x] << " ";
    }
    cout << endl;
} 

    // Fungsi rekursif untuk melakukan Merge sort
    void mergeSort(int arr[], int left, int right){
        if (left < right){
            int mid = left + (right - left) /2; //Hitung titik tengah
            
            //Tampilkan bagian yang diproses
            cout << "Divide: ";
            for (int i = left; i <= right; i++){
                cout << arr[i] << " ";
            }
            cout << endl;
            cout << " ==> left: ";
            for (int i = left; i <= mid; i++){
                cout << arr[i] << " "; 
            }
            cout << " | right ==> ";
            for (int i = mid + 1; i <= right; i++){
                cout << arr[i] << " ";
            }
            cout << endl;

            //urutkan bagian kiri
            mergeSort(arr, left, mid);
            mergeSort(arr, mid + 1, right);

            //Gabungkan bagian yang sudah terurut
            merge(arr, left, mid, right);
        }
    }

    void printArr(int arr[],int n){
        for (int i = 0; i < n; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
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
    
    cout << "Print array sebelum disorting: ";
    printArr(arr, n);

    cout << "Proses Merge Sort: " << endl;
    mergeSort(arr, 0, n-1); //Panggil fungsi merge sort

    cout << "Setelah terurut: ";

    printArr(arr, n); 

    return 0;
}