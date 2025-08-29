#include <iostream>
using namespace std;
    void print(int arr[], int n){
        cout << "List array: ";
        for (int i = 0; i < n; i++){
            cout <<arr[i] << " ";
        }
        cout << endl;
    }

    void bubble(int arr[], int n){
        for (int i = 0; i < n - 1; i++){
            bool swapped;
             for (int j = 0; j < n - i - 1; j++){
                if (arr[j] > arr [j+1]){
                    swap(arr[j], arr[j+1]);
                    print(arr, n);
                    swapped = true;
                }
            }
        }
    }

int main (){
    int arr[] = {5, 2, 1, 3 ,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << n << endl;
    print(arr, n);
    cout << endl;
    bubble(arr, n);
    print (arr, n);
    return 0;
}