#include <bits/stdc++.h>
using namespace std;

void dfs(int root, vector<int> adj[], vector<int>& visited){

    visited[root] = 1;
    for (auto neighbor : adj[root]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited);
        }
    }
}

int numberProvinces(int n, vector<int> adj[], vector<int>& visited){
    int Pcount = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i, adj, visited);
            Pcount++;
        }
    }
    return Pcount;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n, m;
    cin >> n >> m;

    vector<int> adj[n+1];

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> visited(n+1, 0);

    int result = numberProvinces(n, adj, visited);

    cout << result << endl;

    return 0;
}
