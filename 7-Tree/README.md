# 🌳 Tree Data Structures — DSA Demo (Module 7)

A collection of C++ implementations covering core **Tree** data structures and traversal algorithms, organized as part of a Data Structures & Algorithms (DSA) demo series.

---

## 📁 Project Structure

```
7-Tree/
├── 1-BinaryTree.cpp
├── 2-BinarySearchTree.cpp
├── 3-TreeTraversals.cpp
└── 4-LevelOrderTraversal.cpp
```

---

## 📄 File Descriptions

### 1. `1-BinaryTree.cpp`
Implements a basic **Binary Tree** from scratch.

- **Node structure:** Each node holds a value, a left child pointer, and a right child pointer.
- **Core operations:**
  - Insertion of nodes
  - Deletion of nodes
  - Searching for a value
- **Key concepts:** Dynamic memory allocation, pointer-based tree construction, recursive operations.

---

### 2. `2-BinarySearchTree.cpp`
Implements a **Binary Search Tree (BST)** — a binary tree with the ordering property.

- **BST property:** For every node, all values in the left subtree are smaller and all values in the right subtree are larger.
- **Core operations:**
  - Insertion (maintaining BST order)
  - Deletion (handling leaf, one-child, and two-child cases)
  - Search (O(log n) average case)
  - Finding minimum and maximum values
- **Key concepts:** Inorder successor/predecessor, balanced vs. unbalanced trees.

---

### 3. `3-TreeTraversals.cpp`
Demonstrates the three classic **Depth-First Search (DFS)** traversal methods on a binary tree.

| Traversal | Order | Use Case |
|-----------|-------|----------|
| **Inorder** | Left → Root → Right | Produces sorted output for BSTs |
| **Preorder** | Root → Left → Right | Used for tree copying / serialization |
| **Postorder** | Left → Right → Root | Used for tree deletion / expression evaluation |

- Both **recursive** and **iterative** (stack-based) implementations may be included.

---

### 4. `4-LevelOrderTraversal.cpp`
Implements **Level Order Traversal** (Breadth-First Search) on a binary tree.

- **Approach:** Uses a **queue** to process nodes level by level, from top to bottom, left to right.
- **Applications:**
  - Finding the shortest path in an unweighted tree
  - Printing the tree level-by-level
  - Calculating tree height/width
- **Key concepts:** Queue-based BFS, iterative traversal.


## 🧠 Concepts Covered

| Concept | File |
|---------|------|
| Binary Tree fundamentals | `1-BinaryTree.cpp` |
| BST insert / delete / search | `2-BinarySearchTree.cpp` |
| Inorder, Preorder, Postorder | `3-TreeTraversals.cpp` |
| BFS / Level Order (Queue) | `4-LevelOrderTraversal.cpp` |

---

## 📊 Time Complexity Reference

| Operation | Average Case | Worst Case (Unbalanced) |
|-----------|-------------|------------------------|
| BST Insert | O(log n) | O(n) |
| BST Search | O(log n) | O(n) |
| BST Delete | O(log n) | O(n) |
| DFS Traversal | O(n) | O(n) |
| BFS / Level Order | O(n) | O(n) |

---

## 📚 Learning Path

If you're following along with the DSA series, the recommended order is:

1. Start with `1-BinaryTree.cpp` to understand tree node structure.
2. Move to `2-BinarySearchTree.cpp` to learn ordered insertion and search.
3. Study `3-TreeTraversals.cpp` to master DFS techniques.
4. Finally, explore `4-LevelOrderTraversal.cpp` for BFS on trees.

---
