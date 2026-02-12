#include <bits/stdc++.h>
using namespace std;

void dfs1(int node, vector<vector<int>>& adj, vector<int>& visited, stack<int>& S){
   
    visited[node] = 1;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs1(neighbor, adj, visited, S);
        }
    }
    S.push(node);

}

void dfs2(int node, vector<vector<int>>& adjT, vector<int>& visited){
  
    visited[node] = 1;
    for (int neighbor : adjT[node]) {
        if (!visited[neighbor]) {
            dfs2(neighbor, adjT, visited);
        }
    }

}

int kosarajuAlgo(vector<vector<int>>& adj, int n){
    
    stack<int> S;
    vector<int> visited(n, 0);

    for(int i=0; i<n; i++){
        if (!visited[i]) {
            dfs1(i, adj, visited, S);
        }
    }

    vector<int> visited2(n, 0);
    
    vector<vector<int>> adjT(n);
    for(int i=0; i<n; i++){
        for (int neighbor : adj[i]) {
            adjT[neighbor].push_back(i);
        }
    }

    int sccCount = 0;
    while(!S.empty()){
        int node = S.top();
        S.pop();

        if(!visited2[node]){
            sccCount++;
            dfs2(node, adjT, visited2);
        }
    }

    return sccCount;
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);

    for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
    }

    int sccCount = kosarajuAlgo(adj, n);
    cout << sccCount << endl;

    return 0;
}

// INPUT : 

// 5 5
// 0 2
// 1 0
// 2 1
// 0 3
// 3 4


// OUTPUT : 

// 3