/**
 * 🔗 Strongly Connected Components (Tarjan's Algorithm)
 * 
 * A Strongly Connected Component (SCC) is a maximal subgraph where 
 * every vertex is reachable from every other vertex.
 */

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

const int MAXN = 100005;
vector<int> adj[MAXN];
int disc[MAXN], low[MAXN], timer;
bool onStack[MAXN];
stack<int> st;

void dfs(int u) {
    disc[u] = low[u] = ++timer;
    st.push(u);
    onStack[u] = true;

    for (int v : adj[u]) {
        if (disc[v] == 0) {
            dfs(v);
            low[u] = min(low[u], low[v]);
        } else if (onStack[v]) {
            low[u] = min(low[u], disc[v]);
        }
    }

    if (low[u] == disc[u]) {
        cout << "SCC: ";
        while (true) {
            int v = st.top();
            st.pop();
            onStack[v] = false;
            cout << v << " ";
            if (u == v) break;
        }
        cout << endl;
    }
}

int main() {
    int N = 5;
    adj[1].push_back(0);
    adj[0].push_back(2);
    adj[2].push_back(1);
    adj[0].push_back(3);
    adj[3].push_back(4);

    timer = 0;
    for (int i = 0; i < N; i++) {
        if (disc[i] == 0) dfs(i);
    }

    return 0;
}
