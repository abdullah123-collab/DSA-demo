# 📂 Recursion — Factorial & Fibonacci

> Beginner-friendly C++ implementations covering recursive, iterative, and dynamic programming approaches.

---

## 📁 Files

| File | Topic | Approaches |
|------|-------|------------|
| `factorial.cpp` | Factorial of n | Recursive, Iterative, Tail Recursive |
| `fibonacci.cpp` | Fibonacci of n | Naive Recursive, Memoization, Bottom-Up DP, Space Optimized |

---

## 🔢 Factorial (`factorial.cpp`)

### What is Factorial?
The factorial of a non-negative integer `n` is the product of all positive integers less than or equal to `n`.

```
n! = n × (n-1) × (n-2) × ... × 1
5! = 5 × 4 × 3 × 2 × 1 = 120
```

### Approaches

#### 1. Recursive
```cpp
long long factorialRecursive(int n) {
    if (n == 0 || n == 1) return 1;
    return n * factorialRecursive(n - 1);
}
```

#### 2. Iterative
```cpp
long long factorialIterative(int n) {
    long long result = 1;
    for (int i = 2; i <= n; i++)
        result *= i;
    return result;
}
```

#### 3. Tail Recursive
```cpp
long long factorialTail(int n, long long accumulator = 1) {
    if (n == 0 || n == 1) return accumulator;
    return factorialTail(n - 1, n * accumulator);
}
```

### Complexity

| Approach       | Time | Space |
|----------------|------|-------|
| Recursive      | O(n) | O(n)  |
| Iterative      | O(n) | O(1)  |
| Tail Recursive | O(n) | O(n)* |

> *Can be O(1) with compiler tail-call optimization (`-O2` flag)

### Sample Output
```
Enter a number: 5

--- Factorial of 5 ---
Recursive  : 120
Iterative  : 120
Tail Recur : 120

Step-by-step: 5 x 4 x 3 x 2 x 1 = 120
```

---

## 🌀 Fibonacci (`fibonacci.cpp`)

### What is Fibonacci?
A sequence where each number is the sum of the two preceding ones.

```
F(0) = 0
F(1) = 1
F(n) = F(n-1) + F(n-2)

Series: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55 ...
```

### Approaches

#### 1. Naive Recursion ❌ (Slow)
```cpp
long long fibRecursive(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fibRecursive(n - 1) + fibRecursive(n - 2);
}
```

#### 2. Memoization — Top-Down DP ✅
```cpp
map<int, long long> memo;
long long fibMemo(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (memo.count(n)) return memo[n];
    memo[n] = fibMemo(n - 1) + fibMemo(n - 2);
    return memo[n];
}
```

#### 3. Bottom-Up DP ✅
```cpp
long long fibDP(int n) {
    vector<long long> dp(n + 1);
    dp[0] = 0; dp[1] = 1;
    for (int i = 2; i <= n; i++)
        dp[i] = dp[i-1] + dp[i-2];
    return dp[n];
}
```

#### 4. Space Optimized ⭐ (Best)
```cpp
long long fibOptimized(int n) {
    long long prev2 = 0, prev1 = 1, curr = 0;
    for (int i = 2; i <= n; i++) {
        curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    return curr;
}
```

### Complexity

| Approach         | Time   | Space |
|------------------|--------|-------|
| Naive Recursive  | O(2^n) | O(n)  |
| Memoization      | O(n)   | O(n)  |
| Bottom-Up DP     | O(n)   | O(n)  |
| Space Optimized  | O(n)   | O(1)  |

### Sample Output
```
Enter position n (0-indexed): 10

--- Fibonacci of 10 ---
Naive Recursive   : 55
Memoization       : 55
Bottom-Up DP      : 55
Space Optimized   : 55

Fibonacci Series (0 to 10): 0 1 1 2 3 5 8 13 21 34 55
```

---

## 🚀 How to Compile & Run

```bash
# Factorial
g++ factorial.cpp -o factorial
./factorial

# Fibonacci
g++ fibonacci.cpp -o fibonacci
./fibonacci

# With optimization (enables tail-call optimization)
g++ -O2 factorial.cpp -o factorial
```

---

## 💡 Key Concepts

- **Base Case** — The condition that stops recursion
- **Recursive Case** — The function calling itself with a smaller input
- **Memoization** — Caching results of subproblems to avoid recomputation
- **Tail Recursion** — Recursive call is the last operation (can be optimized by compiler)
- **Dynamic Programming** — Breaking a problem into overlapping subproblems

---

## 📚 Related Topics

- [Tower of Hanoi](../basics/tower_of_hanoi.cpp)
- [Backtracking — Subsets](../backtracking/subsets.cpp)
- [Backtracking — Permutations](../backtracking/permutations.cpp)
- [Divide & Conquer — Merge Sort](../divide_and_conquer/merge_sort.cpp)

---

## 🗂️ Folder Structure

```
recursion/
├── basics/
│   ├── factorial.cpp   ← You are here
│   ├── fibonacci.cpp   ← You are here
│   └── README.md
├── backtracking/
└── divide_and_conquer/
```