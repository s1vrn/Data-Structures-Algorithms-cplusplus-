/**
 * Disjoint Set Union (Union-Find)
 * 
 * Efficiently manages disjoint sets.
 * Operations: Union (merge two sets), Find (determine which set an element belongs to).
 * Optimizations: Path Compression & Union by Rank.
 * Complexity: Nearly O(1) amortized (O(alpha(N))).
 */

#include <iostream>
#include <vector>
#include <numeric> // for iota

using namespace std;

struct DSU {
    vector<int> parent;
    vector<int> rank;

    DSU(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0); // Rank/Depth initially 0
        // Initialize parent[i] = i
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int i) {
        if (parent[i] == i)
            return i;
        // Path Compression
        return parent[i] = find(parent[i]);
    }

    void unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);

        if (root_i != root_j) {
            // Union by Rank: Attach smaller tree to larger tree
            if (rank[root_i] < rank[root_j])
                parent[root_i] = root_j;
            else if (rank[root_i] > rank[root_j])
                parent[root_j] = root_i;
            else {
                parent[root_i] = root_j;
                rank[root_j]++;
            }
        }
    }
};

int main() {
    DSU dsu(5);
    
    dsu.unite(1, 2);
    dsu.unite(3, 4);
    
    // Check if 1 and 2 are connected
    if(dsu.find(1) == dsu.find(2)) 
        cout << "1 and 2 are in the same set.\n";
    else
        cout << "1 and 2 are NOT in the same set.\n";
        
    // Check if 1 and 3 are connected
    if(dsu.find(1) == dsu.find(3))
        cout << "1 and 3 are in the same set.\n";
    else
        cout << "1 and 3 are NOT in the same set.\n";
        
    dsu.unite(1, 3);
    cout << "United 1 and 3.\n";
    
    // Now 1, 2, 3, 4 should all be connected (via 1-2, 3-4, 1-3)
    if(dsu.find(2) == dsu.find(4))
        cout << "2 and 4 are now in the same set (indirectly).\n";

    return 0;
}
