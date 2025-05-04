#include <iostream>
using namespace std;


    int linierSearch(int arr[], int n, int target){
        bool ketemu = false;
        for (int i = 0; i < n; i++){
            cout << "Cek elemen yang dicari di index = " << i << endl;
            if (arr[i] == target){
                cout << "Elemen ketemu di index = " << i << endl;
                cout << "Elemen yang dicari = " << arr[i]<< endl;
                ketemu = true;
            }
        }
        if (!ketemu){
            return -1;
        }
        return 0;
    }

int main () { 
    system("clear");  
    int arr[] = {1, 3, 2, 4, 5, 8, 6};
    int n = sizeof(arr)/sizeof(arr[0]);
    int target = 1;
    int result = linierSearch (arr, n, target);

    if (result == -1){
        cout << "Elemen tidak ditemukan";
    }
    return 0;
}