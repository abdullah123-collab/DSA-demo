/*
* Topic: Addition of Two Arrays
* Description: This program takes two arrays of the same size
* and adds them element-by-element into a third array.
* Example: A=[1,2] + B=[3,4] -> Sum=[4,6]
*/

#include<iostream>
using namespace std;

int main(){
    int n;
    
    cout << "Enter size of the arrays: ";
    cin >> n;
    
    // Create 3 arrays: A (first), B (second), Sum (result)
    int* A = new int[n];
    int* B = new int[n];
    int* Sum = new int[n];
    
    // Input for First Array
    cout << "\n--- Enter elements for First Array ---" << endl;
    for(int i = 0; i < n; i++){
        cout << "A[" << i << "]: ";
        cin >> A[i];
    }

    // Input for Second Array
    cout << "\n--- Enter elements for Second Array ---" << endl;
    for(int i = 0; i < n; i++){
        cout << "B[" << i << "]: ";
        cin >> B[i];
    }
    
    // Perform Addition
    for(int i = 0; i < n; i++){
        Sum[i] = A[i] + B[i];
    }
    
    // Display Result
    cout << "\n--- Sum of Arrays (A + B) ---" << endl;
    for(int i = 0; i < n; i++){
        cout << Sum[i] << " ";
    }
    cout << endl;
    
    return 0;
}