/*
* Topic: Insertion Sort Algorithm
* Time Complexity: O(n^2) - Average and Worst Case
* Space Complexity: O(1)
* Explanation: 
* This algorithm builds the sorted array one item at a time.
* It picks an element (key) and places it in its correct position 
* within the already sorted part of the array to its left.
*/

#include<iostream>
using namespace std;

// Function to perform Insertion Sort
void insertionSort(int arr[], int n){
    // Start from the second element (index 1) since index 0 is considered sorted
	for(int i=1; i<n; i++){
		int key = arr[i]; // The element to be inserted
		int j = i - 1;
		
		// Move elements of arr[0..i-1] that are greater than key
		// to one position ahead of their current position
		while(j >= 0 && arr[j] > key){
			arr[j+1] = arr[j]; // Shift element to the right
			j--; // Move to the previous index
		}  
		
		// Place the key at its correct position
		arr[j+1] = key;
	}
}

// Helper function to print the array
void display(int arr[], int n){
	for(int i=0; i<n; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main(){
	int n;
	
	cout << "Enter number of elements: ";
	cin >> n;
	
	// Note: See VLA warning above if using Visual Studio
	int arr[n];
	
	cout << "Enter Elements: " << endl;
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}
	
	cout << "Unsorted Array: " << endl;
	display(arr, n);
	
	// Call Insertion Sort
	insertionSort(arr, n);
	
	cout << "Sorted Array: " << endl;
	display(arr, n);

    return 0;   
}