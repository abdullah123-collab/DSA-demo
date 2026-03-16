// ============================================
//  FIBONACCI - Multiple Approaches in C++
//  Topics: Recursion, Memoization, DP, Space Optimized
// ============================================

#include <iostream>
#include <vector>
#include <map>
using namespace std;

// ----------------------------------------
// 1. Naive Recursion
// Time: O(2^n) | Space: O(n) - call stack
// ----------------------------------------
long long fibRecursive(int n) {
    // Base cases
    if (n == 0) return 0;
    if (n == 1) return 1;
    // Recursive case
    return fibRecursive(n - 1) + fibRecursive(n - 2);
}

// ----------------------------------------
// 2. Memoization (Top-Down DP)
// Time: O(n) | Space: O(n)
// ----------------------------------------
map<int, long long> memo;

long long fibMemo(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    // Check if already computed
    if (memo.count(n))
        return memo[n];

    // Store and return
    memo[n] = fibMemo(n - 1) + fibMemo(n - 2);
    return memo[n];
}

// ----------------------------------------
// 3. Bottom-Up DP (Tabulation)
// Time: O(n) | Space: O(n)
// ----------------------------------------
long long fibDP(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    vector<long long> dp(n + 1);
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
        dp[i] = dp[i - 1] + dp[i - 2];

    return dp[n];
}

// ----------------------------------------
// 4. Space Optimized DP
// Time: O(n) | Space: O(1)
// ----------------------------------------
long long fibOptimized(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    long long prev2 = 0, prev1 = 1, curr = 0;

    for (int i = 2; i <= n; i++) {
        curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }

    return curr;
}

// ----------------------------------------
// 5. Print Fibonacci Series
// ----------------------------------------
void printFibSeries(int n) {
    cout << "Fibonacci Series (0 to " << n << "): ";
    long long prev2 = 0, prev1 = 1;

    if (n >= 0) cout << prev2;
    if (n >= 1) cout << " " << prev1;

    for (int i = 2; i <= n; i++) {
        long long curr = prev1 + prev2;
        cout << " " << curr;
        prev2 = prev1;
        prev1 = curr;
    }
    cout << endl;
}

// ----------------------------------------
// Main
// ----------------------------------------
int main() {
    int n;
    cout << "Enter position n (0-indexed): ";
    cin >> n;

    if (n < 0) {
        cout << "Please enter a non-negative number." << endl;
        return 1;
    }

    cout << "\n--- Fibonacci of " << n << " ---" << endl;
    cout << "Naive Recursive   : " << fibRecursive(n) << endl;
    cout << "Memoization       : " << fibMemo(n) << endl;
    cout << "Bottom-Up DP      : " << fibDP(n) << endl;
    cout << "Space Optimized   : " << fibOptimized(n) << endl;

    cout << endl;
    printFibSeries(n);

    return 0;
}

/*
============================
 SAMPLE OUTPUT
============================
Enter position n (0-indexed): 10

--- Fibonacci of 10 ---
Naive Recursive   : 55
Memoization       : 55
Bottom-Up DP      : 55
Space Optimized   : 55

Fibonacci Series (0 to 10): 0 1 1 2 3 5 8 13 21 34 55

============================
 COMPLEXITY ANALYSIS
============================
| Approach         | Time   | Space |
|------------------|--------|-------|
| Naive Recursive  | O(2^n) | O(n)  |
| Memoization      | O(n)   | O(n)  |
| Bottom-Up DP     | O(n)   | O(n)  |
| Space Optimized  | O(n)   | O(1)  |

============================
 FIBONACCI SEQUENCE
============================
Index:  0  1  2  3  4  5  6   7   8   9  10
Value:  0  1  1  2  3  5  8  13  21  34  55
*/