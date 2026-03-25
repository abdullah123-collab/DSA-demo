# Searching Algorithms

This module contains C++ implementations of fundamental searching algorithms used to find elements within data structures.

## 📂 Files Included

### 1. LinearSearch.cpp
* **Algorithm:** Linear Search
* **Time Complexity:** O(n)
* **Description:** Iterates through the array one by one. It is simple and works on both sorted and unsorted arrays, but is slower for large datasets.

### 2. BinarySearch.cpp
* **Algorithm:** Binary Search
* **Time Complexity:** O(log n)
* **Description:** A highly efficient algorithm that repeatedly divides the search interval in half.
* **Constraint:** The input array **must be sorted** for this to work.

### 3. BinarySearch_Sorted.cpp
* **Algorithm:** Bubble Sort + Binary Search integration
* **Description:** Solves the problem of unsorted data. This program automatically runs a Bubble Sort first to organize the data, and then applies Binary Search to find the target element.