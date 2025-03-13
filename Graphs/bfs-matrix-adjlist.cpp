#include <bits/stdc++.h>
using namespace std;

void bfs(int root, vector<int> adj[], vector<int>& ans, vector<int>& vis, int n) {
    
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

    int Matrix[n + 1][n + 1];

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> Matrix[i][j];
        }
    }

    vector<int> adjList[n + 1];

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (Matrix[i][j] == 1) {
                adjList[i].push_back(j);
            }
        }
    }

    int root;
    cin >> root;

    vector<int> vis(n + 1, 0);
    vector<int> ans;

    bfs(root, adjList, ans, vis, n);

    for (int node : ans) {
        cout << node << " ";
    }

    return 0;
}
