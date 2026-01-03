/**
 * 0/1 Knapsack Problem
 * 
 * Problem: Given val[] and wt[] of N items, and a capacity W,
 * find the maximum value you can put in the knapsack of capacity W.
 * 
 * Time Complexity: O(N * W)
 * Space Complexity: O(N * W) or O(W) with optimization
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 1. Recursive with Memoization (Top-Down)
int memo[105][10005]; // [N][W]
int val[] = {60, 100, 120};
int wt[] = {10, 20, 30};
int N = 3;

int knapsackRecursive(int idx, int w) {
    if (idx < 0 || w == 0) return 0;
    if (memo[idx][w] != -1) return memo[idx][w];

    if (wt[idx] > w) {
        return memo[idx][w] = knapsackRecursive(idx - 1, w);
    } else {
        return memo[idx][w] = max(
            val[idx] + knapsackRecursive(idx - 1, w - wt[idx]), // Take
            knapsackRecursive(idx - 1, w) // Don't take
        );
    }
}

// 2. Iterative (Bottom-Up)
int knapsackIterative(int W) {
    // dp[i][w] = max value using first i items with capacity w
    vector<vector<int>> dp(N + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= N; i++) {
        for (int w = 0; w <= W; w++) {
            if (wt[i-1] <= w) {
                dp[i][w] = max(
                    val[i-1] + dp[i-1][w - wt[i-1]], 
                    dp[i-1][w]
                );
            } else {
                dp[i][w] = dp[i-1][w];
            }
        }
    }
    return dp[N][W];
}

int main() {
    // Initialize memo
    for(int i=0; i<105; i++)
        for(int j=0; j<10005; j++) memo[i][j] = -1;

    int W = 50;
    cout << "Max Value (Recursive): " << knapsackRecursive(N - 1, W) << "\n";
    cout << "Max Value (Iterative): " << knapsackIterative(W) << "\n";

    return 0;
}
