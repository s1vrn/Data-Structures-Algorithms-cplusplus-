# 🤖 Handling Interactive Problems

In some CP problems, you don't receive all the input at once. Instead, you "talk" to the judge by asking questions and receiving answers.

## 1. The Flushing Problem
By default, C++ buffers output to make it faster. In interactive problems, if you don't "flush" the buffer, the judge will never see your question, and you will get **Time Limit Exceeded (TLE)** or **Idleness Limit Exceeded**.

### How to Flush:
1.  **Use `endl`**: Unlike `\n`, `endl` automatically flushes.
2.  **Manual Flush**: `cout.flush()` or `cout << flush;`.
3.  **Standard Sync**: If you use `ios::sync_with_stdio(0); cin.tie(0);`, be careful! You MUST flush manually.

## 2. Example Structure (Binary Search)
Imagine you need to guess a number $X$ in $[1, 10^9]$.

```cpp
int low = 1, high = 1e9, ans = -1;
while(low <= high) {
    int mid = low + (high - low) / 2;
    cout << "? " << mid << endl; // Ask the judge
    
    string response;
    cin >> response; // Read the answer
    
    if(response == "correct") {
        ans = mid;
        break;
    } else if(response == "greater") {
        low = mid + 1;
    } else {
        high = mid - 1;
    }
}
cout << "! " << ans << endl; // Final answer
```

## 3. Important Tips
*   **Don't use Fast I/O untie**: `cin.tie(NULL)` makes it harder to synchronize questions/answers. Keep it simple.
*   **Wait for response**: Always read the judge's response before printing the next question.
*   **Debug with `cerr`**: `cerr` is never buffered and doesn't interfere with the judge. Use it to see your variables.
