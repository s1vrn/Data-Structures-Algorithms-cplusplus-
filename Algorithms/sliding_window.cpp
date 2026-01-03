/**
 * Sliding Window Technique
 * 
 * A powerful technique to perform operations on a specific window size of an array or string.
 * Reduces O(N^2) nested loops to O(N).
 * 
 * Two Types:
 * 1. Fixed Size Window (e.g., Max sum of subarray of size K)
 * 2. Variable Size Window (e.g., Smallest subarray with sum >= S)
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 1. Fixed Size Window: Max Sum of Subarray of size K
int maxSumSubarray(const vector<int>& arr, int k) {
    int n = arr.size();
    if (n < k) return -1;

    // Compute sum of first window
    int current_sum = 0;
    for (int i = 0; i < k; i++)
        current_sum += arr[i];

    int max_sum = current_sum;

    // Slide the window
    for (int i = k; i < n; i++) {
        // Add next element, remove first element of previous window
        current_sum += arr[i] - arr[i - k];
        max_sum = max(max_sum, current_sum);
    }

    return max_sum;
}

int main() {
    vector<int> arr = {1, 4, 2, 10, 2, 3, 1, 0, 20};
    int k = 4;
    
    cout << "Array: ";
    for(int x : arr) cout << x << " ";
    cout << "\n";
    
    cout << "Max sum of subarray of size " << k << ": " << maxSumSubarray(arr, k) << "\n"; 
    // Subarray {2, 10, 2, 3} sum = 17? No.
    // {10, 2, 3, 1} = 16
    // {4, 2, 10, 2} = 18.  Wait, let's trace:
    // Window 1: 1+4+2+10 = 17  (Max: 17)
    // Window 2: 17 + 2 - 1 = 18 (Max: 18) -> {4, 2, 10, 2}
    // Window 3: 18 + 3 - 4 = 17
    // ...
    // Last Window: {3, 1, 0, 20} = 24.
    // Returns 24.

    return 0;
}
