#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

class Stack {
private:
    Node* top;

public:
    Stack() {
        top = nullptr;
    }

    ~Stack() {
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
    int n;
    cout << "Enter the number of values to push: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        int value;
        cout << "Enter a value to push: ";
        cin >> value;
        s.push(value);
    }

    s.display();

    int m;
    cout << "Enter the number of items to pop: ";
    cin >> m;
    for (int i = 0; i < m; i++) {
        cout << s.pop() << " ";
    }
    cout << endl;

    cout << "Stack top: " << s.stackTop() << endl;
    cout << "Is stack empty? " << (s.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}