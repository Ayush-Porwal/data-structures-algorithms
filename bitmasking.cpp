#include <iostream>

using namespace std;

bool isEven(int value){
    return !(value&1);
}

// assume that index system starts from 0 (right to left);

int getBit(int value, int position){
    return (value & (1<<position)) ? 1 : 0;
}

void setBit(int &value, int position){
    value =  (value | (1<<position));
}

void untSetBit(int &value, int position){
    value =  (value & ~(1<<position));
}

void updateBit(int &value, int position, int bit){
    untSetBit(value, position);
    value = (value | (bit<<position));
}

int unSetLastIBits(int value, int position){
    return (value & (-1<<position));
}

int unSetInRange(int value, int i, int j){
    return (value & ((-1<<(j+1)) | ((1<<i)-1)));
}

int replaceBits(int n, int m, int i, int j){
    n = unSetInRange(n, i, j);
    return (n |(m<<i));
}

int main() {
    int n(5), m(7);
    // check for two numbers
    cout << isEven(n) << " " << isEven(m) << endl;
    // let's print bits of 5
    cout << getBit(n, 4) << getBit(n, 3) << getBit(n, 2) << getBit(n, 1) << getBit(n, 0) << endl;
    // let's set the i=1 bit of 5, expected answer = 7
    setBit(n, 1); cout << n << endl;
    // let's unset the i=1 bit of 7, expected answer = 5;
    untSetBit(n, 1); cout << n << endl;
    // let's set i=2 bit of 5 to 1, expected answer = 5;
    updateBit(n, 2, 1); cout << n << endl;
    // let's set i=1 bit of 5 to 1, expected answer = 7;
    updateBit(n, 1, 1); cout << n << endl;
    // let's unSet last 3 bits of 15, expected answer = 8;
    cout << unSetLastIBits(15, 3) << endl;
    // let's unset bits from i = 3 to 7 of 2747, expected answer = 2563;
    cout << unSetInRange(2747, 3, 7) << endl;
    // let's obtain the number back from previous operation;
    cout << replaceBits(2563, 23, 3, 7) << endl;
    return 0;
}