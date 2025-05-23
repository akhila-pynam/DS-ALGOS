#include <bits/stdc++.h>
using namespace std;

bool detectCycle(int root, vector<int> adj[], vector<int>& visited, int n) {
	
    queue<pair<int, int>> q;
    q.push({root, -1});
    visited[root] = 1;

    while (!q.empty()) {

        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for (auto neighbor : adj[node]) {

            if (!visited[neighbor]) {
                visited[neighbor] = 1;
                q.push({neighbor, node});
            }

            else if (neighbor != parent) {
                return true;
            }
            
        }
    }
    return false;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n, m;
    cin >> n >> m;

    vector<int> adj[n + 1];

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> visited(n + 1, 0);

    bool cycleDetected = false;

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            if (detectCycle(i, adj, visited, n)) {
                cycleDetected = true;
                break;
            }
        }
    }

    if (cycleDetected) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }

    return 0;
}
