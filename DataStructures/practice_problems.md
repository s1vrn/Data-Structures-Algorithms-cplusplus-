# 🏗️ Practice Problems: Data Structures

Apply your knowledge of Arrays, Vectors, Maps, Sets, and Segment Trees.

## 🟢 Easy (Basic Containers)
1.  **[Distinct Numbers](https://cses.fi/problemset/task/1621)** (CSES) - Use `std::set` to count unique elements.
2.  **[Word Capitalization](https://codeforces.com/contest/281/problem/A)** (Codeforces) - Basic array/string indexing.
3.  **[Queue at the School](https://codeforces.com/contest/266/problem/B)** (Codeforces) - Simulating movements in an array.

## 🟡 Medium (Advanced Containers)
1.  **[Concert Tickets](https://cses.fi/problemset/task/1091)** (CSES) - Use `std::multiset` and `upper_bound`.
2.  **[Towers](https://cses.fi/problemset/task/1073)** (CSES) - Multiset/Binary Search applications.
3.  **[Union-Find Tutorial Problem](https://codeforces.com/edu/course/2/lesson/7/1/practice/contest/289390/problem/A)** (Codeforces) - Standard DSU practice.

## 🔴 Hard (Range Queries)
1.  **[Static Range Sum Queries](https://cses.fi/problemset/task/1646)** (CSES) - Prefix sums or Segment Tree.
2.  **[Dynamic Range Minimum Queries](https://cses.fi/problemset/task/1648)** (CSES) - Segment Tree with updates.

---

### 💡 Hints
*   When using `std::set`, remember that insertions are $O(\log N)$.
*   For **Concert Tickets**, the `upper_bound` function helps you find the first ticket price strictly greater than the customer's limit.
*   The **DSU** (Disjoint Set Union) is essential for connectivity problems!
