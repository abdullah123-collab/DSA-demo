/*
* Topic: Bubble Sort Algorithm
* Time Complexity: O(n^2) - Average and Worst Case
* Space Complexity: O(1)
* Explanation: 
* This algorithm repeatedly steps through the list, compares adjacent elements, 
* and swaps them if they are in the wrong order. 
* The pass through the list is repeated until the list is sorted.
*/

#include<iostream>
using namespace std;

// Function to perform Bubble Sort
void bubbleSort(int arr[], int n){
    // Outer loop: This handles the number of passes.
    // We run this n-1 times because after n-1 passes, the last element is naturally sorted.
	for(int i=0; i<n-1; i++){
        
        // Inner loop: This compares adjacent elements.
        // We go up to 'n-i-1' because the last 'i' elements are already sorted and in place.
		for(int j=0; j<n-i-1; j++){
			
            // Compare the current element with the next one
			if(arr[j] > arr[j+1]){
                // If they are in the wrong order, swap them
				int temp = arr[j];      // Store current value in a temporary variable
				arr[j] = arr[j+1];      // Move the next value to current position
				arr[j+1] = temp;        // Move the stored value to the next position
			}
		}
	}
}

// Helper function to print the array
void display(int arr[], int n){
	for(int i=0; i<n; i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

int main(){
	int n;
	
	cout<<"Enter number of elements to enter: ";
	cin>>n;
	
	// Creating the array with size 'n' based on user input
	int arr[n]; 
	
	cout << "Enter Elements: " << endl;
	
    for(int i=0; i<n; i++){
		cout<<"Index [" << i << "] : ";
		cin>>arr[i];
	}
	cout<<endl;
	
	cout<<"Unsorted Array: ";
	display(arr, n);
	
	// Calling the sort function
	bubbleSort(arr, n);
	
	cout<<"Array after sorting: ";
	display(arr, n);
	
	return 0;
}