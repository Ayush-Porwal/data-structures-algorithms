#include<iostream>

using namespace std;

#define size 5

class Stack{

private:
    int top;
    int arr[size];

public:
    Stack(){
        top = -1;
    }

    void push(int value){
        if(top==size-1){
            cout << "Stack Overflow\n";
        }
        else{
            arr[++top] = value;
        }
    }

    int peek(){
        if(top>=0) return arr[top];
        else cout << "Empty stack\n";
    }

    int pop(){
        if(top>=0) return arr[top--];
        else{
            cout << "Stack underflow\n";
            return 0;
        }
    }

    bool isEmpty(){
        return top<0;
    }

    //adding a function to print stack;
    void print(){
        cout << "Stack is: ";
        for(int i=0; i<=top; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    class Stack S;
    cout << S.isEmpty() << endl;
    S.push(1);
    S.push(2);
    S.push(3);
    S.push(4);
    S.push(5);
    S.pop();
    S.pop();
    S.pop();
    S.pop();
    S.pop();
    S.pop();
    S.push(6);
    S.print();
    return 0;
}