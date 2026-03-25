# 🔗 Linked Lists in C++

A clean, well-commented collection of all three fundamental linked list variants implemented from scratch in C++. No STL containers — just raw pointers and manual memory management, ideal for learning data structures from the ground up.

---

## 📁 Repository Structure

```
LinkedLists/
├── 1-SinglyLinkedList.cpp    # One-directional chain (next pointer only)
├── 2-DoublyLinkedList.cpp    # Bi-directional chain (next + prev pointers)
├── 3-CircularLinkedList.cpp  # Singly linked but tail wraps back to head
└── readme.md
```

---

## 📖 Overview of Each Variant

### 1. Singly Linked List
Each node stores data and a **single pointer** to the next node. The last node points to `NULL`.

```
head → [10] → [20] → [30] → NULL
```

| Operation    | Time Complexity |
|--------------|-----------------|
| push_front   | O(1)            |
| push_back    | O(1) *          |
| pop_front    | O(1)            |
| pop_back     | O(n)            |
| insert(pos)  | O(n)            |
| search       | O(n)            |

> \* O(1) because a `tail` pointer is maintained.

---

### 2. Doubly Linked List
Each node stores data and **two pointers** — one to the next node and one to the previous node.

```
NULL ← [10] ↔ [20] ↔ [30] → NULL
```

| Operation    | Time Complexity |
|--------------|-----------------|
| push_front   | O(1)            |
| push_back    | O(1)            |
| pop_front    | O(1)            |
| pop_back     | O(1) ✓          |
| insert(pos)  | O(n)            |
| search       | O(n)            |

> Key advantage: `pop_back` is O(1) because `tail->prev` directly gives the second-last node.  
> Supports **backward traversal** as well.

---

### 3. Circular Linked List
Like a singly linked list, but the **tail's next pointer wraps back to the head** instead of NULL.

```
head → [10] → [20] → [30] ─┐
  └─────────────────────────┘
```

| Operation    | Time Complexity |
|--------------|-----------------|
| push_front   | O(1)            |
| push_back    | O(1)            |
| pop_front    | O(1)            |
| pop_back     | O(n)            |
| insert(pos)  | O(n)            |
| search       | O(n)            |

> Key advantage: every node is reachable from every other node — no dead end.  
> Ideal for **round-robin scheduling**, **circular buffers**, and **game turn management**.

---

## ⚙️ Operations Implemented

All three variants implement the following interface:

| Method            | Description                                      |
|-------------------|--------------------------------------------------|
| `push_front(val)` | Insert a node at the beginning                   |
| `push_back(val)`  | Insert a node at the end                         |
| `pop_front()`     | Remove the node at the beginning                 |
| `pop_back()`      | Remove the node at the end                       |
| `insert(val,pos)` | Insert a node at a given 0-based position        |
| `search(key)`     | Return the index of the first match, or -1       |
| `print*()`        | Display the full list in a readable format       |

---



## 🧠 Comparison at a Glance

| Feature                  | Singly | Doubly | Circular |
|--------------------------|:------:|:------:|:--------:|
| Extra pointer per node   | 0      | 1      | 0        |
| Bidirectional traversal  | ✗      | ✓      | ✗        |
| O(1) pop_back            | ✗      | ✓      | ✗        |
| No NULL terminator       | ✗      | ✗      | ✓        |
| Memory per node          | Low    | Medium | Low      |

---

## 💡 When to Use Which?

- **Singly** — Simple stack/queue use-cases, low memory environments.
- **Doubly** — When you need fast deletion from both ends or backward traversal (e.g., browser history, LRU cache).
- **Circular** — Round-robin algorithms, continuous cycling over elements (e.g., game turns, CPU scheduling).

---

## 👤 Author

Feel free to fork, star ⭐, and open issues or PRs for improvements!