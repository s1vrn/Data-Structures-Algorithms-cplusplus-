/**
 * 🔢 Digit DP
 * 
 * Digit DP is used to count numbers in a range [L, R] that satisfy 
 * a certain property based on their digits.
 * Example: How many numbers in [1, N] have sum of digits equal to S?
 */

#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

string N;
long long memo[20][200][2]; // [pos][sum][is_less]

long long dp(int pos, int sum, bool is_less) {
    if (pos == N.size()) return sum == 0; // Check your specific condition here
    if (memo[pos][sum][is_less] != -1) return memo[pos][sum][is_less];

    long long ans = 0;
    int limit = is_less ? 9 : N[pos] - '0';

    for (int digit = 0; digit <= limit; digit++) {
        ans += dp(pos + 1, sum - digit, is_less || (digit < limit));
    }

    return memo[pos][sum][is_less] = ans;
}

long long solve(long long num, int target_sum) {
    N = to_string(num);
    memset(memo, -1, sizeof(memo));
    return dp(0, target_sum, false);
}

int main() {
    long long n = 1000;
    int s = 10;
    cout << "Numbers between 0 and " << n << " with digit sum " << s << ": " 
         << solve(n, s) << endl;

    return 0;
}
