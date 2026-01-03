/**
 * Fenwick Tree (Binary Indexed Tree)
 * 
 * Supports Prefix Sums and Point Updates efficiently.
 * Simpler to code than Segment Tree, uses less memory.
 * Complexity: O(log N) for both query and update.
 * Space: O(N)
 */

#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> bit;

// Update: Add val to element at index idx
void update(int idx, int val) {
    for (; idx <= n; idx += idx & -idx)
        bit[idx] += val;
}

// Query: Sum from 1 to idx
int query(int idx) {
    int sum = 0;
    for (; idx > 0; idx -= idx & -idx)
        sum += bit[idx];
    return sum;
}

int main() {
    vector<int> a = {0, 2, 1, 1, 3, 2, 3, 4, 5, 6, 7, 8, 9}; // 1-indexed, a[0] ignored
    n = a.size() - 1; 

    bit.assign(n + 1, 0);

    // Build BIT
    for (int i = 1; i <= n; i++)
        update(i, a[i]);

    cout << "Prefix sum of first 5 elements: " << query(5) << "\n"; // 2+1+1+3+2 = 9
    cout << "Sum of range [2, 4]: " << query(4) - query(1) << "\n"; // (2+1+1+3) - (2) = 5 (elements 1, 1, 3)

    return 0;
}
