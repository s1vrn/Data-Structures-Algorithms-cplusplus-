# 🐞 Debugging Tips for CP Beginners

Everyone gets bugs. The difference between a pro and a beginner is how fast they find them.

## 1. The Power of `cerr`
Never use `cout` to find where your code fails, because it might mess up your program output. Use `cerr` (Character Error) instead. It prints to the terminal but is ignored by the online judge.

```cpp
int target = 10;
cerr << "DEBUG: Current value of target is: " << target << "\n";
```

## 2. Common "Gotcha" Bugs
1.  **Integer Overflow**: If a problem says $N \times M$ and both are $10^9$, the product is $10^{18}$. An `int` only goes up to $2 \times 10^9$. You MUST use `long long`.
2.  **Off-by-One**: Does your loop start at 0 or 1? Does it go to `i < n` or `i <= n`? This is the most common bug in history.
3.  **Array Out of Bounds**: Accessing `arr[10]` when your array size is 10 (valid indices are 0 to 9).
4.  **Floating Point Precision**: When using `double`, $0.1 + 0.2$ might be $0.30000000000004$. Use a small `EPS = 1e-9` for comparisons.

## 3. The "Stupid" Check
If you are stuck for 10 minutes:
*   Read the problem AGAIN. Did you miss a constraint?
*   Check your Fast I/O.
*   Check if you reset your variables for multiple test cases.

## 4. Manual Dry Run
Take a piece of paper and a pen. Trace your variables for the sample input. Computers are fast, but paper is smart.
