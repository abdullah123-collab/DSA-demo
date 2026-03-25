# 8 - Graph Algorithms

A graph is a non-linear data structure consisting of **vertices (nodes)** and **edges** that connect them.

---

## 📁 Files in This Folder

| File | Description |
|------|-------------|
| `1-BFS.cpp` | Breadth First Search using Queue |
| `2-DFS.cpp` | Depth First Search using Recursion |

---

## 📌 What is a Graph?

```
    0 ──── 1 ──── 3
    │             │
    2 ──── 4      5
```

- **Vertices**: Nodes (0, 1, 2, 3, 4, 5)
- **Edges**: Connections between nodes
- **Adjacency List**: Each node stores its neighbors

---

## 🔍 BFS (Breadth First Search)

Explores all neighbors level by level using a **Queue**.

```
Start at 0:
Level 0 → 0
Level 1 → 1, 2
Level 2 → 3, 4
Level 3 → 5

Output: 0 1 2 3 4 5
```

### Algorithm:
1. Push start node into Queue, mark visited
2. Pop front node, print it
3. Push all unvisited neighbors
4. Repeat until Queue is empty

### Code Snippet:
```cpp
void BFS(int start) {
    vector<bool> visited(vertices, false);
    queue<int> q;
    visited[start] = true;
    q.push(start);
    while (!q.empty()) {
        int node = q.front(); q.pop();
        cout << node << " ";
        for (int neighbor : adjList[node])
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
    }
}
```

---

## 🔍 DFS (Depth First Search)

Explores as deep as possible before backtracking using **Recursion**.

```
Start at 0:
0 → 1 → 3 → 5 → backtrack → 2 → 4

Output: 0 1 3 5 2 4
```

### Algorithm:
1. Mark current node as visited, print it
2. Recursively visit all unvisited neighbors
3. Backtrack when no unvisited neighbor exists

### Code Snippet:
```cpp
void DFSHelper(int node, vector<bool>& visited) {
    visited[node] = true;
    cout << node << " ";
    for (int neighbor : adjList[node])
        if (!visited[neighbor])
            DFSHelper(neighbor, visited);
}
```

---

## ⚖️ BFS vs DFS Comparison

| Feature | BFS | DFS |
|---------|-----|-----|
| **Data Structure** | Queue | Stack / Recursion |
| **Traversal Order** | Level by level | Deep first |
| **Time Complexity** | O(V + E) | O(V + E) |
| **Space Complexity** | O(V) | O(V) |
| **Best For** | Shortest path | Cycle detection |
| **Use Cases** | Social networks, GPS | Maze solving, Topological sort |

---

## 🧠 Real World Applications

### BFS:
- 🗺️ Google Maps (shortest route)
- 👥 Facebook (friend suggestions)
- 🌐 Web crawlers

### DFS:
- 🧩 Solving mazes
- 📦 Topological sorting
- 🔄 Detecting cycles in a graph

---

## ▶️ How to Compile & Run

```bash
# BFS
g++ 1-BFS.cpp -o bfs
./bfs

# DFS
g++ 2-DFS.cpp -o dfs
./dfs
```

---

## 📚 Related Topics
- Dijkstra's Algorithm (Shortest Path)
- Minimum Spanning Tree (Prim's / Kruskal's)
- Topological Sort
- Cycle Detection

---

*Part of the Data Structures & Algorithms series in C++*