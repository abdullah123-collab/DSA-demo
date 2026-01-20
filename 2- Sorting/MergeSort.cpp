/*
 * File: MergeSort.cpp
 * Method: Divide and Conquer
 * Time Complexity: O(n log n) (Best, Average, and Worst case)
 * Space Complexity: O(n)
 */

#include <iostream>
using namespace std;

// Function to merge two halves
void merge(int arr[], int left, int mid, int right) {
    // calculate sizes of two subarrays
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    // create temporary arrays
    int leftArr[n1];
    int rightArr[n2];
    
    // copy data to temp arrays
    for(int i = 0; i < n1; i++) {
        leftArr[i] = arr[left + i];
    }
    
    for(int j = 0; j < n2; j++) {
        rightArr[j] = arr[mid + 1 + j];
    }
    
    // merge the temp arrays back
    int i = 0;  // index for left subarray
    int j = 0;  // index for right subarray
    int k = left;  // index for merged array
    
    // compare elements and merge
    while(i < n1 && j < n2) {
        if(leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }
    
    // copy remaining elements of left array
    while(i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }
    
    // copy remaining elements of right array
    while(j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

// DIVIDE - Split array into halves recursively
void mergeSort(int arr[], int left, int right) {
    if(left < right) {
        // DIVIDE: find middle point
        int mid = left + (right - left) / 2;
        
        // DIVIDE: recursively sort first half
        mergeSort(arr, left, mid);
        
        // DIVIDE: recursively sort second half
        mergeSort(arr, mid + 1, right);
        
        // CONQUER: merge the sorted halves
        merge(arr, left, mid, right);
    }
}

// Utility function to print array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    cout << "Original array: ";
    printArray(arr, n);
    
    cout << "\nApplying Merge Sort (Divide and Conquer)...\n\n";
    
    mergeSort(arr, 0, n - 1);
    
    cout << "Sorted array: ";
    printArray(arr, n);
    
    return 0;
}