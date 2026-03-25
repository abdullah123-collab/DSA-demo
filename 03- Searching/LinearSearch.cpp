/*
* Topic: Linear Search Algorithm
* Language: C++
* Time Complexity: O(n) - In the worst case, we check every element.
* Space Complexity: O(1) - No extra space is used.
* * Explanation: 
* The Linear Search algorithm iterates through the array starting from the first element.
* It compares each element with the 'key' (the number we are looking for).
* If a match is found, it returns the position. If the loop finishes without a match, it returns -1.
*/

#include <iostream>
using namespace std;

// Function to perform Linear Search
int learnSearch(int* arr, int nsize, int x) {
    // Loop through the array from index 0 to nsize-1
    for (int i = 0; i < nsize; i++) {
        // If the current element equals the key 'x'
        if (arr[i] == x) {
            return i + 1; // Return the position (Index + 1 for user friendliness)
        }
    }
    return -1; // Return -1 if the element is not found
}

int main() {
    int n, key;

    cout << "Enter number of elements to enter: ";
    cin >> n;

    // Dynamically allocate memory for the array (Required for Visual Studio)
    int* arr = new int[n];

    cout << "Enter elements: " << endl;
    for (int i = 0; i < n; i++) {
        cout << "Element at Index [" << i << "] : ";
        cin >> arr[i];
    }

    cout << "Enter number to find: ";
    cin >> key;

    // Call the search function
    int result = learnSearch(arr, n, key);

    if (result != -1) {
        cout << "Number found at Position: " << result << endl;
    }
    else {
        cout << "Number not found" << endl;
    }

    // Free the memory we allocated
    delete[] arr;

    return 0;
}