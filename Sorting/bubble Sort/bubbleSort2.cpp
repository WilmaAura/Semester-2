#include <iostream> 
using namespace std;
    void printArr(int arr[], int n){
        for (int i = 0; i < n; i++){
            cout << arr[i] << " " ;
        }
    }
    
    void bubbleSort(int arr [], int n){
        bool swapped;
        for (int i = 0; i < n - 1; i++){
        swapped = false;
        for (int j = 0; j < n - i - 1; j++){
            if (arr [j] > arr [j + 1]){
                swap (arr [j], arr [j+1]);
                swapped = true;
            }
            if (!swapped){
                break;
            }
        }
        
        cout << endl;
        }
    }

int main (){   
    int arr [] = {5,3,2,4,1};
    int n = sizeof(arr)/sizeof(arr [0]);
    printArr(arr, n);
    bubbleSort(arr, n);
    return 0;
}