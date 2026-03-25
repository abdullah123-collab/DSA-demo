/*
 * ============================================================
 *  Singly Linked List Implementation in C++
 * ============================================================
 *  Each node holds data and a pointer to the NEXT node only.
 *  Operations: push_front, push_back, pop_front, pop_back,
 *              insert at position, search, print
 * ============================================================
 */

#include<iostream>
using namespace std;

// -----------------------------------------------------------
// Node: building block of the linked list
// -----------------------------------------------------------
class Node {
public:
    int   data;   // value stored in this node
    Node* next;   // pointer to the next node (NULL if last)

    // Constructor: initialise data and set next to NULL
    Node(int val) {
        data = val;
        next = NULL;
    }
};

// -----------------------------------------------------------
// List: manages the chain of Nodes
// -----------------------------------------------------------
class List {
    Node* head;   // pointer to the first node
    Node* tail;   // pointer to the last node

public:
    // Constructor: empty list – both pointers start as NULL
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
            // List was empty – new node is both head and tail
            head = tail = newNode;
            return;
        }

        // Point new node to the current head, then update head
        newNode->next = head;
        head = newNode;
    }

    // -------------------------------------------------------
    // push_back: insert a new node at the END
    // Time Complexity: O(1)  – tail pointer makes this fast
    // -------------------------------------------------------
    void push_back(int val) {
        Node* newNode = new Node(val);

        if (head == NULL) {
            // List was empty
            head = tail = newNode;
        } else {
            // Link current tail to new node, advance tail
            tail->next = newNode;
            tail = newNode;
        }
    }

    // -------------------------------------------------------
    // pop_front: remove the node at the BEGINNING
    // Time Complexity: O(1)
    // -------------------------------------------------------
    void pop_front() {
        if (head == NULL) return;   // nothing to remove

        Node* temp = head;          // save current head
        head = head->next;          // move head forward
        temp->next = NULL;          // isolate removed node
        delete temp;                // free memory
    }

    // -------------------------------------------------------
    // pop_back: remove the node at the END
    // Time Complexity: O(n)  – must walk to second-last node
    // -------------------------------------------------------
    void pop_back() {
        if (head == NULL) return;   // nothing to remove

        // Special case: only one node in the list
        if (head == tail) {
            delete head;
            head = tail = NULL;
            return;
        }

        // Walk until temp->next is the tail
        Node* temp = head;
        while (temp->next != tail) {
            temp = temp->next;
        }

        // Detach tail and update
        temp->next = NULL;
        delete tail;
        tail = temp;
    }

    // -------------------------------------------------------
    // insert: insert a value at a given 0-based position
    // pos == 0  →  same as push_front
    // Time Complexity: O(n)
    // -------------------------------------------------------
    void insert(int val, int pos) {
        if (pos < 0) return;        // invalid position

        if (pos == 0) {
            push_front(val);
            return;
        }

        Node* temp = head;

        // Advance (pos-1) steps to reach the node just before
        // the desired insertion point
        for (int i = 0; i < pos - 1; i++) {
            if (temp == NULL) {
                cout << "Invalid Position" << endl;
                return;
            }
            temp = temp->next;
        }

        // Insert new node between temp and temp->next
        Node* newNode   = new Node(val);
        newNode->next   = temp->next;
        temp->next      = newNode;

        // If we inserted at the very end, update tail
        if (newNode->next == NULL) {
            tail = newNode;
        }
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

        return -1;   // key not found
    }

    // -------------------------------------------------------
    // printLL: display the list in "data->data->NULL" format
    // -------------------------------------------------------
    void printLL() {
        Node* temp = head;

        while (temp != NULL) {
            cout << temp->data << "->";
            temp = temp->next;
        }

        cout << "NULL" << endl;
    }
};

// -----------------------------------------------------------
// main: demonstration of all List operations
// -----------------------------------------------------------
int main() {
    List ll;

    cout << "Initial list after push_front(20), push_front(30), push_front(40):" << endl;
    ll.push_front(20);
    ll.push_front(30);
    ll.push_front(40);
    ll.printLL();   // 40->30->20->NULL

    cout << "\nAfter push_front(50):" << endl;
    ll.push_front(50);
    ll.printLL();   // 50->40->30->20->NULL

    cout << "\nAfter push_back(60):" << endl;
    ll.push_back(60);
    ll.printLL();   // 50->40->30->20->60->NULL

    cout << "\nAfter pop_front():" << endl;
    ll.pop_front();
    ll.printLL();   // 40->30->20->60->NULL

    cout << "\nAfter pop_back():" << endl;
    ll.pop_back();
    ll.printLL();   // 40->30->20->NULL

    cout << "\nAfter insert(70, 2):" << endl;
    ll.insert(70, 2);
    ll.printLL();   // 40->30->70->20->NULL

    cout << "\nSearch for 20 → index: " << ll.search(20) << endl;

    return 0;
}