#include <iostream>
using namespace std;
 
int binarySearch(int arr [], int left, int right, int target){
    while (left <= right){
        int mid = left + (right - left)/2;
        if (arr[mid] == target){
            cout << "Elemen ketemu di index =" << mid << endl;
            cout << "Element yang dicar:i " << target << endl;
            return mid;
        }
        else if (arr[mid] < target){
            cout << "Cari di kanannya: " << arr[mid] <<  endl;
            left = mid + 1;
        }
        else{
            cout << "Cari di kiri" << arr[mid] << endl;
            right = mid - 1;
        } 
    }
    return -1;
}

int main (){
    system ("clear");
    int arr [] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Jumlah elemen: " << n << endl;
    int target = 4;
    int result = binarySearch(arr, 0, n-1, target);

    if (result == -1){
        cout << "Elemen tidak ditemukan" << endl;
    }
    return 0;
}