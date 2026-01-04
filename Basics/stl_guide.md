# 🛠️ Introduction to the STL (Standard Template Library)

The STL is the most powerful tool in C++. It provides "pre-written" data structures and algorithms so you don't have to reinvent the wheel.

## 1. The Big Three (Containers)
1.  **`std::vector`**: The dynamic array. Can resize itself automatically.
2.  **`std::set`**: Stores unique elements and keeps them **sorted**. (Useful for "How many unique elements?")
3.  **`std::map`**: Stores Key-Value pairs. Basically an array where the index can be a string! (e.g., `score["Alice"] = 100`).

## 2. The Smart Tools (Algorithms)
Found in `<algorithm>`:
*   **`sort(v.begin(), v.end())`**: Sorts anything in $O(N \log N)$.
*   **`reverse(s.begin(), s.end())`**: Reverses a string or vector.
*   **`lower_bound()`**: Binary search for the first element $\ge X$.
*   **`__gcd(a, b)`**: Instantly find the Greatest Common Divisor.

## 3. Why use STL?
*   **Speed**: They are highly optimized by experts.
*   **Safety**: Less error-prone than manual manual memory management.
*   **Standard**: Every CP site supports them.

*Next Step: Explore the `DataStructures/` and `Algorithms/` folders to see these in action!*
