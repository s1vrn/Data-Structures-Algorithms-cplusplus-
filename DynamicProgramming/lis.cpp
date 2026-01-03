/**
 * Longest Increasing Subsequence (LIS)
 * 
 * Problem: Find the length of the longest subsequence where elements are strictly increasing.
 * 
 * Approaches:
 * 1. DP O(N^2): Simple double loop.
 * 2. Binary Search O(N log N): Optimized approach (Patience Sorting).
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// O(N^2) Approach
int lis_dp(const vector<int>& nums) {
    if (nums.empty()) return 0;
    int n = nums.size();
    vector<int> dp(n, 1);
    int max_len = 1;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        max_len = max(max_len, dp[i]);
    }
    return max_len;
}

// O(N log N) Approach
int lis_optimized(const vector<int>& nums) {
    if (nums.empty()) return 0;
    vector<int> tails; // Contains the smallest tail of all increasing subsequences of length i+1
    
    for (int x : nums) {
        auto it = lower_bound(tails.begin(), tails.end(), x);
        if (it == tails.end()) {
            tails.push_back(x);
        } else {
            *it = x; // Update existing tail to smaller value
        }
    }
    return tails.size();
}

int main() {
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    
    cout << "LIS (DP O(N^2)): " << lis_dp(nums) << "\n";
    cout << "LIS (Optimized O(N log N)): " << lis_optimized(nums) << "\n";
    
    return 0;
}
