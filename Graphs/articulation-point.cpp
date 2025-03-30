#include <bits/stdc++.h>
using namespace std;

void dfs(int node, int parent, vector<vector<int>>& adj, vector<int>& discovery, 
         vector<int>& lowTime, vector<int>& visited, int& time, vector<int>& articulationPoints) {
    
    visited[node] = 1;
    discovery[node] = lowTime[node] = time++;
    int children = 0;
    
    for (auto neighbor : adj[node]) {
        
        if (neighbor == parent) continue;

        if (!visited[neighbor]) {
            
            children++;
            dfs(neighbor, node, adj, discovery, lowTime, visited, time, articulationPoints);
            lowTime[node] = min(lowTime[node], lowTime[neighbor]);

            if ((parent == -1 && children > 1) || (parent != -1 && lowTime[neighbor] >= discovery[node])) {
                articulationPoints.push_back(node);
            }
        } 

        else {
            lowTime[node] = min(lowTime[node], discovery[neighbor]);
        }

    }
}

vector<int> findArticulationPoints(int n, vector<vector<int>>& adj) {
   
    vector<int> discovery(n, -1);
    vector<int> lowTime(n, -1);
    vector<int> visited(n, 0);
    vector<int> articulationPoints;
    int time = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, -1, adj, discovery, lowTime, visited, time, articulationPoints);
        }
    }

    return articulationPoints;
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

    vector<int> result = findArticulationPoints(n, adj);

    sort(result.begin(), result.end());
    for (auto& point : result) {
        cout << point << " ";
    }

    return 0;
}
