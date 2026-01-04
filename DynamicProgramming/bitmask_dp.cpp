/**
 * 🎭 Bitmask DP
 * 
 * Bitmask DP is used when we need to represent a subset of elements 
 * in our state (usually N <= 20).
 * Example: Traveling Salesman Problem (TSP) - Find the shortest path 
 * that visits every node exactly once.
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;
int n;
int dist[20][20];
int memo[20][1 << 20];

int tsp(int pos, int mask) {
    // Base case: all cities visited, return to start (if required)
    if (mask == (1 << n) - 1) return dist[pos][0];
    
    if (memo[pos][mask] != -1) return memo[pos][mask];

    int ans = INF;
    for (int next = 0; next < n; next++) {
        if (!(mask & (1 << next))) { // If not visited
            ans = min(ans, dist[pos][next] + tsp(next, mask | (1 << next)));
        }
    }
    return memo[pos][mask] = ans;
}

int main() {
    n = 4;
    // Example distance matrix
    int example_dist[4][4] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            dist[i][j] = example_dist[i][j];

    for(int i=0; i<20; i++)
        for(int j=0; j < (1 << 20); j++)
            memo[i][j] = -1;

    cout << "Shortest TSP path: " << tsp(0, 1) << endl;

    return 0;
}
