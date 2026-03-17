# 10. Heaps (Priority Queues)

A **Heap** is a complete binary tree-based data structure that satisfies the **Heap Property**. This repository contains manual C++ implementations of both Min-Heaps and Max-Heaps without using the STL `<vector>` library, focusing on manual memory management.

---

## 🚀 Overview

### 1. Min-Heap
In a **Min-Heap**, the value of the root node must be the minimum among all nodes present in the heap. This property must be recursively true for all subtrees.
* **Top element:** Always the smallest.
* **Use case:** Finding the shortest path (Dijkstra's), task scheduling with lowest latency.

### 2. Max-Heap
In a **Max-Heap**, the value of the root node must be the maximum among all nodes. 
* **Top element:** Always the largest.
* **Use case:** Priority scheduling where the highest value gets processed first.

---

## 📊 Complexity Analysis

Regardless of the heap type, the time complexities remain the same:

| Operation | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Insert (Push)** | $O(\log n)$ | $O(1)$ |
| **Extract Top (Pop)** | $O(\log n)$ | $O(1)$ |
| **Peek (Top)** | $O(1)$ | $O(1)$ |
| **Heapify (Build)** | $O(n)$ | $O(1)$ |

---

## 🛠️ Implementation Logic

Since a heap is a **Complete Binary Tree**, it can be efficiently represented as an **Array**. For any element at index `i`:

* **Parent:** `(i - 1) / 2`
* **Left Child:** `2i + 1`
* **Right Child:** `2i + 2`



### Key Methods
* **`heapifyUp`**: Used during `push`. It moves an element up the tree until the heap property is restored.
* **`heapifyDown`**: Used during `pop`. After replacing the root with the last element, this moves the new root down to its correct position.
* **`resize()`**: Manually handles memory by doubling the array capacity when the heap is full.

---

## 📂 Files in this Folder
* `MinHeap.cpp`: Manual implementation of a Min-Priority Queue.
* `MaxHeap.cpp`: Manual implementation of a Max-Priority Queue.

> **Note:** These implementations use raw pointers (`int* arr`) and manual `new`/`delete[]` to demonstrate low-level memory management and the resizing logic typically hidden by `std::vector`.