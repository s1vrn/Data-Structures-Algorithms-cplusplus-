# 🕸️ Practice Problems: Graph Theory

Implement BFS, DFS, Dijkstra, and explore connectivity.

## 🟢 Easy (Traversals)
1.  **[Counting Rooms](https://cses.fi/problemset/task/1192)** (CSES) - Find connected components using DFS/BFS.
2.  **[Message Route](https://cses.fi/problemset/task/1667)** (CSES) - BFS to find the shortest path in an unweighted graph.
3.  **[Building Roads](https://cses.fi/problemset/task/1666)** (CSES) - Use DSU or DFS to count components.

## 🟡 Medium (Shortest Paths)
1.  **[Shortest Routes I](https://cses.fi/problemset/task/1671)** (CSES) - Classical Dijkstra.
2.  **[Shortest Routes II](https://cses.fi/problemset/task/1672)** (CSES) - Classical Floyd-Warshall (All-Pairs).
3.  **[Course Schedule](https://cses.fi/problemset/task/1679)** (CSES) - Topological Sort.

## 🔴 Hard (Advanced Connectivity)
1.  **[Flight Discount](https://cses.fi/problemset/task/1195)** (CSES) - Dijkstra on a modified graph.
2.  **[Round Trip](https://cses.fi/problemset/task/1669)** (CSES) - Cycle detection using DFS.

---

### 💡 Hints
*   **BFS** finds the shortest path by *number of edges*.
*   **Dijkstra** finds the shortest path by *weight* (only for positive weights).
*   For **Counting Rooms**, treat the 2D grid as a graph where each '.' is a node connected to adjacent '.'.
