# ⏱️ Understanding Time Complexity (Big O)

In Competitive Programming, it's not enough to solve a problem—you must solve it **fast enough**. Most problems have a **1-second time limit**.

## 1. The Core Idea: "Counting Operations"
Imagine the computer can perform roughly **100,000,000 (10^8) simple operations per second**.
Complexity ($O$) tells us how many times your code runs relative to the input size ($N$).

### Example: Finding a book in a shelf of $N$ books.
1.  **Linear Scan ($O(N)$)**: You check one by one from left to right.
    *   If $N=10$, you check 10 times.
    *   If $N=10^8$, it takes ~1 second. (Safe!)
2.  **Binary Search ($O(\log N)$)**: The shelf is sorted, so you jump to the middle, then half again.
    *   If $N=10^8$, you only check ~27 times! (Super Fast!)
3.  **Nested Loops ($O(N^2)$)**: For every book, you scan the whole shelf again.
    *   If $N=10$, you check 100 times.
    *   If $N=10^5$, you check $10^{10}$ times. (Wait! That's 100 seconds. **TLE!**)

---

## 2. The "Cheat Sheet" for Constraints
When you read a problem, look at the constraints for $N$. They tell you which algorithm to use!

| $N$ (Input Size) | Acceptable $O$ | Example Scenario |
| :--- | :--- | :--- |
| **$N \le 10$** | $O(N!)$ | Trying every possible order (Permutations). |
| **$N \le 20$** | $O(2^N)$ | Trying every possible subset. |
| **$N \le 500$** | $O(N^3)$ | Triple nested loops. |
| **$N \le 5,000$** | $O(N^2)$ | Double nested loops (e.g., Bubble Sort). |
| **$N \le 10^5$** | $O(N \log N)$ | Sorting, Segment Trees, Priority Queues. |
| **$N \le 10^6$** | $O(N)$ | Single loop, Two Pointers, Linear scan. |
| **$N \ge 10^9$** | $O(\log N)$ or $O(1)$ | Binary Search on answer, GCD, Math formulas. |

---

## 3. How to analyze your code?
Ignore constants. $O(2N + 5)$ is just **$O(N)$**. We only care about the "biggest" part.

```cpp
for(int i=0; i<n; i++) {       // Runs N times
    for(int j=0; j<n; j++) {   // Runs N times for each i
        // simple math operation
    }
}
// Total: N * N = O(N^2)
```

---

## 4. Helpful Tips
1.  **TLE (Time Limit Exceeded)**: This usually means your $O$ is too high for the constraints.
2.  **Space Complexity**: Be careful with memory! An array `int a[10^8]` uses ~400MB. If the limit is 256MB, your program will crash (**MLE** - Memory Limit Exceeded).
3.  **The 10^8 Rule**: Always aim for your total operations to be $\le 10^8$. 

**Formula**: (Ops per test case) $\times$ (Number of test cases) $\le 10^8$.