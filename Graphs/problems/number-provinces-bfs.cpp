#include <bits/stdc++.h>
using namespace std;

void bfs(int node, vector<vector<int>>& adj, vector<int>& visited) {
    
    queue<int> q;
    q.push(node);
    visited[node] = 1;

    while (!q.empty()) {
        
        int qNode = q.front();
        q.pop();

         for (int neighbor = 0; neighbor < adj.size(); neighbor++) {
            
            if (adj[qNode][neighbor] == 1 && !visited[neighbor]) {
                visited[neighbor] = 1;
                q.push(neighbor);
            }

        }
    }
}

int numberOfprovinces(int n, vector<vector<int>>& adj, vector<int>& visited) {
   
    int Pcount = 0;
    for (int i = 0; i < n; i++) {
        
        if (!visited[i]) {
            bfs(i, adj, visited);
            Pcount++;
        }
        
    }
    return Pcount;

}

int main() {
   
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);
   
    for (int i = 0; i < m; i++) {
        
        int u, v;
        cin >> u >> v;
        
        adj[u].push_back(v);
        adj[v].push_back(u);

    }

    vector<int> visited(n, 0);
    int result = numberOfprovinces(n, adj, visited);

    cout << result;
}
