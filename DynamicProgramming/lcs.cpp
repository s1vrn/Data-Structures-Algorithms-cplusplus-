/**
 * Longest Common Subsequence (LCS)
 * 
 * Problem: Find the length of the longest subsequence present in both strings.
 * Example: "ABCDE", "ACE" -> "ACE" (Length 3)
 * 
 * Time Complexity: O(N * M)
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string s1 = "AGGTAB";
string s2 = "GXTXAYB";

int lcs() {
    int m = s1.length();
    int n = s2.length();
    
    // dp[i][j] stores LCS length of s1[0..i-1] and s2[0..j-1]
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1]; // Match found
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); // No match, take max from top or left
            }
        }
    }
    return dp[m][n];
}

int main() {
    cout << "String 1: " << s1 << "\n";
    cout << "String 2: " << s2 << "\n";
    cout << "Length of LCS: " << lcs() << "\n"; // Output should be 4 (GTAB)
    return 0;
}
