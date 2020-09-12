#include <bits/stdc++.h>

using namespace std;

void insertionSort(int arr[], int n){
    for(int i=1; i<n; i++){
        int j = i;
        
        while(j-1>=0 and arr[j]<arr[j-1]){
            swap(arr[j], arr[j-1]);
            j--;
        }
    }
}


int main() {
    int arr[] = {5, 2, 3, 0, 1};
    int size = sizeof(arr)/sizeof(int);

    insertionSort(arr,size);

    for(auto item : arr){
        cout << item << " ";
    }
    
    cout << endl;

    return 0;
}