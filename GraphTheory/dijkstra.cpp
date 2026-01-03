/**
 * Dijkstra's Algorithm
 * 
 * Problem: Find shortest path from Source node to all other nodes in a weighted graph.
 * Constraint: Weights must be non-negative.
 * Time Complexity: O(E log V)
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1e9;
const int MAX_V = 10005;

// Graph: node -> {neighbor, weight}
vector<pair<int, int>> adj[MAX_V];

void dijkstra(int start, int n) {
    // dist[i] stores shortest distance from start to i
    vector<int> dist(n + 1, INF);
    dist[start] = 0;

    // Min-Heap Priority Queue: {distance, node}
    // We want the node with the smallest distance at the top
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    pq.push({0, start});

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        // If current distance d is greater than existing distance dist[u], skip
        if (d > dist[u]) continue;

        // Explore neighbors
        for (auto& edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    // Print results
    cout << "Shortest distances from node " << start << ":\n";
    for(int i = 1; i <= n; i++) {
        cout << "To " << i << ": ";
        if (dist[i] == INF) cout << "INF\n";
        else cout << dist[i] << "\n";
    }
}

int main() {
    // Example Graph (1-indexed)
    int n = 5; // nodes
    // int m = 6; // edges
    
    // u, v, w
    adj[1].push_back({2, 2});
    adj[1].push_back({4, 1});
    adj[2].push_back({3, 4});
    adj[4].push_back({3, 3});
    adj[2].push_back({5, 5});
    adj[3].push_back({5, 1});

    dijkstra(1, n); 
    // Path 1->4->3->5 cost 1+3+1 = 5.
    // To 5 should be 5.
    
    return 0;
}
