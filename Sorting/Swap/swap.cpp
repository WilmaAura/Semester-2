#include <iostream> 
#include <utility> //untuk menggunakan fungsi swap

using namespace std;
    void printArr(int arr [], int n){
        for (int i = 0; i < n; i++){
            cout << arr[i] << " ";
        }
            
    }

int main (){
    system("clear");
    int arr[] = {10, 20, 30, 40, 50};
    int n= sizeof(arr)/sizeof(arr[0]);

    cout << "Array sebelum sorting: ";
    printArr(arr, n);

    int index0 = 0, index4 = 4, index1= 1, index3 = 3;
    swap (arr[index0], arr[index4]);
    swap (arr[index1], arr[index3]);

    cout << endl;
    cout << "Tampilkan setelah swap: ";
    printArr(arr, n);
    //ubah menjadi descending dengan swap manual

    return 0; 
}