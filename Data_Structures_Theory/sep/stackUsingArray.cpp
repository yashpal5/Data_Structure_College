#include <iostream>
using namespace std;
#define MAX 5

class Stack {
    int arr[MAX];
    int top;

public:
    Stack() { top = -1; }

    void push(int value) {
        if (top == MAX - 1) {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = value;
        cout << value << " pushed into stack\n";
    }

    void pop() {
        if (top == -1) {
            cout << "Stack Underflow\n";
            return;
        }
        cout << arr[top--] << " popped from stack\n";
    }

    void peek() {
        if (top == -1) {
            cout << "Stack is empty\n";
            return;
        }
        cout << "Top element is " << arr[top] << "\n";
    }

    void display() {
        if (top == -1) {
            cout << "Stack is empty\n";
            return;
        }
        cout << "Stack elements: ";
        for (int i = top; i >= 0; i--)
            cout << arr[i] << " ";
        cout << "\n";
    }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.display();
    s.pop();
    s.peek();
    s.display();
    return 0;
}
