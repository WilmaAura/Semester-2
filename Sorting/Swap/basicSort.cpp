#include <iostream>
#include <utility>
using namespace std;

int main (){

    int arr[] = {1, 2, 0};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "Sebelum di sorting: ";
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }

    //pensortingan
    for (int j = 0; j < n - 1; j++){
        if (arr[j] > arr[j+1]){
            swap (arr[j], arr[j+1]);
            cout << arr[j] << " " << arr[j+1];
            cout << endl;
        }
        else {
            cout << "tetap"  << endl;
        }
        cout << endl;
        for (int k = 0; k < n; k++){
            cout << arr[k] << " ";
        }
    }

    cout << endl;
    cout << "Setelah sortingan: "; 
    for (int a = 0; a < n; a++){
        cout << arr[a];
    }

    return 0;
}