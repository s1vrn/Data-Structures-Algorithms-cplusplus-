/**
 * 🌲 Minimum Spanning Tree (Kruskal's Algorithm)
 * 
 * Find a subset of edges that connects all vertices without cycles 
 * and with the minimum total edge weight.
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v, weight;
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

struct DSU {
    vector<int> parent;
    DSU(int n) {
        parent.resize(n);
        for (int i = 0; i < n; i++) parent[i] = i;
    }
    int find(int i) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent[i]);
    }
    bool unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            parent[root_i] = root_j;
            return true;
        }
        return false;
    }
};

int main() {
    int N = 4;
    vector<Edge> edges = {
        {0, 1, 10}, {0, 2, 6}, {0, 3, 5},
        {1, 3, 15}, {2, 3, 4}
    };

    sort(edges.begin(), edges.end());

    DSU dsu(N);
    int mst_weight = 0;
    vector<Edge> mst_edges;

    for (auto& edge : edges) {
        if (dsu.unite(edge.u, edge.v)) {
            mst_weight += edge.weight;
            mst_edges.push_back(edge);
        }
    }

    cout << "Total MST Weight: " << mst_weight << endl;
    cout << "Edges in MST:" << endl;
    for (auto& edge : mst_edges) {
        cout << edge.u << " -- " << edge.v << " == " << edge.weight << endl;
    }

    return 0;
}
