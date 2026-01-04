/**
 * ✍️ Edit Distance (Levenshtein Distance)
 * 
 * Find the minimum number of operations to convert string A to string B.
 * Operations: Insert, Delete, Replace.
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int editDistance(string s1, string s2) {
    int m = s1.length();
    int n = s2.length();
    
    // dp[i][j] = distance between s1[0...i-1] and s2[0...j-1]
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0) {
                dp[i][j] = j; // Base case: s1 is empty
            } else if (j == 0) {
                dp[i][j] = i; // Base case: s2 is empty
            } else if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1]; // Characters match
            } else {
                dp[i][j] = 1 + min({
                    dp[i - 1][j],    // Delete
                    dp[i][j - 1],    // Insert
                    dp[i - 1][j - 1] // Replace
                });
            }
        }
    }
    return dp[m][n];
}

int main() {
    string word1 = "sunday";
    string word2 = "saturday";

    cout << "Edit Distance between '" << word1 << "' and '" << word2 << "': " 
         << editDistance(word1, word2) << endl;

    return 0;
}
