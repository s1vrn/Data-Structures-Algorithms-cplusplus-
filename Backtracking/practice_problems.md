# 🔙 Practice Problems: Backtracking

Explore every possibility with smart recursion.

## 🟢 Easy (Basic Recursion)
1.  **[Apple Division](https://cses.fi/problemset/task/1623)** (CSES) - Try every combination of weights.
2.  **[Creating Strings](https://cses.fi/problemset/task/1622)** (CSES) - Generate all unique permutations.

## 🟡 Medium (Decision Trees)
1.  **[N-Queens Puzzle](https://leetcode.com/problems/n-queens/)** (LeetCode) - Classical backtracking obstacle.
2.  **[Chessboard and Queens](https://cses.fi/problemset/task/1624)** (CSES) - Constraint-based permutations.
3.  **[Subset Sum](https://leetcode.com/problems/subsets/)** (LeetCode) - Generating power sets.

## 🔴 Hard (Pruning)
1.  **[Grid Paths](https://cses.fi/problemset/task/1625)** (CSES) - Very tight backtracking with pruning.

---

### 💡 Hints
*   Backtracking is "Brute Force with a Brain". Always check if a path is invalid early (**pruning**).
*   For **Apple Division**, you have $2^N$ choices. If $N \le 20$, this is perfectly fine.
*   Don't forget to **undo** your changes after the recursive call (e.g., `path.pop_back()`).
