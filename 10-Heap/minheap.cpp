#include <iostream>
#include <algorithm>

class MinHeap {
private:
    int* arr;
    int capacity;
    int size;

    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (arr[index] < arr[parent]) {
                std::swap(arr[index], arr[parent]);
                index = parent;
            } else break;
        }
    }

    void heapifyDown(int index) {
        int smallest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < size && arr[left] < arr[smallest]) smallest = left;
        if (right < size && arr[right] < arr[smallest]) smallest = right;

        if (smallest != index) {
            std::swap(arr[index], arr[smallest]);
            heapifyDown(smallest);
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
    MinHeap(int initCap = 10) {
        capacity = initCap;
        size = 0;
        arr = new int[capacity];
    }

    ~MinHeap() {
        delete[] arr;
    }

    void push(int val) {
        if (size == capacity) resize();
        arr[size] = val;
        heapifyUp(size);
        size++;
    }

    void pop() {
        if (size == 0) return;
        arr[0] = arr[size - 1];
        size--;
        heapifyDown(0);
    }

    int top() { return (size > 0) ? arr[0] : -1; }
    bool isEmpty() { return size == 0; }
};

int main() {
    MinHeap mh;
    mh.push(20);
    mh.push(10);
    mh.push(30);
    mh.push(5);

    std::cout << "Min-Heap Top: " << mh.top() << std::endl; // Output: 5
    mh.pop();
    std::cout << "New Top after pop: " << mh.top() << std::endl; // Output: 10
    
    return 0;
}