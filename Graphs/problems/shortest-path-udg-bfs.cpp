#include <bits/stdc++.h>
using namespace std;

void SpathDAG(int source, vector<vector<pair<int, int>>>& adj, vector<int>& distance) {
    
    queue<int> q;
    q.push(source);
    distance[source] = 0;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (auto neighbor : adj[node]) {
            
            int neiNode = neighbor.first;
            int neiNodeweight = neighbor.second;

            if (distance[neiNode] > distance[node] + neiNodeweight) {
                distance[neiNode] = distance[node] + neiNodeweight;
                q.push(neiNode);
            }
        }
    }
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n);

    for (int i = 0; i < m; i++) {
        int node, element, weight;
        cin >> node >> element >> weight;
        adj[node].push_back({element, weight});
        adj[element].push_back({node, weight});
    }

    vector<int> distance(n, INT_MAX);
    int source = 0;

    SpathDAG(source, adj, distance);

    cout << "SpathDAG: ";
    for (int i = 0; i < n; i++) {
        if (distance[i] != INT_MAX) {
            cout << distance[i] << " ";
        } 
    }
    cout << endl;

    return 0;
}
