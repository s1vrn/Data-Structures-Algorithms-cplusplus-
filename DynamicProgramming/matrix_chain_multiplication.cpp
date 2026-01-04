/**
 * 🧊 Matrix Chain Multiplication (Interval DP)
 * 
 * Find the most efficient way to multiply a given sequence of matrices.
 * The goal is to find the order of multiplication that minimize the number 
 * of scalar multiplications.
 */

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int main() {
    // Dimensions of matrices: A1(10x20), A2(20x30), A3(30x40)
    // Represented as {10, 20, 30, 40}
    vector<int> p = {10, 20, 30, 40, 30};
    int n = p.size();

    // dp[i][j] = minimum number of multiplications to multiply matrices from i to j
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // L is chain length
    for (int L = 2; L < n; L++) {
        for (int i = 1; i < n - L + 1; i++) {
            int j = i + L - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; k++) {
                int q = dp[i][k] + dp[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < dp[i][j])
                    dp[i][j] = q;
            }
        }
    }

    cout << "Minimum cost of multiplications: " << dp[1][n - 1] << endl;

    return 0;
}
