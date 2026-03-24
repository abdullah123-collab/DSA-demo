#include <iostream>
#include <algorithm>

using namespace std;

struct Node {
    int data;
    Node *left, *right;
    int height;

    Node(int val) {
        data = val;
        left = right = NULL;
        height = 1;
    }
};

class AVLTree {
public:
    int getHeight(Node* n) {
        return (n == NULL) ? 0 : n->height;
    }

    int getBalanceFactor(Node* n) {
        return (n == NULL) ? 0 : getHeight(n->left) - getHeight(n->right);
    }

    // Right Rotate (for LL Case)
    Node* rightRotate(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

        return x;
    }

    // Left Rotate (for RR Case)
    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

        return y;
    }

    Node* insert(Node* node, int data) {
        if (node == NULL) return new Node(data);

        if (data < node->data)
            node->left = insert(node->left, data);
        else if (data > node->data)
            node->right = insert(node->right, data);
        else
            return node; // No duplicates

        // Update height
        node->height = 1 + max(getHeight(node->left), getHeight(node->right));

        // Get balance and check if it became unbalanced
        int bf = getBalanceFactor(node);

        // LL Case
        if (bf > 1 && data < node->left->data)
            return rightRotate(node);

        // RR Case
        if (bf < -1 && data > node->right->data)
            return leftRotate(node);

        // LR Case
        if (bf > 1 && data > node->left->data) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // RL Case
        if (bf < -1 && data < node->right->data) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    void inorder(Node* root) {
        if (root) {
            inorder(root->left);
            cout << root->data << " ";
            inorder(root->right);
        }
    }
};

int main() {
    AVLTree tree;
    Node* root = NULL;

    // Inserting elements that would make a normal BST skewed
    root = tree.insert(root, 10);
    root = tree.insert(root, 20);
    root = tree.insert(root, 30);
    root = tree.insert(root, 40);
    root = tree.insert(root, 50);

    cout << "Inorder traversal of AVL tree: ";
    tree.inorder(root);
    cout << endl;

    return 0;
}