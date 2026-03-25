// ============================================
//  FACTORIAL - Multiple Approaches in C++
//  Topics: Recursion, Iteration, Tail Recursion
// ============================================

#include <iostream>
using namespace std;

// ----------------------------------------
// 1. Recursive Factorial
// Time: O(n) | Space: O(n) - call stack
// ----------------------------------------
long long factorialRecursive(int n) {
    // Base case
    if (n == 0 || n == 1)
        return 1;
    // Recursive case
    return n * factorialRecursive(n - 1);
}

// ----------------------------------------
// 2. Iterative Factorial
// Time: O(n) | Space: O(1)
// ----------------------------------------
long long factorialIterative(int n) {
    long long result = 1;
    for (int i = 2; i <= n; i++)
        result *= i;
    return result;
}

// ----------------------------------------
// 3. Tail Recursive Factorial
// Time: O(n) | Space: O(n) but optimizable
// ----------------------------------------
long long factorialTail(int n, long long accumulator = 1) {
    if (n == 0 || n == 1)
        return accumulator;
    return factorialTail(n - 1, n * accumulator);
}

// ----------------------------------------
// Main
// ----------------------------------------
int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    if (n < 0) {
        cout << "Factorial not defined for negative numbers." << endl;
        return 1;
    }

    cout << "\n--- Factorial of " << n << " ---" << endl;
    cout << "Recursive  : " << factorialRecursive(n) << endl;
    cout << "Iterative  : " << factorialIterative(n) << endl;
    cout << "Tail Recur : " << factorialTail(n) << endl;

    // Show step-by-step for small n
    if (n <= 10) {
        cout << "\nStep-by-step: ";
        for (int i = n; i >= 1; i--) {
            cout << i;
            if (i != 1) cout << " x ";
        }
        cout << " = " << factorialRecursive(n) << endl;
    }

    return 0;
}

/*
============================
 SAMPLE OUTPUT
============================
Enter a number: 5

--- Factorial of 5 ---
Recursive  : 120
Iterative  : 120
Tail Recur : 120

Step-by-step: 5 x 4 x 3 x 2 x 1 = 120

============================
 COMPLEXITY ANALYSIS
============================
| Approach       | Time | Space |
|----------------|------|-------|
| Recursive      | O(n) | O(n)  |
| Iterative      | O(n) | O(1)  |
| Tail Recursive | O(n) | O(n)* |
* Can be O(1) with compiler tail-call optimization
*/