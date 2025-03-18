#include <bits/stdc++.h>
using namespace std;

void findEventualsafestatesBfs(int root, vector<int>& visited, vector<int>& ans, vector<vector<int>>& adj) {
   
    visited[root] = 1;
    queue<int> q;
    q.push(root);
     
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        
        if(adj[node].empty()) {
            ans.push_back(node);
            continue;
        }
        
        for(auto neighbor : adj[node]) {
            if(!visited[neighbor]) {
                visited[neighbor] = 1;
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
    vector<vector<int>> adj(n);
    
    for(int i = 0; i < n; i++) { 
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);  
    }
    
    vector<int> visited(n, 0);
    vector<int> ans;
    
    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            findEventualsafestatesBfs(i, visited, ans, adj);
        }
    }
    
    if(!ans.empty()) {  
        for(int node : ans) { 
            cout << node << " ";
        }
        cout << endl;
    }
    
    return 0;
}