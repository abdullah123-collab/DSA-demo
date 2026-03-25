// ============================================
//        LEVEL ORDER TRAVERSAL - C++
// ============================================
// Also known as: BFS (Breadth First Search)
//
// Operations:
//   levelOrder()     - Print level by level   O(n)
//   levelOrderLines()- Print each level on
//                      its own line            O(n)
//   height()         - Height of tree          O(n)
//   leftView()       - First node of each level O(n)
//   rightView()      - Last node of each level  O(n)
// ============================================

#include <iostream>
#include <queue>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data  = val;
        left  = nullptr;
        right = nullptr;
    }
};

// Helper to insert into BST
Node* insert(Node* node, int x) {
    if (node == nullptr) return new Node(x);
    if (x < node->data) node->left  = insert(node->left, x);
    else                node->right = insert(node->right, x);
    return node;
}

// ─────────────────────────────────────────
// LEVEL ORDER - print all nodes level by level
// Uses a Queue (FIFO) to process each level
// ─────────────────────────────────────────
void levelOrder(Node* root) {
    if (root == nullptr) return;
    queue<Node*> q;
    q.push(root);
    cout << "Level Order: ";
    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();
        cout << curr->data << " ";
        if (curr->left)  q.push(curr->left);
        if (curr->right) q.push(curr->right);
    }
    cout << endl;
}

// ─────────────────────────────────────────
// LEVEL ORDER LINE BY LINE
// Print each level on a separate line
// ─────────────────────────────────────────
void levelOrderLines(Node* root) {
    if (root == nullptr) return;
    queue<Node*> q;
    q.push(root);
    int level = 1;
    while (!q.empty()) {
        int size = q.size();   // number of nodes at current level
        cout << "Level " << level << " : ";
        for (int i = 0; i < size; i++) {
            Node* curr = q.front();
            q.pop();
            cout << curr->data << " ";
            if (curr->left)  q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
        cout << endl;
        level++;
    }
}

// ─────────────────────────────────────────
// HEIGHT OF TREE using level order
// ─────────────────────────────────────────
int height(Node* root) {
    if (root == nullptr) return 0;
    queue<Node*> q;
    q.push(root);
    int height = 0;
    while (!q.empty()) {
        int size = q.size();
        height++;
        for (int i = 0; i < size; i++) {
            Node* curr = q.front();
            q.pop();
            if (curr->left)  q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
    }
    return height;
}

// ─────────────────────────────────────────
// LEFT VIEW - first node of each level
// ─────────────────────────────────────────
void leftView(Node* root) {
    if (root == nullptr) return;
    queue<Node*> q;
    q.push(root);
    cout << "Left View  : ";
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            Node* curr = q.front();
            q.pop();
            if (i == 0) cout << curr->data << " ";  // first node of level
            if (curr->left)  q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
    }
    cout << endl;
}

// ─────────────────────────────────────────
// RIGHT VIEW - last node of each level
// ─────────────────────────────────────────
void rightView(Node* root) {
    if (root == nullptr) return;
    queue<Node*> q;
    q.push(root);
    cout << "Right View : ";
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            Node* curr = q.front();
            q.pop();
            if (i == size - 1) cout << curr->data << " ";  // last node of level
            if (curr->left)  q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
    }
    cout << endl;
}

// ─────────────────────────────────────────
// MAIN - Test all operations
// ─────────────────────────────────────────
int main() {

    Node* root = nullptr;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    cout << "Tree Structure:" << endl;
    cout << "        50        " << endl;
    cout << "       /  \\      " << endl;
    cout << "      30   70     " << endl;
    cout << "     / \\ / \\   " << endl;
    cout << "    20 40 60 80   " << endl;
    cout << endl;

    levelOrder(root);

    cout << endl;
    levelOrderLines(root);

    cout << endl;
    cout << "Height     : " << height(root) << endl;

    cout << endl;
    leftView(root);
    rightView(root);

    return 0;
}

// ============================================
// EXPECTED OUTPUT:
// Level Order: 50 30 70 20 40 60 80
//
// Level 1 : 50
// Level 2 : 30 70
// Level 3 : 20 40 60 80
//
// Height     : 3
//
// Left View  : 50 30 20
// Right View : 50 70 80
// ============================================