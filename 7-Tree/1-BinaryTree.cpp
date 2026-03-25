// ============================================
//           BINARY TREE - C++
// ============================================
// Operations:
//   insert(x)   - Insert element           O(n)
//   inorder()   - Left, Root, Right        O(n)
//   preorder()  - Root, Left, Right        O(n)
//   postorder() - Left, Right, Root        O(n)
//   height()    - Height of tree           O(n)
//   countNodes()- Count total nodes        O(n)
//   search(x)   - Search for a value       O(n)
// ============================================

#include <iostream>
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

class BinaryTree {
public:
    Node* root;

    // Constructor
    BinaryTree() {
        root = nullptr;
    }

    // Insert element (level order - fills left to right)
    Node* insert(Node* node, int x) {
        if (node == nullptr) {
            return new Node(x);
        }
        if (x < node->data) {
            node->left = insert(node->left, x);
        } else {
            node->right = insert(node->right, x);
        }
        return node;
    }

    void insert(int x) {
        root = insert(root, x);
        cout << x << " inserted into tree." << endl;
    }

    // ─────────────────────────────────────
    // INORDER Traversal - Left, Root, Right
    // Gives sorted order for BST
    // ─────────────────────────────────────
    void inorder(Node* node) {
        if (node == nullptr) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    void inorder() {
        cout << "Inorder   (L → Root → R): ";
        inorder(root);
        cout << endl;
    }

    // ─────────────────────────────────────
    // PREORDER Traversal - Root, Left, Right
    // Used to copy/serialize a tree
    // ─────────────────────────────────────
    void preorder(Node* node) {
        if (node == nullptr) return;
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }

    void preorder() {
        cout << "Preorder  (Root → L → R): ";
        preorder(root);
        cout << endl;
    }

    // ─────────────────────────────────────
    // POSTORDER Traversal - Left, Right, Root
    // Used to delete a tree
    // ─────────────────────────────────────
    void postorder(Node* node) {
        if (node == nullptr) return;
        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }

    void postorder() {
        cout << "Postorder (L → R → Root): ";
        postorder(root);
        cout << endl;
    }

    // Height of tree
    int height(Node* node) {
        if (node == nullptr) return 0;
        int leftHeight  = height(node->left);
        int rightHeight = height(node->right);
        return 1 + max(leftHeight, rightHeight);
    }

    int height() {
        return height(root);
    }

    // Count total nodes
    int countNodes(Node* node) {
        if (node == nullptr) return 0;
        return 1 + countNodes(node->left) + countNodes(node->right);
    }

    int countNodes() {
        return countNodes(root);
    }

    // Search for a value
    bool search(Node* node, int x) {
        if (node == nullptr) return false;
        if (node->data == x) return true;
        return search(node->left, x) || search(node->right, x);
    }

    bool search(int x) {
        return search(root, x);
    }
};

// ─────────────────────────────────────────
// MAIN - Test all operations
// ─────────────────────────────────────────
int main() {

    BinaryTree bt;

    bt.insert(50);
    bt.insert(30);
    bt.insert(70);
    bt.insert(20);
    bt.insert(40);
    bt.insert(60);
    bt.insert(80);

    cout << endl;
    cout << "Tree Structure:" << endl;
    cout << "        50        " << endl;
    cout << "       /  \\      " << endl;
    cout << "      30   70     " << endl;
    cout << "     / \\ / \\   " << endl;
    cout << "    20 40 60 80   " << endl;
    cout << endl;

    bt.inorder();
    bt.preorder();
    bt.postorder();

    cout << endl;
    cout << "Height of tree  : " << bt.height()     << endl;
    cout << "Total nodes     : " << bt.countNodes() << endl;

    cout << endl;
    cout << "Search 40 : " << (bt.search(40) ? "Found" : "Not Found") << endl;
    cout << "Search 90 : " << (bt.search(90) ? "Found" : "Not Found") << endl;

    return 0;
}

// ============================================
// EXPECTED OUTPUT:
// 50 inserted into tree.
// 30 inserted into tree.
// 70 inserted into tree.
// 20 inserted into tree.
// 40 inserted into tree.
// 60 inserted into tree.
// 80 inserted into tree.
//
// Inorder   (L → Root → R): 20 30 40 50 60 70 80
// Preorder  (Root → L → R): 50 30 20 40 70 60 80
// Postorder (L → R → Root): 20 40 30 60 80 70 50
//
// Height of tree  : 3
// Total nodes     : 7
//
// Search 40 : Found
// Search 90 : Not Found
// ============================================