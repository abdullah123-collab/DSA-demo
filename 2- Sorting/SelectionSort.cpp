/*
* Topic: Selection Sort Algorithm
* Time Complexity: O(n^2) - Average and Worst Case
* Space Complexity: O(1)
* Explanation: 
* This algorithm repeatedly finds the minimum element (considering ascending order) 
* from the unsorted part and puts it at the beginning. 
* It maintains two subarrays: one sorted and one unsorted.
*/

#include<iostream>
using namespace std;

// Function to perform Selection Sort
void selectionSort(int arr[], int n){
    // Move the boundary of the unsorted subarray one by one
	for(int i=0; i<n-1; i++){
		
		int minIndex = i; // Assume the first element of the unsorted part is the minimum
		
		// Find the minimum element in the remaining unsorted array
		for(int j=i+1; j<n; j++){
			if(arr[j] < arr[minIndex]){
				minIndex = j; // Update minIndex if a smaller element is found
			}
		}
		
		// Swap the found minimum element with the first element of the unsorted part
		int temp = arr[minIndex];
		arr[minIndex] = arr[i];
		arr[i] = temp;
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
	cout << "Enter number of elements to enter: ";
	cin >> n;
	
	// Note: 'int arr[n]' is a Variable Length Array (VLA). 
    // It works in some compilers (like GCC) but may error in standard Visual Studio.
	int arr[n];
	
	cout << "========================================" << endl;
	
	for(int i=0; i<n; i++){
		cout << "Element at Index [" << i << "] : ";
		cin >> arr[i];
	}
	cout << endl;
	
	cout << "========================================" << endl;
	
	cout << "Unsorted Array: " << endl;
	display(arr, n);
	
	// Call Selection Sort
	selectionSort(arr, n);
	
	cout << "After sorting (through selection sort) array! : " << endl;
	display(arr, n);
	
	return 0;
}