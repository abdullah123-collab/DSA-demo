# 12. AVL Tree (Self-Balancing BST)

A **Binary Search Tree (BST)** can become inefficient ($O(n)$) if data is inserted in sorted order. An **AVL Tree** solves this by ensuring the height difference between left and right subtrees (Balance Factor) is at most **1**.

## ⚖️ Balance Factor
For every node $N$:
$$BalanceFactor(N) = Height(LeftSubtree) - Height(RightSubtree)$$
- If $BF > 1$ or $BF < -1$, the tree is unbalanced and requires a **Rotation**.

## 🔄 Rotation Types
1. **LL (Left-Left):** Single Right Rotation.
2. **RR (Right-Right):** Single Left Rotation.
3. **LR (Left-Right):** Left Rotation then Right Rotation.
4. **RL (Right-Left):** Right Rotation then Left Rotation.

## 📊 Complexity
| Operation | BST (Worst) | AVL (Worst) |
| :--- | :--- | :--- |
| **Search** | $O(n)$ | $O(\log n)$ |
| **Insert** | $O(n)$ | $O(\log n)$ |
| **Delete** | $O(n)$ | $O(\log n)$ |