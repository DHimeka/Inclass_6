#include <iostream>
#include <chrono> // for timing
using namespace std;

#define MAX_SIZE 1000

class Stack {
private:
    int top;
    int arr[MAX_SIZE];

public:
    Stack() {
        top = -1;
    }

    bool isFull() {
        return top == MAX_SIZE - 1;
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

class Node {
public:
    int data;
    Node* next;
};

class LinkedListStack {
private:
    Node* top;

public:
    LinkedListStack() {
        top = nullptr;
    }

    ~LinkedListStack() {
        Node* p = top;
        while (top) {
            top = top->next;
            delete p;
            p = top;
        }
    }

    bool isEmpty() {
        return top == nullptr;
    }

    void push(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = top;
        top = newNode;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        int value = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return value;
    }

    int stackTop() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return top->data;
    }

    void display() {
        Node* p = top;
        while (p) {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }
};

int main() {
    Stack s;
    LinkedListStack ls;
    int pushCount = 10;
    int pushCount2 = 4;
    int popCount = 5;

    // push random values to the stack 
    auto start1 = chrono::high_resolution_clock::now();
    for (int i = 0; i < pushCount; i++) {
        int value = rand() % 100;
        s.push(value);
    }
    cout << "Current stack: ";
    s.display();
    for (int i = 0; i < popCount; i++) {
        s.pop();
    }
    cout << "Current stack: ";
    s.display();
    for (int i = 0; i < pushCount2; i++) {
        int value = rand() % 100;
        s.push(value);
    }
    cout << "Current stack: ";
    s.display();

    auto end1 = chrono::high_resolution_clock::now();
    auto duration1 = chrono::duration_cast<chrono::microseconds>(end1 - start1);
    cout << " array Stack took " << duration1.count() << " microseconds" << endl;

    // push random values to the linked list stack  
    auto start2 = chrono::high_resolution_clock::now();
    for (int i = 0; i < pushCount; i++) {
        int value = rand() % 100;
        ls.push(value);
    }
    cout << "Current stack: ";
    ls.display();
    for (int i = 0; i < popCount; i++) {
        ls.pop();
    }
    cout << "Current stack: ";
    ls.display();
    for (int i = 0; i < pushCount2; i++) {
        int value = rand() % 100;
        ls.push(value);
    }
    cout << "Current stack: ";
    ls.display();

    auto end2 = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end2 - start2);
    cout << "Linked list Stack took " << duration.count() << " microseconds" << endl;
}
