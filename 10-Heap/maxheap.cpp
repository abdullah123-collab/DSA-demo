#include <iostream>
#include <algorithm>


class MaxHeap {
private:
    int* arr;
    int capacity;
    int size;

    // Moves the element at index up to its correct position
    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            // Max-Heap condition: Parent must be >= Child
            if (arr[index] > arr[parent]) {
                swap(arr[index], arr[parent]);
                index = parent;
            } else {
                break;
            }
        }
    }

    // Moves the element at index down to its correct position
    void heapifyDown(int index) {
        int largest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        // Check if left child is larger than current largest
        if (left < size && arr[left] > arr[largest]) {
            largest = left;
        }
        // Check if right child is larger than current largest
        if (right < size && arr[right] > arr[largest]) {
            largest = right;
        }

        if (largest != index) {
            swap(arr[index], arr[largest]);
            heapifyDown(largest);
        }
    }

    void resize() {
        capacity *= 2;
        int* newArr = new int[capacity];
        for (int i = 0; i < size; i++) {
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
    }

public:
    MaxHeap(int initCap = 10) {
        capacity = initCap;
        size = 0;
        arr = new int[capacity];
    }

    ~MaxHeap() {
        delete[] arr;
    }

    void push(int val) {
        if (size == capacity) resize();
        arr[size] = val;
        heapifyUp(size);
        size++;
    }

    void pop() {
        if (size == 0) {
            std::cout << "Heap is empty!" << std::endl;
            return;
        }
        // Replace root with the last element
        arr[0] = arr[size - 1];
        size--;
        // Restore heap property from the top down
        heapifyDown(0);
    }

    int top() {
        if (size == 0) return -1;
        return arr[0];
    }

    int getSize() { return size; }
    bool isEmpty() { return size == 0; }
};

int main() {
    MaxHeap mx;

    mx.push(10);
    mx.push(40);
    mx.push(15);
    mx.push(50);
    mx.push(5);

    std::cout << "Max-Heap Top (Should be 50): " << mx.top() << std::endl;

    mx.pop();
    std::cout << "New Top after pop (Should be 40): " << mx.top() << std::endl;

    return 0;
}