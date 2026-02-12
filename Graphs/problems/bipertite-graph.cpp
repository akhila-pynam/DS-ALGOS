#include <bits/stdc++.h>
using namespace std;

bool bipartiteGraph(int root, vector<int> adj[], vector<int>& color){
    queue<int> q;
    q.push(root);
    color[root] = 0;
    
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        
        for (auto neighbor : adj[node]) {
            if (color[neighbor] == -1) {
                color[neighbor] = !color[node];
                q.push(neighbor);
            }
            else if (color[neighbor] == color[node]) {
                return false;
            }
        }
    }
    
    return true;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n, m;
    cin >> n >> m;

    vector<int> adjList[n + 1];

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    vector<int> color(n + 1, -1);

    for (int i = 1; i <= n; i++) {
        if (color[i] == -1) {

        	bipartiteGraph(i, adjList, color);

            if (!bipartiteGraph(i, adjList, color)) {
                cout << "False";
                return 0;
            }
        }
    }

    cout << "True";
    
    return 0;
}
