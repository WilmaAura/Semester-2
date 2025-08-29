#include <iostream>
using namespace std;

    int binarySearch (int arr[], int left, int right, int x){
        while (left <= right){ // 0 <= 9
            int mid = left + (right - left)/2; // 0 + (9 - 0) / 2 = 4
            if (arr[mid] == x){
                cout << "Element " << x << " ketemu di index: " << mid << endl;
                return mid;
            }
            else if(arr[mid] < x){ 
                cout << "cek bagian kanan array " << endl;
                left = mid + 1; //left = 4 + 1
            }
            else {
                cout << "cek bagian kiri array" << endl;
                right = mid - 1;
            }
        }
        return -1; //jika tidak ada datanya maka akan exit
    }
int main (){
    system ("clear");
    int arr [] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr)/sizeof (arr[0]);
    cout << n << endl;
    int x = 7;

    int result = binarySearch(arr, 0, n-1, x);
    if (result == -1){
        cout << "Element tidak ada" << endl;
    }
    return 0;
}