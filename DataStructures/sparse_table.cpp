/**
 * 📊 Sparse Table
 * 
 * Sparse Table is a data structure that answers Range Minimum Queries (RMQ)
 * in O(1) time after O(N log N) preprocessing.
 * It works for any idempotent function (min, max, gcd).
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const int MAXN = 100005;
const int K = 20; // 2^K > MAXN

int st[MAXN][K];
int lg[MAXN];

void build(const vector<int>& a) {
    int n = a.size();
    
    // Precompute logs
    lg[1] = 0;
    for (int i = 2; i <= n; i++)
        lg[i] = lg[i/2] + 1;

    // Base case: intervals of length 1
    for (int i = 0; i < n; i++)
        st[i][0] = a[i];

    // Build the table
    for (int j = 1; j < K; j++) {
        for (int i = 0; i + (1 << j) <= n; i++) {
            st[i][j] = min(st[i][j-1], st[i + (1 << (j - 1))][j-1]);
        }
    }
}

int query(int L, int R) {
    int j = lg[R - L + 1];
    return min(st[L][j], st[R - (1 << j) + 1][j]);
}

int main() {
    vector<int> a = {1, 3, 2, 7, 9, 11, 3, 1};
    build(a);

    cout << "Range Minimum Query [1, 5]: " << query(1, 5) << endl; // min(3, 2, 7, 9, 11) = 2
    cout << "Range Minimum Query [0, 7]: " << query(0, 7) << endl; // min of all = 1

    return 0;
}
