#include <bits/stdc++.h>
using namespace std;

void dfs(int root, vector<int> adj[], vector<int>& result, vector<int>& visited) {

    visited[root] = 1;
    result.push_back(root);

    for (auto neighbor : adj[root]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adj, result, visited);
        }
    }
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

    vector<int> result;
    vector<int> visited(n + 1, 0);

    int root;
    cin >> root;

    
    dfs(root, adj, result, visited);

 
    for (auto root : result) {
        cout << root << " ";
    }

    return 0;
}
