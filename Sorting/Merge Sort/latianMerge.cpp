#include <iostream>
using namespace std;
//Arr[]= {5, 4, 2, 1, 3}
void merge(int arr[], int left, int mid, int right){
    int n1 = mid - left + 1; // 1 - 0 + 1 = 2
    //n1 = 2
    int n2 = right - mid; //4 - 1 = 3
    //n2 = 3
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++){ //i < 2
        //{5, 4}
        L[i] = arr[left + i];
        /*i = 0 | L[0] = arr[0+0] 
        i = 1 | L[1] = arr[0 + 1]
        */
    }
    for (int j = 0; j < n2; j++){
        //{2, 1, 3}
        R[j] =arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;
    while(i < n1 && j < n2){
        if (L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        }
        else{
            arr[k]= R[j];
            j++;
        }
        k++;
    }

    while (i < n1){
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2){
        arr[k] = R[j];
        j++;
        k++;
    }
    cout << "Merged: ";
    for (int m = left; m <=right; m++){
        cout << arr[m] << " ";
    }
}

void mergeSort(int arr[], int left, int right){
    if (left < right){
        int mid = left + (right - left) / 2;
    
    cout << "Merge: ";
    for (int i = left; i <=right; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "Left: ";
    for (int l = left; l <= mid; l++){
        cout << arr[l] << " ";
    }
    cout << " | Right: ";
    for (int r = mid + 1; r <= right; r++){
        cout << arr[r] << " ";
    }
    cout << endl;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge (arr, left, mid, right);
    }

}

void printList(int arr[], int size){
    cout << "Data: ";
    for (int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }

}
int main (){
    int arr[]= {5, 4, 2, 1, 3};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout << size << endl;
    cout << "Data sebelum sorting" << endl;
    cout << "-------------------------" << endl;
    printList(arr, size);

    cout << "Proses Merge Sort" << endl;
    cout << "-------------------------" << endl;
    mergeSort(arr, 0, size-1);

    cout << "Setelah urut" << endl;
    cout << "-------------------------" << endl;
    printList(arr, size);
    return 0;
}