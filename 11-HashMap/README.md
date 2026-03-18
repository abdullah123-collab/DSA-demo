# 11 - Hash Map 🗂️

A Hash Map (Hash Table) stores **key-value pairs** using a hash function to compute an index for fast access.  
In C++, implemented via `unordered_map` from STL.

---

## 📌 Key Concepts

- **Hash Function** — converts a key into an array index
- **Collision** — when two keys hash to the same index
- **Load Factor** — ratio of elements to bucket count
- **Chaining / Open Addressing** — collision resolution strategies

---

## ⚙️ Operations & Time Complexity

| Operation  | Method (C++)          | Average | Worst  |
|------------|-----------------------|---------|--------|
| Insert     | `map[key] = val`      | O(1)    | O(n)   |
| Update     | `map[key] = val`      | O(1)    | O(n)   |
| Search     | `map.find(key)`       | O(1)    | O(n)   |
| Delete     | `map.erase(key)`      | O(1)    | O(n)   |
| Traversal  | `for(auto& e : map)`  | O(n)    | O(n)   |
| Size       | `map.size()`          | O(1)    | O(1)   |

---

## 💻 Code Example
```cpp
#include<iostream>
#include<unordered_map>
using namespace std;

int main(){

    // 1. INSERT & UPDATE
    unordered_map<string, int> shop;
    shop["Apple"] = 50;
    shop["Banana"] = 20;
    shop["Mango"] = 80;
    shop["Apple"] = 60;  // UPDATE

    // 2. SEARCH — O(1)
    if(shop.find("Mango") != shop.end())
        cout << "Mango: " << shop["Mango"] << endl;

    // 3. DELETE
    shop.erase("Banana");

    // 4. TRAVERSAL
    for(auto& entry : shop)
        cout << entry.first << " : " << entry.second << endl;

    // 5. FREQUENCY COUNT (classic pattern)
    unordered_map<string, int> freq;
    string words[] = {"apple", "banana", "apple", "mango", "banana", "apple"};
    for(string w : words)
        freq[w]++;

    for(auto& entry : freq)
        cout << entry.first << " : " << entry.second << " times" << endl;

    return 0;
}
```

---

## 🔄 unordered_map vs map

| Feature        | `unordered_map`     | `map`             |
|----------------|---------------------|-------------------|
| Order          | No order            | Sorted by key     |
| Search Time    | O(1) average        | O(log n)          |
| Implementation | Hash Table          | Red-Black Tree    |
| Header         | `<unordered_map>`   | `<map>`           |
| Use When       | Speed matters       | Order matters     |

---

## ✅ Common Use Cases

- Frequency counting of elements
- Two Sum — store complement values
- Grouping anagrams
- Caching / Memoization in DP
- Detecting duplicates
- Graph adjacency lists

---

## 🧩 Practice Problems

| # | Problem | Difficulty | Pattern |
|---|---------|------------|---------|
| 1 | [Two Sum](https://leetcode.com/problems/two-sum/) | 🟢 Easy | Complement lookup |
| 2 | [Valid Anagram](https://leetcode.com/problems/valid-anagram/) | 🟢 Easy | Frequency count |
| 3 | [Group Anagrams](https://leetcode.com/problems/group-anagrams/) | 🟡 Medium | Key grouping |
| 4 | [Top K Frequent Elements](https://leetcode.com/problems/top-k-frequent-elements/) | 🟡 Medium | Freq + Heap |
| 5 | [Longest Consecutive Sequence](https://leetcode.com/problems/longest-consecutive-sequence/) | 🟡 Medium | Set/Map lookup |
| 6 | [Subarray Sum Equals K](https://leetcode.com/problems/subarray-sum-equals-k/) | 🟡 Medium | Prefix sum + Map |