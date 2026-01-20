/*
* Topic: Binary Search Algorithm
* Time Complexity: O(log n) - Extremely efficient.
* Space Complexity: O(1) - Iterative approach uses constant space.
* * Explanation:
* Binary Search works by repeatedly dividing the search interval in half.
* IMPORTANT: The array MUST be sorted for this to work.
* If the value of the search key is less than the item in the middle of the interval, 
* narrow the interval to the lower half. Otherwise, narrow it to the upper half.
*/

#include<iostream>
using namespace std;

// Function to perform Binary Search
// Returns the index of 'key' if found, otherwise returns -1
int binarySearch(int arr[], int start, int end, int key){
    
    // Continue loop while the search interval is valid
    while(start <= end){
        
        // Find the middle index
        int mid = (start + end) / 2;
        
        // Case 1: Check if the middle element is the key we are looking for
        if(arr[mid] == key){
            return mid; // Return the index
        }
        
        // Case 2: If the middle element is smaller than the key,
        // it means the key must be in the RIGHT half (greater values).
        else if(arr[mid] < key){
            start = mid + 1; // Move start pointer to the right of mid
        }
        
        // Case 3: If the middle element is greater than the key,
        // it means the key must be in the LEFT half (smaller values).
        else{
            end = mid - 1; // Move end pointer to the left of mid
        }
    }
    
    // If we reach here, the element was not present
    return -1;
}

int main(){
    int n, key;
    
    cout << "Enter number of elements to enter: ";
    cin >> n;
    
    // Creating array of size n
    // Note: If using Visual Studio, use 'int* arr = new int[n];' instead to avoid errors.
    int arr[n];
    
    cout << "Enter number in sorted form!" << endl;
    cout << "Enter Elements: " << endl;
    
    for(int i = 0; i < n; i++){
        cout << "Index [" << i << "] : ";
        cin >> arr[i];
    }
    
    cout << "Enter Value to Search: ";
    cin >> key;
    
    // Call the binary search function
    // We pass 0 as start index and n-1 as end index
    int result = binarySearch(arr, 0, n - 1, key);
    
    // Display the result
    if(result != -1){
        cout << "Number found! at index: " << result;
    } else {
        cout << "Number not found!";
    }

    return 0;
}