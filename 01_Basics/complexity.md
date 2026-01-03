# Time Complexity (Big O)

Understanding time complexity is crucial in competitive programming to predict if your solution will pass within the time limit (usually 1 second).

## Common Limits
In 1 second, a typical C++ (modern compiler) code can perform roughly $10^8$ operations.

| N (Input Size) | Acceptable Complexity | Example Algorithms |
| :--- | :--- | :--- |
| $N \le 10$ | $O(N!)$, $O(N^6)$ | Permutations |
| $N \le 20$ | $O(2^N)$ | Bitmask DP, Subsets |
| $N \le 100$ | $O(N^4)$ | 2D/3D Dynamic Programming |
| $N \le 500$ | $O(N^3)$ | Floyd-Warshall, Matrix Multiplication |
| $N \le 2000$ | $O(N^2)$ | Bubble Sort, 2-Nested Loops |
| $N \le 10^5$ | $O(N \log N)$ | Merge Sort, std::sort, Sets/Maps |
| $N \le 10^6$ | $O(N)$ | Two Pointers, Linear Scan |
| $N \le 10^9$ | $O(\sqrt{N})$ | Primality Check (Trial Division) |
| $N \le 10^{18}$ | $O(\log N)$ | Binary Exponentiation, GCD |

## Tips
1.  **Look at Constraints**: always check the constraints of the problem variables first.
2.  **Estimate Worst Case**: Calculate the number of operations for the largest input.
3.  **Space Complexity**: Don't forget memory limits (usually 256MB or 512MB). Creating an array `int arr[10^8]` will exceed memory (~400MB).