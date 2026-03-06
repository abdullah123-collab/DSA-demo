/*
 * ============================================================
 *  Circular Linked List Implementation in C++
 * ============================================================
 *  Like a singly linked list, EXCEPT the tail's next pointer
 *  always points back to the HEAD instead of NULL.
 *
 *  Visual:  head → [A] → [B] → [C] → (back to head)
 *
 *  Use-cases: round-robin scheduling, circular buffers,
 *             multiplayer board games (turn management).
 *
 *  Operations: push_front, push_back, pop_front, pop_back,
 *              insert at position, search, print
 * ============================================================
 */

#include<iostream>
using namespace std;

// -----------------------------------------------------------
// Node: building block of the circular linked list
// -----------------------------------------------------------
class Node {
public:
    int   data;   // value stored in this node
    Node* next;   // pointer to next node (tail wraps to head)

    // Constructor: initialise data; next defaults to NULL
    Node(int val) {
        data = val;
        next = NULL;
    }
};

// -----------------------------------------------------------
// List: manages the circular chain of Nodes
// -----------------------------------------------------------
class List {
    Node* head;   // pointer to the first node
    Node* tail;   // pointer to the last node
                  // Invariant: tail->next == head  (when non-empty)

public:
    // Constructor: empty list
    List() {
        head = tail = NULL;
    }

    // -------------------------------------------------------
    // push_front: insert a new node at the BEGINNING
    // Time Complexity: O(1)
    // -------------------------------------------------------
    void push_front(int val) {
        Node* newNode = new Node(val);

        if (head == NULL) {
            // First node – points to itself
            head = tail = newNode;
            newNode->next = head;
            return;
        }

        // New node points to old head; tail wraps to new head
        newNode->next = head;
        tail->next    = newNode;
        head          = newNode;
    }

    // -------------------------------------------------------
    // push_back: insert a new node at the END
    // Time Complexity: O(1)
    // -------------------------------------------------------
    void push_back(int val) {
        Node* newNode = new Node(val);

        if (head == NULL) {
            // First node – points to itself
            head = tail = newNode;
            newNode->next = head;
            return;
        }

        // Old tail points to new node; new node wraps to head
        tail->next    = newNode;
        newNode->next = head;
        tail          = newNode;
    }

    // -------------------------------------------------------
    // pop_front: remove the node at the BEGINNING
    // Time Complexity: O(1)
    // -------------------------------------------------------
    void pop_front() {
        if (head == NULL) return;

        // Only one node in the list
        if (head == tail) {
            delete head;
            head = tail = NULL;
            return;
        }

        Node* temp = head;
        head       = head->next;   // advance head
        tail->next = head;         // keep the circle intact
        delete temp;
    }

    // -------------------------------------------------------
    // pop_back: remove the node at the END
    // Time Complexity: O(n) – must find the second-last node
    // -------------------------------------------------------
    void pop_back() {
        if (head == NULL) return;

        // Only one node
        if (head == tail) {
            delete head;
            head = tail = NULL;
            return;
        }

        // Walk to the node just before tail
        Node* temp = head;
        while (temp->next != tail) {
            temp = temp->next;
        }

        // Detach old tail
        temp->next = head;   // second-last now wraps to head
        delete tail;
        tail = temp;
    }

    // -------------------------------------------------------
    // insert: insert a value at a given 0-based position
    // Time Complexity: O(n)
    // -------------------------------------------------------
    void insert(int val, int pos) {
        if (pos < 0) return;

        if (pos == 0) {
            push_front(val);
            return;
        }

        Node* temp = head;

        // Walk to the node at position (pos - 1)
        for (int i = 0; i < pos - 1; i++) {
            if (temp->next == head) {
                // Reached end of list before reaching pos-1
                cout << "Invalid Position" << endl;
                return;
            }
            temp = temp->next;
        }

        Node* newNode = new Node(val);

        // If inserting after tail, use push_back to keep invariant
        if (temp == tail) {
            push_back(val);
            return;
        }

        // Insert between temp and temp->next
        newNode->next = temp->next;
        temp->next    = newNode;
    }

    // -------------------------------------------------------
    // search: find the first occurrence of key
    // Returns 0-based index, or -1 if not found
    // Time Complexity: O(n)
    // -------------------------------------------------------
    int search(int key) {
        if (head == NULL) return -1;

        Node* temp = head;
        int   idx  = 0;

        // Traverse until we loop back to head
        do {
            if (temp->data == key) return idx;
            temp = temp->next;
            idx++;
        } while (temp != head);

        return -1;
    }

    // -------------------------------------------------------
    // printCLL: display the list showing the circular link
    // -------------------------------------------------------
    void printCLL() {
        if (head == NULL) {
            cout << "List is empty" << endl;
            return;
        }

        Node* temp = head;

        do {
            cout << temp->data << "->";
            temp = temp->next;
        } while (temp != head);

        // Show the wrap-around back to head
        cout << "(back to " << head->data << ")" << endl;
    }
};

// -----------------------------------------------------------
// main: demonstration of all List operations
// -----------------------------------------------------------
int main() {
    List cll;

    cout << "After push_back(10, 20, 30):" << endl;
    cll.push_back(10);
    cll.push_back(20);
    cll.push_back(30);
    cll.printCLL();    // 10->20->30->(back to 10)

    cout << "\nAfter push_front(5):" << endl;
    cll.push_front(5);
    cll.printCLL();    // 5->10->20->30->(back to 5)

    cout << "\nAfter pop_front():" << endl;
    cll.pop_front();
    cll.printCLL();    // 10->20->30->(back to 10)

    cout << "\nAfter pop_back():" << endl;
    cll.pop_back();
    cll.printCLL();    // 10->20->(back to 10)

    cout << "\nAfter insert(15, 1):" << endl;
    cll.insert(15, 1);
    cll.printCLL();    // 10->15->20->(back to 10)

    cout << "\nSearch for 15 → index: " << cll.search(15) << endl;

    return 0;
}