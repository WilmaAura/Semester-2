#include <iostream>
using namespace std;
    int binarySearch (int arr[], int left, int right, int target){
        while (left <= right){
            int mid = left + (right - left)/2 ;
            if (arr[mid]==target){
                cout << "Data ketemu di index: " << mid << endl;
                return mid;
            } 
            else if(arr[mid] < target){
                cout << "Cari di kanannya " << arr[mid] << endl;
                left = mid + 1;
            }
            else if (arr[mid]> target){
                cout << "Cari di kirinya "<< arr[mid] << endl;
                right = mid - 1;
            }
        }        
            return -1;

    }
int main (){
    int arr[] = {1,2,3,4,5};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout << arr; //4 bytes
    //arr = int arr[5] = 5 * 4
    //sizeof(arr[0]) = 4 bytes
    //20 / 4 = 5 
    int target = 10;
    int result = binarySearch(arr, 0, size-1, target);
    if (result == -1){
        cout << "Data tidak ditemukan"  << endl;
    }
    return 0;
}