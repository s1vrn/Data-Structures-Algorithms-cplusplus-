/**
 * 🎨 Graph Coloring (M-Coloring Problem)
 * 
 * Find if it's possible to color a graph with M colors such that
 * no two adjacent vertices have the same color.
 */

#include <iostream>
#include <vector>

using namespace std;

bool isSafe(int v, vector<vector<int>>& adj, vector<int>& color, int c) {
    for (int neighbor : adj[v]) {
        if (color[neighbor] == c) return false;
    }
    return true;
}

bool graphColoring(int v, vector<vector<int>>& adj, vector<int>& color, int m, int N) {
    if (v == N) return true; // All vertices colored

    // Try colors from 1 to m
    for (int c = 1; c <= m; c++) {
        if (isSafe(v, adj, color, c)) {
            color[v] = c;
            if (graphColoring(v + 1, adj, color, m, N)) return true;
            color[v] = 0; // Backtrack
        }
    }
    return false;
}

int main() {
    int N = 4;
    vector<vector<int>> adj(N);
    // 0-1, 1-2, 2-3, 3-0, 0-2 (A complete graph minus one edge)
    adj[0] = {1, 3, 2}; adj[1] = {0, 2}; adj[2] = {1, 3, 0}; adj[3] = {2, 0};

    int m = 3; // Number of colors
    vector<int> color(N, 0);

    if (graphColoring(0, adj, color, m, N)) {
        cout << "Graph can be colored with " << m << " colors." << endl;
        for (int i = 0; i < N; i++) cout << "Vertex " << i << ": " << color[i] << endl;
    } else {
        cout << "No solution exists for " << m << " colors." << endl;
    }

    return 0;
}
