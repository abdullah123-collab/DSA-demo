// ============================================
//          TREE TRAVERSALS - C++
// ============================================
// Traversals Covered:
//   1. Inorder   - Left, Root, Right        O(n)
//   2. Preorder  - Root, Left, Right        O(n)
//   3. Postorder - Left, Right, Root        O(n)
//
// Each traversal done in two ways:
//   - Recursive
//   - Iterative (using stack)
// ============================================

#include <iostream>
#include <stack>
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
// 1. INORDER  →  Left, Root, Right
//    Result: Sorted ascending order
// ─────────────────────────────────────────
void inorderRecursive(Node* node) {
    if (node == nullptr) return;
    inorderRecursive(node->left);
    cout << node->data << " ";
    inorderRecursive(node->right);
}

void inorderIterative(Node* root) {
    stack<Node*> st;
    Node* curr = root;
    while (curr != nullptr || !st.empty()) {
        while (curr != nullptr) {
            st.push(curr);
            curr = curr->left;
        }
        curr = st.top();
        st.pop();
        cout << curr->data << " ";
        curr = curr->right;
    }
}

// ─────────────────────────────────────────
// 2. PREORDER  →  Root, Left, Right
//    Result: Used to copy or serialize tree
// ─────────────────────────────────────────
void preorderRecursive(Node* node) {
    if (node == nullptr) return;
    cout << node->data << " ";
    preorderRecursive(node->left);
    preorderRecursive(node->right);
}

void preorderIterative(Node* root) {
    if (root == nullptr) return;
    stack<Node*> st;
    st.push(root);
    while (!st.empty()) {
        Node* curr = st.top();
        st.pop();
        cout << curr->data << " ";
        // Push right first so left is processed first
        if (curr->right) st.push(curr->right);
        if (curr->left)  st.push(curr->left);
    }
}

// ─────────────────────────────────────────
// 3. POSTORDER  →  Left, Right, Root
//    Result: Used to delete a tree
// ─────────────────────────────────────────
void postorderRecursive(Node* node) {
    if (node == nullptr) return;
    postorderRecursive(node->left);
    postorderRecursive(node->right);
    cout << node->data << " ";
}

void postorderIterative(Node* root) {
    if (root == nullptr) return;
    stack<Node*> st1, st2;
    st1.push(root);
    while (!st1.empty()) {
        Node* curr = st1.top();
        st1.pop();
        st2.push(curr);
        if (curr->left)  st1.push(curr->left);
        if (curr->right) st1.push(curr->right);
    }
    while (!st2.empty()) {
        cout << st2.top()->data << " ";
        st2.pop();
    }
}

// ─────────────────────────────────────────
// MAIN - Test all traversals
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

    cout << "-----------------------------" << endl;
    cout << " INORDER (Left->Root->Right) " << endl;
    cout << "-----------------------------" << endl;
    cout << "Recursive : ";
    inorderRecursive(root);
    cout << endl;
    cout << "Iterative : ";
    inorderIterative(root);
    cout << endl;

    cout << endl;
    cout << "------------------------------" << endl;
    cout << " PREORDER (Root->Left->Right) " << endl;
    cout << "------------------------------" << endl;
    cout << "Recursive : ";
    preorderRecursive(root);
    cout << endl;
    cout << "Iterative : ";
    preorderIterative(root);
    cout << endl;

    cout << endl;
    cout << "------------------------------" << endl;
    cout << " POSTORDER (Left->Right->Root)" << endl;
    cout << "------------------------------" << endl;
    cout << "Recursive : ";
    postorderRecursive(root);
    cout << endl;
    cout << "Iterative : ";
    postorderIterative(root);
    cout << endl;

    return 0;
}

// ============================================
// EXPECTED OUTPUT:
// -----------------------------
//  INORDER (Left->Root->Right)
// -----------------------------
// Recursive : 20 30 40 50 60 70 80
// Iterative : 20 30 40 50 60 70 80
//
// ------------------------------
//  PREORDER (Root->Left->Right)
// ------------------------------
// Recursive : 50 30 20 40 70 60 80
// Iterative : 50 30 20 40 70 60 80
//
// ------------------------------
//  POSTORDER (Left->Right->Root)
// ------------------------------
// Recursive : 20 40 30 60 80 70 50
// Iterative : 20 40 30 60 80 70 50
// ============================================