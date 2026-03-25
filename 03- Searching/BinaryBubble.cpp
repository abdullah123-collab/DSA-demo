/*
* USE THIS WHEN: The input array is UNSORTED and you need to find a value.
* It automatically runs Bubble Sort first, because Binary Search requires sorted data.
*/

#include<iostream>
using namespace std;

// Function to perform Binary Search (Returns index or -1)
int binarySearch(int arr[], int start, int end, int key){
    while(start <= end){
        int mid = (start + end) / 2;
        
        if(arr[mid] == key) return mid;
        else if(arr[mid] < key) start = mid + 1;
        else end = mid - 1;
    }
    return -1;
}

// Function to perform Bubble Sort (Sorts array ascending)
void bubbleSort(int arr[], int n){
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void display(int arr[], int n){
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

int main(){
    int n, key;
    cout << "Enter number of elements: ";
    cin >> n;
    
    // Use dynamic array for VS compatibility
    int* arr = new int[n];
    
    cout << "Enter Elements (Unsorted is fine): " << endl;
    for(int i = 0; i < n; i++) cin >> arr[i];
    
    cout << "Unsorted: ";
    display(arr, n);

    // 1. Sort the array
    bubbleSort(arr, n);
    
    cout << "Sorted: ";
    display(arr, n);
        
    // 2. Search the array
    cout << "Enter value to search: ";
    cin >> key;
    
    int result = binarySearch(arr, 0, n - 1, key);
    
    if(result != -1) cout << "Found at index: " << result << endl;
    else cout << "Not found!" << endl;
    
    delete[] arr; // Clean up memory
    return 0;
}