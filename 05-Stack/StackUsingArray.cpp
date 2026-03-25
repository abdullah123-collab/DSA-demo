// ============================================
//         STACK USING ARRAY - C++
// ============================================
// Operations:
//   push(x)   - Insert element at top     O(1)
//   pop()     - Remove top element        O(1)
//   peek()    - View top element          O(1)
//   isEmpty() - Check if stack is empty   O(1)
//   isFull()  - Check if stack is full    O(1)
//   display() - Print all elements        O(n)
// ============================================

#include <iostream>
using namespace std;

class Stack {
private:
    int arr[100];
    int top;

public:
    // Constructor
    Stack() {
        top = -1;
    }

    // Push element onto stack
    void push(int x) {
        if (isFull()) {
            cout << "Stack Overflow! Cannot push " << x << endl;
            return;
        }
        arr[++top] = x;
        cout << x << " pushed to stack." << endl;
    }

    // Pop element from stack
    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! Stack is empty." << endl;
            return -1;
        }
        return arr[top--];
    }

    // Peek top element
    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return -1;
        }
        return arr[top];
    }

    // Check if stack is empty
    bool isEmpty() {
        return top == -1;
    }

    // Check if stack is full
    bool isFull() {
        return top == 99;
    }

    // Get current size
    int size() {
        return top + 1;
    }

    // Display all elements
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "Stack (top → bottom): ";
        for (int i = top; i >= 0; i--) {
            cout << arr[i];
            if (i != 0) cout << " → ";
        }
        cout << endl;
    }
};

// ─────────────────────────────────────────
// MAIN - Test all operations
// ─────────────────────────────────────────
int main() {

    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    s.display();

    cout << "Top element : " << s.peek() << endl;
    cout << "Stack size  : " << s.size() << endl;

    cout << "Popped: " << s.pop() << endl;
    cout << "Popped: " << s.pop() << endl;

    s.display();

    return 0;
}

// ============================================
// EXPECTED OUTPUT:
// 10 pushed to stack.
// 20 pushed to stack.
// 30 pushed to stack.
// 40 pushed to stack.
// 50 pushed to stack.
// Stack (top → bottom): 50 → 40 → 30 → 20 → 10
// Top element : 50
// Stack size  : 5
// Popped: 50
// Popped: 40
// Stack (top → bottom): 30 → 20 → 10
// ============================================