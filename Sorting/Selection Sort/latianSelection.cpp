#include <iostream>
#include <utility>
using namespace std;
    void printList(int arr[], int n){
        cout << "List array: ";
        for (int i = 0; i < n; i++){
            cout << arr[i] << " ";
         }
         cout << endl;
    }

    void selection(int arr [], int n){
        for (int i = 0; i < n - 1; i++ ){
            int minIndex = i;
            cout << "minIndex(i):" << minIndex << endl << endl;
            for (int j = i+1; j < n; j++){
                if (arr[j] < arr[minIndex]){
                    minIndex = j;
                    cout << "minIndex(j):"<<minIndex << endl;
                }
            }
            if (minIndex != i){
                cout << "Tukar " << arr[i] << " dan " << arr[minIndex] << ": " << endl;
                swap (arr [i], arr[minIndex]);
                printList(arr, n);
            }
        }
    }

int main (){
    int arr[] = {2, 4, 1, 3, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    printList(arr, n);
    cout << endl;
    selection(arr, n);
    cout << endl;

    printList(arr, n);
    return 0;
}