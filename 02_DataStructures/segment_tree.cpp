/**
 * Segment Tree
 * 
 * Efficiently answers range queries and updates.
 * Query: O(log N)
 * Update: O(log N)
 * Space: O(4 * N)
 */

#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 100005;
int t[4 * MAXN]; // Tree array

// Build: node=1, range [tl, tr]
void build(const vector<int>& a, int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = t[v*2] + t[v*2+1]; // Sum Query
    }
}

// Sum Query: range [l, r]
int sum(int v, int tl, int tr, int l, int r) {
    if (l > r) 
        return 0;
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return sum(v*2, tl, tm, l, min(r, tm)) +
           sum(v*2+1, tm+1, tr, max(l, tm+1), r);
}

// Point Update: index pos becomes new_val
void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        t[v] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        t[v] = t[v*2] + t[v*2+1];
    }
}

int main() {
    vector<int> a = {1, 3, 5, 7, 9, 11};
    int n = a.size();

    // Arrays in CP are often 1-indexed for convenience in Segment Trees,
    // but here we map 0-indexed vector to the tree range [0, n-1]
    
    build(a, 1, 0, n-1);
    
    cout << "Sum of range [1, 3] (elements 3, 5, 7): " << sum(1, 0, n-1, 1, 3) << "\n"; // 15
    
    update(1, 0, n-1, 1, 10); // Update index 1 (val 3) to 10
    
    cout << "Sum after update [1, 3] (elements 10, 5, 7): " << sum(1, 0, n-1, 1, 3) << "\n"; // 22

    return 0;
}
