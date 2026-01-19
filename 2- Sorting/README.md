# Sorting Algorithms

## What I Learned This Week
This week, I focused on mastering fundamental **Sorting Algorithms** in C++. I learned how to implement different sorting techniques from scratch and analyzed their time complexities to understand the trade-offs between O(n^2) and O(n\logn) approaches.

## What is Sorting❓
Sorting is the process of arranging data in a specific order (like ascending or descending). It is a crucial operation that makes data easier to search, analyze, and manage efficiently.

## 📄 Algorithms Implemented

| File | Explanation |
| :--- | :--- |
| **`BubbleSort.cpp`** | A simple algorithm that repeatedly steps through the list, compares adjacent elements, and swaps them if they are in the wrong order. |
| **`InsertionSort.cpp`** | Builds the sorted array one item at a time by taking an element and inserting it into its correct position within the already sorted part. |
| **`SelectionSort.cpp`** | Sorts an array by repeatedly finding the minimum element from the unsorted portion and putting it at the beginning. |
| **`MergeSort.cpp`** | A highly efficient divide-and-conquer algorithm that divides the array into halves, sorts them, and then merges them back together. |
| **`QuickSort.cpp`** | A divide-and-conquer algorithm that picks a "pivot" element and partitions the array so that smaller elements are on the left and larger ones are on the right. |

## 📊 Complexity Analysis

| Algorithm | Best Case | Average Case | Worst Case | Space Complexity |
| :--- | :---: | :---: | :---: | :---: |
| **Bubble Sort** | O(n) | O(n^2) | $O(n^2)$ | O(1) |
| **Insertion Sort** | O(n) | O(n^2) | O(n^2)$ | O(1) |
| **Selection Sort** | O(n^2) | O(n^2) | O(n^2)$ | O(1) |
| **Merge Sort** | O(n\logn) | O(n\logn) | O(n\logn) | O(n) |
| **Quick Sort** | O(n\logn) | O(n\logn) | O(n^2) | O(\logn) |
