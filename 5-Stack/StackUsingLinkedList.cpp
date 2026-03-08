// ============================================
//       STACK USING LINKED LIST - C++
// ============================================
// Operations:
//   push(x)   - Insert element at top     O(1)
//   pop()     - Remove top element        O(1)
//   peek()    - View top element          O(1)
//   isEmpty() - Check if stack is empty   O(1)
//   size()    - Get total elements        O(1)
//   display() - Print all elements        O(n)
// ============================================

#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class Stack {
private:
    Node* top;
    int count;

public:
    // Constructor
    Stack() {
        top = nullptr;
        count = 0;
    }

    // Destructor - free all memory
    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }

    // Push element onto stack
    void push(int x) {
        Node* newNode = new Node(x);
        newNode->next = top;
        top = newNode;
        count++;
        cout << x << " pushed to stack." << endl;
    }

    // Pop element from stack
    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! Stack is empty." << endl;
            return -1;
        }
        Node* temp = top;
        int popped = temp->data;
        top = top->next;
        delete temp;
        count--;
        return popped;
    }

    // Peek top element
    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return -1;
        }
        return top->data;
    }

    // Check if stack is empty
    bool isEmpty() {
        return top == nullptr;
    }

    // Get current size
    int size() {
        return count;
    }

    // Display all elements
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "Stack (top → bottom): ";
        Node* temp = top;
        while (temp != nullptr) {
            cout << temp->data;
            if (temp->next != nullptr) cout << " → ";
            temp = temp->next;
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