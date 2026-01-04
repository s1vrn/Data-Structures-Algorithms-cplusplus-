# ⚡ Practice Problems: Bit Manipulation

Use binary magic to solve problems in O(1) or O(N).

## 🟢 Easy (Basic Operations)
1.  **[Bitwise AND of Numbers Range](https://leetcode.com/problems/bitwise-and-of-numbers-range/)** (LeetCode).
2.  **[Number of 1 Bits](https://leetcode.com/problems/number-of-1-bits/)** (LeetCode) - Population count.
3.  **[XOR Queries of a Subarray](https://leetcode.com/problems/xor-queries-of-a-subarray/)** (LeetCode) - Prefix XOR pattern.

## 🟡 Medium (Bitmasks)
1.  **[Apple Division](https://cses.fi/problemset/task/1623)** (CSES) - Solve using bitmasks instead of recursion.
2.  **[Finding the only non-duplicate element](https://leetcode.com/problems/single-number/)** (LeetCode) - XOR magic.
3.  **[Sum of Two Integers](https://leetcode.com/problems/sum-of-two-integers/)** (LeetCode) - Addition without `+` or `-`.

## 🔴 Hard (Advanced)
1.  **[Hamming Distance](https://cses.fi/problemset/task/2136)** (CSES) - Bitset optimizations.

---

### 💡 Hints
*   `x & (x - 1)` removes the rightmost set bit.
*   `a ^ a = 0`. This property is incredibly useful for finding unique elements.
*   `1LL << n` is the correct way to get $2^N$ for $N > 31$.
