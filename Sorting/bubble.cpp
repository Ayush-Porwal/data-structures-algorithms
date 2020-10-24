#include <bits/stdc++.h>

using namespace std;

void bubbleSort(int arr[], int n){
    while(n){
        for(int i=0; i<n-1; i++){
            if(arr[i] > arr[i+1]){
                swap(arr[i], arr[i+1]);
            }
        }
        n--;
    }
}


int main() {
    int arr[] = {5, 2, 3, 0, 1};
    int size = sizeof(arr)/sizeof(int);

    bubbleSort(arr,size);

    for(auto item : arr){
        cout << item << " ";
    }
    cout << endl;

    return 0;
}