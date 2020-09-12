#include<iostream>
#include<vector>

using namespace std;

/*
    Q1: Write a function for binary search using recursion.
*/

int biSearch(vector<int> arr, int low, int high, int value){
    int mid = low + (high-low)/2;

    if(arr[mid]==value){
        return mid;
    }

    if(value > arr[mid]){
        return biSearch(arr, mid+1, high, value);
    }
    else{
        return biSearch(arr, low, mid-1, value);
    }
    return -1;
}

/*
    Q2: Write a function to compute 'a' raised to power 'n' using recursion.
*/

int power(int base, int n){
    // base case
    if(n==0){
        return 1;
    }

    // recursion logic
    return base*power(base,n-1);
}

/*
    Q3: Write a function to multiply two numbers using recursion
*/

int multiply(int a, int b){
    // base condition
    if(b==0){
        return 0;
    }

    // recursion logic
    return a + multiply(a, b-1);
}

int main(){
    int a, n;
    cin >> a >> n;
    cout << power(a,n) << endl;
    cout << multiply(a, n) << endl;

    vector<int> arr = {1,2,3,4,5};
    cout << biSearch(arr, 0, 4, 4) << endl;
    return 0;
}
