/*
* Topic: Array Traversal (Input and Output)
* Description: This program demonstrates how to take input from the user 
* and store it in an array, then display (traverse) the data.
*/

#include<iostream>
using namespace std;

int main(){
    int n;
    
    // 1. Ask for the size of the array
    cout<<"Enter the size of the array: ";
    cin>>n;
    
    // 2. Create the array (Using dynamic memory for safety in VS)
    int* arr = new int[n];
    
    // 3. Get data from the user
    cout<<"Enter " << n << " elements:" << endl;
    for(int i = 0; i < n; i++){
        cout<<"Element at index [" << i << "]: ";
        cin>>arr[i];
    }
    
    // 4. Display the data back to the user
    cout<<"\nYou entered the following data: " << endl;
    for(int i = 0; i < n; i++){
        cout<<arr[i]<< " ";
    }
    cout<<endl;
    
    return 0;
}