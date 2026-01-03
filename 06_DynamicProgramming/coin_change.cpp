/**
 * Coin Change Problem
 * 
 * Variant 1: Min coins to make amount X.
 * Variant 2: Number of ways to make amount X.
 * 
 * Time Complexity: O(N * Amount)
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;

// 1. Minimum Coins to make Amount
int minCoins(vector<int>& coins, int amount) {
    // dp[i] = min coins to make amount i
    vector<int> dp(amount + 1, INF);
    dp[0] = 0;

    for (int i = 1; i <= amount; i++) {
        for (int coin : coins) {
            if (i - coin >= 0) {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }
    return (dp[amount] == INF) ? -1 : dp[amount];
}

// 2. Number of Ways to make Amount
long long waysToMake(vector<int>& coins, int amount) {
    // dp[i] = number of ways to make amount i
    vector<long long> dp(amount + 1, 0);
    dp[0] = 1; // Base case: one way to make 0 (use nothing)

    for (int coin : coins) { // Iterate coins first to avoid duplicates (permutations vs combinations)
        for (int i = coin; i <= amount; i++) {
            dp[i] += dp[i - coin];
        }
    }
    return dp[amount];
}

int main() {
    vector<int> coins = {1, 2, 5};
    int amount = 11;

    cout << "Min Coins for " << amount << ": " << minCoins(coins, amount) << "\n";
    cout << "Ways to make " << amount << ": " << waysToMake(coins, amount) << "\n";

    return 0;
}
