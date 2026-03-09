// ============================================
//      QUEUE USING LINKED LIST - C++
// ============================================
// Operations:
//   enqueue(x) - Insert element at rear    O(1)
//   dequeue()  - Remove element from front O(1)
//   front()    - View front element        O(1)
//   rear()     - View rear element         O(1)
//   isEmpty()  - Check if queue is empty   O(1)
//   size()     - Get total elements        O(1)
//   display()  - Print all elements        O(n)
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

class Queue {
private:
    Node* frontNode;
    Node* rearNode;
    int count;

public:
    // Constructor
    Queue() {
        frontNode = nullptr;
        rearNode  = nullptr;
        count     = 0;
    }

    // Destructor - free all memory
    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    // Enqueue - insert at rear
    void enqueue(int x) {
        Node* newNode = new Node(x);
        if (isEmpty()) {
            frontNode = newNode;
            rearNode  = newNode;
        } else {
            rearNode->next = newNode;
            rearNode       = newNode;
        }
        count++;
        cout << x << " enqueued to queue." << endl;
    }

    // Dequeue - remove from front
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow! Queue is empty." << endl;
            return -1;
        }
        Node* temp = frontNode;
        int val    = temp->data;
        frontNode  = frontNode->next;
        if (frontNode == nullptr) {
            rearNode = nullptr;
        }
        delete temp;
        count--;
        return val;
    }

    // View front element
    int front() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return -1;
        }
        return frontNode->data;
    }

    // View rear element
    int rear() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return -1;
        }
        return rearNode->data;
    }

    // Check if queue is empty
    bool isEmpty() {
        return frontNode == nullptr;
    }

    // Get current size
    int size() {
        return count;
    }

    // Display all elements
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Queue (front → rear): ";
        Node* temp = frontNode;
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

    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    q.display();

    cout << "Front element : " << q.front() << endl;
    cout << "Rear element  : " << q.rear()  << endl;
    cout << "Queue size    : " << q.size()  << endl;

    cout << "Dequeued: " << q.dequeue() << endl;
    cout << "Dequeued: " << q.dequeue() << endl;

    q.display();

    return 0;
}

// ============================================
// EXPECTED OUTPUT:
// 10 enqueued to queue.
// 20 enqueued to queue.
// 30 enqueued to queue.
// 40 enqueued to queue.
// 50 enqueued to queue.
// Queue (front → rear): 10 → 20 → 30 → 40 → 50
// Front element : 10
// Rear element  : 50
// Queue size    : 5
// Dequeued: 10
// Dequeued: 20
// Queue (front → rear): 30 → 40 → 50
// ============================================
