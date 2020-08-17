#include <iostream>

using namespace std;

long long int factorial(int n){
    // base case
    if(n==1 || n==0) return 1; // we may write only n==0 inside if loop

    //recursive logic
    return n*factorial(n-1);
}

int main() {
    int n;
    cin >> n;
    cout << factorial(n) << endl;;
    return 0;
}