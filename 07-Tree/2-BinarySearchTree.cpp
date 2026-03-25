// ============================================
//        BINARY SEARCH TREE (BST) - C++
// ============================================
// Property:
//   Left child  < Parent
//   Right child > Parent
//
// Operations:
//   insert(x)   - Insert element           O(log n) avg
//   search(x)   - Search for a value       O(log n) avg
//   deleteNode()- Delete a node            O(log n) avg
//   inorder()   - Sorted order traversal   O(n)
//   minValue()  - Smallest element         O(log n)
//   maxValue()  - Largest element          O(log n)
//   height()    - Height of tree           O(n)
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

class BST {
public:
    Node* root;

    // Constructor
    BST() {
        root = nullptr;
    }

    // ─────────────────────────────────────
    // INSERT
    // ─────────────────────────────────────
    Node* insert(Node* node, int x) {
        if (node == nullptr) return new Node(x);
        if (x < node->data)
            node->left  = insert(node->left, x);
        else if (x > node->data)
            node->right = insert(node->right, x);
        else
            cout << x << " already exists in BST." << endl;
        return node;
    }

    void insert(int x) {
        root = insert(root, x);
        cout << x << " inserted into BST." << endl;
    }

    // ─────────────────────────────────────
    // SEARCH
    // ─────────────────────────────────────
    bool search(Node* node, int x) {
        if (node == nullptr) return false;
        if (node->data == x) return true;
        if (x < node->data)  return search(node->left, x);
        return search(node->right, x);
    }

    bool search(int x) {
        return search(root, x);
    }

    // ─────────────────────────────────────
    // MINIMUM VALUE (leftmost node)
    // ─────────────────────────────────────
    Node* minNode(Node* node) {
        while (node->left != nullptr)
            node = node->left;
        return node;
    }

    int minValue() {
        if (root == nullptr) {
            cout << "BST is empty." << endl;
            return -1;
        }
        return minNode(root)->data;
    }

    // ─────────────────────────────────────
    // MAXIMUM VALUE (rightmost node)
    // ─────────────────────────────────────
    int maxValue() {
        if (root == nullptr) {
            cout << "BST is empty." << endl;
            return -1;
        }
        Node* node = root;
        while (node->right != nullptr)
            node = node->right;
        return node->data;
    }

    // ─────────────────────────────────────
    // DELETE NODE
    // 3 cases:
    //   1. Node has no children  → simply remove
    //   2. Node has one child    → replace with child
    //   3. Node has two children → replace with inorder successor
    // ─────────────────────────────────────
    Node* deleteNode(Node* node, int x) {
        if (node == nullptr) {
            cout << x << " not found in BST." << endl;
            return nullptr;
        }
        if (x < node->data) {
            node->left  = deleteNode(node->left, x);
        } else if (x > node->data) {
            node->right = deleteNode(node->right, x);
        } else {
            // Case 1: No children
            if (node->left == nullptr && node->right == nullptr) {
                delete node;
                return nullptr;
            }
            // Case 2: One child
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            }
            if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            // Case 3: Two children
            // Find inorder successor (smallest in right subtree)
            Node* successor  = minNode(node->right);
            node->data       = successor->data;
            node->right      = deleteNode(node->right, successor->data);
        }
        return node;
    }

    void deleteNode(int x) {
        root = deleteNode(root, x);
        cout << x << " deleted from BST." << endl;
    }

    // ─────────────────────────────────────
    // INORDER TRAVERSAL (gives sorted output)
    // ─────────────────────────────────────
    void inorder(Node* node) {
        if (node == nullptr) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    void inorder() {
        cout << "Inorder (sorted): ";
        inorder(root);
        cout << endl;
    }

    // Height of tree
    int height(Node* node) {
        if (node == nullptr) return 0;
        return 1 + max(height(node->left), height(node->right));
    }

    int height() {
        return height(root);
    }
};

// ─────────────────────────────────────────
// MAIN - Test all operations
// ─────────────────────────────────────────
int main() {

    BST bst;

    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);

    cout << endl;
    cout << "BST Structure:" << endl;
    cout << "        50        " << endl;
    cout << "       /  \\      " << endl;
    cout << "      30   70     " << endl;
    cout << "     / \\ / \\   " << endl;
    cout << "    20 40 60 80   " << endl;
    cout << endl;

    bst.inorder();

    cout << endl;
    cout << "Min value   : " << bst.minValue() << endl;
    cout << "Max value   : " << bst.maxValue() << endl;
    cout << "Height      : " << bst.height()   << endl;

    cout << endl;
    cout << "Search 40   : " << (bst.search(40) ? "Found" : "Not Found") << endl;
    cout << "Search 90   : " << (bst.search(90) ? "Found" : "Not Found") << endl;

    cout << endl;
    bst.deleteNode(20);   // Case 1: no children
    bst.deleteNode(30);   // Case 2: one child
    bst.deleteNode(50);   // Case 3: two children

    cout << endl;
    bst.inorder();

    return 0;
}

// ============================================
// EXPECTED OUTPUT:
// 50 inserted into BST.
// 30 inserted into BST.
// 70 inserted into BST.
// 20 inserted into BST.
// 40 inserted into BST.
// 60 inserted into BST.
// 80 inserted into BST.
//
// Inorder (sorted): 20 30 40 50 60 70 80
//
// Min value   : 20
// Max value   : 80
// Height      : 3
//
// Search 40   : Found
// Search 90   : Not Found
//
// 20 deleted from BST.
// 30 deleted from BST.
// 50 deleted from BST.
//
// Inorder (sorted): 40 60 70 80
// ============================================