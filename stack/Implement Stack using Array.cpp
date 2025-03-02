#include <iostream>
using namespace std;

class Stack {
private:
    int* arr;
    int topIndex;
    int capacity;

public:
    // Constructor
    Stack(int size) {
        capacity = size;
        arr = new int[capacity];
        topIndex = -1;
    }

    // Push an element onto the stack
    void push(int x) {
        if (isFull()) {
            cout << "Stack Overflow! Cannot push " << x << endl;
            return;
        }
        arr[++topIndex] = x;
    }

    // Pop the top element
    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! Nothing to pop." << endl;
            return;
        }
        topIndex--;
    }

    // Get the top element
    int top() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return arr[topIndex];
    }

    // Check if stack is empty
    bool isEmpty() {
        return topIndex == -1;
    }

    // Check if stack is full
    bool isFull() {
        return topIndex == capacity - 1;
    }

    // Destructor
    ~Stack() {
        delete[] arr;
    }
};

int main() {
    Stack s(5);

    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top element: " << s.top() << endl;

    s.pop();
    cout << "Top after pop: " << s.top() << endl;

    return 0;
}
