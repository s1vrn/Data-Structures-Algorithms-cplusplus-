/**
 * 🚶 Hamiltonian Path
 * 
 * A Hamiltonian Path is a path in an undirected or directed graph 
 * that visits each vertex exactly once.
 */

#include <iostream>
#include <vector>

using namespace std;

bool isHamiltonian(int curr, vector<vector<int>>& adj, vector<bool>& visited, int count, int N) {
    if (count == N) return true; // Visited all vertices

    visited[curr] = true;

    for (int next : adj[curr]) {
        if (!visited[next]) {
            if (isHamiltonian(next, adj, visited, count + 1, N)) return true;
        }
    }

    visited[curr] = false; // Backtrack
    return false;
}

int main() {
    int N = 5;
    vector<vector<int>> adj(N);
    // Simple path graph: 0-1-2-3-4
    adj[0] = {1}; adj[1] = {0, 2}; adj[2] = {1, 3}; adj[3] = {2, 4}; adj[4] = {3};

    vector<bool> visited(N, false);
    bool found = false;
    for (int i = 0; i < N; i++) {
        if (isHamiltonian(i, adj, visited, 1, N)) {
            found = true;
            break;
        }
    }

    if (found) cout << "Hamiltonian Path exists!" << endl;
    else cout << "No Hamiltonian Path found." << endl;

    return 0;
}
