#include <iostream>
using namespace std;
    
    void printList(int arr[], int n){
        cout << "List array: ";
        for (int i = 0; i < n; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void insertionSort(int arr[], int n){
        int key, i, j;
        for (i = 1; i < n;i++){
            key = arr[i];
            j = i - 1;
            while (j>=0 && arr[j] > key){
                arr[j+1] = arr[j];
                j = j - 1;               
            }
            arr[j+1] = key;
        }
        printList(arr, n);
    }

int main(){
    int arr[] = {3, 4, 2, 5, 1, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
        printList(arr, n);
        insertionSort(arr, n);
        printList(arr, n);
    return 0; 
}