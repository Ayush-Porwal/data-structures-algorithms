#include <iostream>

using namespace std;

int fibonacci(int n){
    //base condition
    if(n==1 || n==2) return 1;
    

    // recursion logic
    return fibonacci(n-1) + fibonacci(n-2);
}

void printForward(int n){
    // base condition
    if(n==1){
        cout << n << " ";
        return;
    }

    // recursion logic
    printForward(n-1);
    // after f(n) exits, print the value n where n!=1;
    cout << n << " ";
}

void printBackward(int n){
    // base condition
    if(n==1){
        cout << 1 << " ";
        return;
    }

    // recursion logic
    cout << n << " ";
    printBackward(n-1);
}

int main() {
    int n;
    cin >> n;
    cout << fibonacci(n) << endl;
    printForward(n);
    cout << endl;
    printBackward(n);
    cout << endl;
    return 0;
}