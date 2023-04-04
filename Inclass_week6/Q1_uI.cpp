#include <iostream>
using namespace std;

class Stack {
private:
    int top;
    int* arr;
    int size;

public:
    Stack(int n) {
        size = n;
        top = -1;
        arr = new int[size];
    }

    ~Stack() {
        delete[] arr;
    }

    bool isFull() {
        return top == size - 1;
    }

    bool isEmpty() {
        return top == -1;
    }

    void push(int value) {
        if (isFull()) {
            cout << "Stack Overflow" << endl;
            return;
        }
        top++;
        arr[top] = value;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        int value = arr[top];
        top--;
        return value;
    }

    int stackTop() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return arr[top];
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return;
        }
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    while (true) {
        int n;
        cout << "Enter the size of the stack: ";
        cin >> n;

        Stack s(n);

        for (int i = 0; i < n; i++) {
            int value;
            cout << "Enter a value to push: ";
            cin >> value;
            s.push(value);
        }

        //s.display();
        //cout << "Stack Top: " << s.stackTop() << endl;

        int popCount;
        cout << "Enter the number of items to pop: ";
        cin >> popCount;

        for (int i = 0; i < popCount; i++) {
            cout << s.pop() << endl;
        }

        s.display();
        cout << "Stack Top: " << s.stackTop() << endl;
    }

    return 0;
}