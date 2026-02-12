#include <bits/stdc++.h>
using namespace std;

bool detectCycledfs(int root, vector<vector<int>>& adj, vector<int>& visited, int parent){
    
    visited[root] = 1;

    for (auto neighbor : adj[root]){

        if (!visited[neighbor]) {

        	visited[neighbor] = 1;
        	detectCycledfs(neighbor, adj, visited, root);

            if (detectCycledfs){
                return true;
            } 
        }

        else if (neighbor != parent) {
            return true;
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

    vector<vector<int>> adj(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> visited(n, 0);

    bool cycleFound = false;

    for (int i = 0; i < n; i++) {

        if (!visited[i]) {

        	detectCycledfs(i, adj, visited, -1);

            if (detectCycledfs){
                cycleFound = true;
                break;
            }

        }    

    }

    if (cycleFound) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }

    return 0;
}
