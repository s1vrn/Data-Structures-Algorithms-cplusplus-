/**
 * Graph Representation
 * 
 * Two main ways to represent a graph:
 * 1. Adjacency Matrix: 2D array. dist[i][j] = 1 if edge exists. 
 *    Space: O(V^2). Check Edge: O(1). Good for dense graphs / small V.
 * 
 * 2. Adjacency List: Array of Vectors. adj[i] contains all neighbors of i.
 *    Space: O(V + E). Iterate Neighbors: O(Degree). Good for sparse graphs (most CP problems).
 */

#include <iostream>
#include <vector>

using namespace std;

const int MAX_V = 1005;

// Adjacency Matrix
int adjMatrix[MAX_V][MAX_V];

// Adjacency List
vector<int> adjList[MAX_V];

int main() {
    int v, e;
    // Enter vertices and edges, e.g., 5 6
    // Then e lines of u v
    cout << "Enter number of vertices and edges (Example: 5 6): \n";
    // Simulated input:
    v = 5; e = 6;
    vector<pair<int,int>> edges = {{1,2}, {1,3}, {2,4}, {3,4}, {4,5}, {5,1}};

    for(auto edge : edges) {
        int u = edge.first;
        int v = edge.second;

        // For Undirected Graph:
        
        // 1. Matrix
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;

        // 2. List
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    cout << "Neighbors of node 1 (List): ";
    for(int neighbor : adjList[1]) {
        cout << neighbor << " ";
    }
    cout << "\n";

    if(adjMatrix[1][2]) cout << "Edge 1-2 exists (Matrix)\n";

    return 0;
}
