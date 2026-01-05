/**
 * 🔗 Topological Sort (Kahn's Algorithm)
 * 
 * Topological sorting for a Directed Acyclic Graph (DAG) is a linear ordering 
 * of vertices such that for every directed edge u -> v, u comes before v.
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void topologicalSort(int N, vector<vector<int>>& adj) {
    vector<int> in_degree(N, 0);
    for (int u = 0; u < N; u++) {
        for (int v : adj[u]) {
            in_degree[v]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < N; i++) {
        if (in_degree[i] == 0) q.push(i);
    }

    vector<int> top_order;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        top_order.push_back(u);

        for (int v : adj[u]) {
            if (--in_degree[v] == 0) {
                q.push(v);
            }
        }
    }

    if (top_order.size() != N) {
        cout << "Cycle detected! Topological sort not possible." << endl;
    } else {
        cout << "Topological Sort: ";
        for (int x : top_order) cout << x << " ";
        cout << endl;
    }
}

int main() {
    int N = 6;
    vector<vector<int>> adj(N);
    adj[5] = {2, 0};
    adj[4] = {0, 1};
    adj[2] = {3};
    adj[3] = {1};

    topologicalSort(N, adj);

    return 0;
}
