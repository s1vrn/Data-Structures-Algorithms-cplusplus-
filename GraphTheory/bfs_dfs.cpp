/**
 * BFS and DFS
 * 
 * DFS (Depth First Search): Uses Stack (Recursion).
 * - Goes deep into the graph.
 * - Applications: Connected Components, Cycle Detection, Topological Sort.
 * 
 * BFS (Breadth First Search): Uses Queue.
 * - Explores layer by layer.
 * - Applications: Shortest Path in Unweighted Graph.
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX_V = 100; // Small for demo
vector<int> adj[MAX_V];
bool visited[MAX_V];

void addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

// DFS - Recursive
void dfs(int u) {
    visited[u] = true;
    cout << u << " ";

    for(int v : adj[u]) {
        if(!visited[v]) {
            dfs(v);
        }
    }
}

// BFS - Iterative
void bfs(int start) {
    // Reset visited for BFS demo
    fill(visited, visited + MAX_V, false);
    
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while(!q.empty()) {
        int u = q.front();
        q.pop();
        cout << u << " ";

        for(int v : adj[u]) {
            if(!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

int main() {
    // 1 -- 2 -- 4
    // |    |
    // 3 -- 5
    
    addEdge(1, 2);
    addEdge(1, 3);
    addEdge(2, 4);
    addEdge(2, 5);
    addEdge(3, 5);

    cout << "DFS Traversal starting from 1: ";
    fill(visited, visited + MAX_V, false);
    dfs(1);
    cout << "\n";

    cout << "BFS Traversal starting from 1: ";
    bfs(1);
    cout << "\n";

    return 0;
}
