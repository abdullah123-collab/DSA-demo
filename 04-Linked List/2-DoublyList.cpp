/*
 * ============================================================
 *  Doubly Linked List Implementation in C++
 * ============================================================
 *  Each node holds data, a pointer to the NEXT node, and a
 *  pointer to the PREVIOUS node.
 *
 *  Advantage over singly LL:
 *    • pop_back is O(1) because we can reach the second-last
 *      node directly via tail->prev.
 *    • Bidirectional traversal is possible.
 *
 *  Operations: push_front, push_back, pop_front, pop_back,
 *              insert at position, search, print forward,
 *              print backward
 * ============================================================
 */

#include<iostream>
using namespace std;

// -----------------------------------------------------------
// Node: building block of the doubly linked list
// -----------------------------------------------------------
class Node {
public:
    int   data;   // value stored in this node
    Node* next;   // pointer to the NEXT node
    Node* prev;   // pointer to the PREVIOUS node

    // Constructor: set data; both links default to NULL
    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

// -----------------------------------------------------------
// List: manages the doubly linked chain of Nodes
// -----------------------------------------------------------
class List {
    Node* head;   // pointer to the first node
    Node* tail;   // pointer to the last node

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
            head = tail = newNode;
            return;
        }

        // Wire new node: its next is old head; old head's prev is new node
        newNode->next = head;
        head->prev    = newNode;
        head          = newNode;
    }

    // -------------------------------------------------------
    // push_back: insert a new node at the END
    // Time Complexity: O(1)
    // -------------------------------------------------------
    void push_back(int val) {
        Node* newNode = new Node(val);

        if (head == NULL) {
            head = tail = newNode;
            return;
        }

        // Wire new node: its prev is old tail; old tail's next is new node
        newNode->prev = tail;
        tail->next    = newNode;
        tail          = newNode;
    }

    // -------------------------------------------------------
    // pop_front: remove the node at the BEGINNING
    // Time Complexity: O(1)
    // -------------------------------------------------------
    void pop_front() {
        if (head == NULL) return;

        Node* temp = head;
        head       = head->next;

        if (head != NULL) {
            head->prev = NULL;   // new head has no predecessor
        } else {
            tail = NULL;         // list is now empty
        }

        delete temp;
    }

    // -------------------------------------------------------
    // pop_back: remove the node at the END
    // Time Complexity: O(1)  – prev pointer makes this fast!
    // -------------------------------------------------------
    void pop_back() {
        if (head == NULL) return;

        Node* temp = tail;
        tail       = tail->prev;

        if (tail != NULL) {
            tail->next = NULL;   // new tail has no successor
        } else {
            head = NULL;         // list is now empty
        }

        delete temp;
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
            if (temp == NULL) {
                cout << "Invalid Position" << endl;
                return;
            }
            temp = temp->next;
        }

        // If inserting after the tail, just push_back
        if (temp->next == NULL) {
            push_back(val);
            return;
        }

        // Insert between temp and temp->next
        Node* newNode       = new Node(val);
        newNode->next       = temp->next;
        newNode->prev       = temp;
        temp->next->prev    = newNode;
        temp->next          = newNode;
    }

    // -------------------------------------------------------
    // search: find the first occurrence of key
    // Returns 0-based index, or -1 if not found
    // Time Complexity: O(n)
    // -------------------------------------------------------
    int search(int key) {
        Node* temp = head;
        int   idx  = 0;

        while (temp != NULL) {
            if (temp->data == key) return idx;
            temp = temp->next;
            idx++;
        }

        return -1;
    }

    // -------------------------------------------------------
    // printForward: display list from head to tail
    // -------------------------------------------------------
    void printForward() {
        Node* temp = head;

        cout << "NULL<-";
        while (temp != NULL) {
            cout << temp->data;
            if (temp->next != NULL) cout << "<->";
            temp = temp->next;
        }
        cout << "->NULL" << endl;
    }

    // -------------------------------------------------------
    // printBackward: display list from tail to head
    // -------------------------------------------------------
    void printBackward() {
        Node* temp = tail;

        cout << "NULL<-";
        while (temp != NULL) {
            cout << temp->data;
            if (temp->prev != NULL) cout << "<->";
            temp = temp->prev;
        }
        cout << "->NULL" << endl;
    }
};

// -----------------------------------------------------------
// main: demonstration of all List operations
// -----------------------------------------------------------
int main() {
    List dll;

    cout << "After push_back(10, 20, 30):" << endl;
    dll.push_back(10);
    dll.push_back(20);
    dll.push_back(30);
    dll.printForward();    // NULL<-10<->20<->30->NULL

    cout << "\nAfter push_front(5):" << endl;
    dll.push_front(5);
    dll.printForward();    // NULL<-5<->10<->20<->30->NULL

    cout << "\nAfter pop_back():" << endl;
    dll.pop_back();
    dll.printForward();    // NULL<-5<->10<->20->NULL

    cout << "\nAfter pop_front():" << endl;
    dll.pop_front();
    dll.printForward();    // NULL<-10<->20->NULL

    cout << "\nAfter insert(15, 1):" << endl;
    dll.insert(15, 1);
    dll.printForward();    // NULL<-10<->15<->20->NULL

    cout << "\nBackward traversal:" << endl;
    dll.printBackward();   // NULL<-20<->15<->10->NULL

    cout << "\nSearch for 15 → index: " << dll.search(15) << endl;

    return 0;
}