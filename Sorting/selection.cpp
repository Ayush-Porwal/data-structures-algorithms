#include <bits/stdc++.h>

using namespace std;

void selectionSort(int arr[], int n){
    for(int i=0; i<n-1; i++){
        int minIdx = i;
        for(int j=i; j<n; j++){
            if(arr[minIdx]>arr[j]){
                minIdx = j;
            }
        }
        swap(arr[minIdx], arr[i]);
    }
}

int main() {
    int arr[] = {12, 3, 54};
    int size = sizeof(arr)/sizeof(int);

    selectionSort(arr,size);

    for(auto item : arr){
        cout << item << " ";
    }
    cout << endl;

    return 0;
}