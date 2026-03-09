// ============================================
//         CIRCULAR QUEUE USING ARRAY - C++
// ============================================
// Operations:
//   enqueue(x) - Insert element at rear    O(1)
//   dequeue()  - Remove element from front O(1)
//   front()    - View front element        O(1)
//   rear()     - View rear element         O(1)
//   isEmpty()  - Check if queue is empty   O(1)
//   isFull()   - Check if queue is full    O(1)
//   size()     - Get total elements        O(1)
//   display()  - Print all elements        O(n)
// ============================================

// ─────────────────────────────────────────
// WHY CIRCULAR QUEUE?
// In a normal queue using array, once rear
// reaches the end, we can't insert even if
// front has moved forward (wasted space).
// Circular Queue reuses that empty space
// by wrapping around using % (modulo).
// ─────────────────────────────────────────

#include <iostream>
using namespace std;

class CircularQueue {
private:
    int arr[5];       // Fixed capacity of 5
    int frontIndex;
    int rearIndex;
    int count;
    int capacity;

public:
    // Constructor
    CircularQueue() {
        capacity   = 5;
        frontIndex = 0;
        rearIndex  = -1;
        count      = 0;
    }

    // Enqueue - insert at rear
    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue Overflow! Cannot enqueue " << x << endl;
            return;
        }
        rearIndex = (rearIndex + 1) % capacity;  // wrap around
        arr[rearIndex] = x;
        count++;
        cout << x << " enqueued to queue." << endl;
    }

    // Dequeue - remove from front
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow! Queue is empty." << endl;
            return -1;
        }
        int val    = arr[frontIndex];
        frontIndex = (frontIndex + 1) % capacity;  // wrap around
        count--;
        return val;
    }

    // View front element
    int front() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return -1;
        }
        return arr[frontIndex];
    }

    // View rear element
    int rear() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return -1;
        }
        return arr[rearIndex];
    }

    // Check if queue is empty
    bool isEmpty() {
        return count == 0;
    }

    // Check if queue is full
    bool isFull() {
        return count == capacity;
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
        for (int i = 0; i < count; i++) {
            cout << arr[(frontIndex + i) % capacity];
            if (i != count - 1) cout << " → ";
        }
        cout << endl;
    }
};

// ─────────────────────────────────────────
// MAIN - Test all operations
// ─────────────────────────────────────────
int main() {

    CircularQueue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);   // Overflow test

    q.display();

    cout << "Front element : " << q.front() << endl;
    cout << "Rear element  : " << q.rear()  << endl;
    cout << "Queue size    : " << q.size()  << endl;

    cout << "Dequeued: " << q.dequeue() << endl;
    cout << "Dequeued: " << q.dequeue() << endl;

    q.display();

    // Reuse freed space - key feature of circular queue
    q.enqueue(60);
    q.enqueue(70);

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
// Queue Overflow! Cannot enqueue 60
// Queue (front → rear): 10 → 20 → 30 → 40 → 50
// Front element : 10
// Rear element  : 50
// Queue size    : 5
// Dequeued: 10
// Dequeued: 20
// Queue (front → rear): 30 → 40 → 50
// 60 enqueued to queue.
// 70 enqueued to queue.
// Queue (front → rear): 30 → 40 → 50 → 60 → 70
// ============================================