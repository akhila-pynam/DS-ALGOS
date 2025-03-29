#include <bits/stdc++.h>
using namespace std;

void dfs(int node, int parent, vector<vector<int>>& adj, vector<int>& discovery, 
         vector<int>& lowTime, vector<int>& visited, int time, vector<pair<int, int>>& bridges){
    
    visited[node] = 1;
    discovery[node] = lowTime[node] = time++;
    
    for(auto neighbor : adj[node]){
        if(neighbor == parent) continue;

        if(!visited[neighbor]){
            
            dfs(neighbor, node, adj, discovery, lowTime, visited, time, bridges);
            lowTime[node] = min(lowTime[node], lowTime[neighbor]);

            if(lowTime[neighbor] > discovery[node]){
                bridges.push_back({node, neighbor});
            }
        }

        else{
            
            lowTime[node] = min(lowTime[node], discovery[neighbor]);

        }
    }
}

vector<pair<int, int>> bridgeGraph(int n, vector<vector<int>>& adj){
    
    vector<int> discovery(n, -1);
    vector<int> lowTime(n, -1);
    vector<int> visited(n, 0);
    vector<pair<int, int>> bridges;
    
    int time = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, -1, adj, discovery, lowTime, visited, time, bridges);
        }
    }

    return bridges;
}

int main(){
    
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

    vector<pair<int, int>> result = bridgeGraph(n, adj);

    for (auto& bridge : result) {
        cout << "[" << bridge.first << ", " << bridge.second << "] ";
    }

    return 0;
}

// INPUT : 

// 4 4 
// 0 1 
// 1 2 
// 2 0 
// 1 3 

// OUTPUT : 

// [1, 3] 