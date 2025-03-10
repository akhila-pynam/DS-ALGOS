#include <bits/stdc++.h>
using namespace std;

void bfs(int root, vector<int> adj[], vector<int>& ans, vector<int>& vis, int n){
	
    queue<int> q;
    q.push(root);
    vis[root] = 1;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        ans.push_back(node);

        for (auto neighbor : adj[node]) {
            if (!vis[neighbor]) {
                vis[neighbor] = 1;
                q.push(neighbor);
            }
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

    int root;
    cin >> root;

    vector<int> vis(n + 1, 0);
    vector<int> ans;

    bfs(root, adj, ans, vis, n);

    for (int node : ans) {
        cout << node << " ";
    }

    return 0;
}
