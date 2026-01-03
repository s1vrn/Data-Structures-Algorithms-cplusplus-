/**
 * Floyd-Warshall Algorithm
 * 
 * Problem: Find All-Pairs Shortest Path.
 * Time Complexity: O(V^3)
 * Suitable for: Small graphs (V <= 500). Works with negative weights (but no negative cycles).
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;

void floydWarshall(int n, vector<vector<int>>& graph) {
    // Initialize dist matrix equal to input graph
    vector<vector<int>> dist = graph;

    // Phase k: Try to use vertex k as an intermediate node
    for (int k = 0; k < n; k++) {
        // Iterate over all pairs (i, j)
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // If path via k is shorter, update dist[i][j]
                if (dist[i][k] != INF && dist[k][j] != INF && 
                    dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    cout << "Shortest Distance Matrix:\n";
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(dist[i][j] == INF) cout << "INF ";
            else cout << dist[i][j] << "   ";
        }
        cout << "\n";
    }
}

int main() {
    int n = 4;
    vector<vector<int>> graph = {
        {0,   5,   INF, 10},
        {INF, 0,   3,   INF},
        {INF, INF, 0,   1},
        {INF, INF, INF, 0}
    };

    floydWarshall(n, graph);
    // Path 0->1->2->3 cost 5+3+1 = 9.

    return 0;
}
