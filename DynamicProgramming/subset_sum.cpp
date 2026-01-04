/**
 * 🔢 Subset Sum Problem
 * 
 * Check if there exists a subset of a given set such that the sum 
 * of its elements is equal to a target value S.
 */

#include <iostream>
#include <vector>

using namespace std;

bool canAchieveSum(const vector<int>& nums, int target) {
    int n = nums.size();
    // dp[i][j] = true if sum j is possible using first i elements
    vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));

    // Base case: sum 0 is always possible
    for (int i = 0; i <= n; i++) dp[i][0] = true;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= target; j++) {
            if (j < nums[i - 1]) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
            }
        }
    }
    return dp[n][target];
}

// Optimized version using O(target) space
bool canAchieveSumOptimized(const vector<int>& nums, int target) {
    vector<bool> dp(target + 1, false);
    dp[0] = true;
    for (int x : nums) {
        for (int j = target; j >= x; j--) {
            dp[j] = dp[j] || dp[j - x];
        }
    }
    return dp[target];
}

int main() {
    vector<int> nums = {3, 34, 4, 12, 5, 2};
    int sum = 9;

    if (canAchieveSumOptimized(nums, sum))
        cout << "Found a subset with sum " << sum << endl;
    else
        cout << "No subset with sum " << sum << endl;

    return 0;
}
