/**
 * Kadane's Algorithm
 * 
 * Problem: Find the Maximum Subarray Sum in an array (containing negative numbers).
 * Naive: O(N^2)
 * Kadane's: O(N)
 * 
 * Logic: Keep running max. If current running sum becomes negative, reset it to 0.
 */

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int maxSubArraySum(const vector<int>& nums) {
    int max_so_far = INT_MIN;
    int current_max = 0;

    for (int x : nums) {
        current_max += x;
        
        if (max_so_far < current_max)
            max_so_far = current_max;

        // If sum becomes negative, it won't help us maximize future sums.
        // So reset it to 0 (effectively starting a new subarray).
        if (current_max < 0)
            current_max = 0;
    }
    return max_so_far;
}

int main() {
    vector<int> a = {-2, -3, 4, -1, -2, 1, 5, -3};
    // Subarray {4, -1, -2, 1, 5} sums to 7.

    cout << "Maximum contiguous sum is " << maxSubArraySum(a) << "\n";
    return 0;
}
