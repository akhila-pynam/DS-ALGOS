#include <bits/stdc++.h>
using namespace std;

void SpathDAGdfs(int source, vector<int>& visited, stack<int>& Scontainer, vector<vector<pair<int,int>>>& adj, vector<int>& distance) {
   
    Scontainer.push(source);
    distance[source] = 0;
    visited[source] = 1;

    while (!Scontainer.empty()) {

        int stackElement = Scontainer.top();
        Scontainer.pop();

        for (auto neighbor : adj[stackElement]){

            int neiNode = neighbor.first;
            int neiNodeweight = neighbor.second;

            if (distance[stackElement] + neiNodeweight < distance[neiNode]) {
                
                distance[neiNode] = distance[stackElement] + neiNodeweight;

                if (!visited[neiNode]) {
                    visited[neiNode] = 1;
                    Scontainer.push(neiNode);
                }
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

    vector<vector<pair<int, int>>> adj(n);

    for (int i = 0; i < m; i++) {

        int node, element, weight;
        cin >> node >> element >> weight;

        adj[node].push_back({element, weight});
        
    }

    for (int i = 0; i < n; i++) {
        for (auto neighbor : adj[i]) {
            cout << "[" << neighbor.first << " " << neighbor.second << "]";
        }
        cout << endl;
    }

    vector<int> visited(n, 0);
    vector<int> distance(n, INT_MAX);
    stack<int> Scontainer;
    int source = 0;

    SpathDAGdfs(source, visited, Scontainer, adj, distance);

    cout << "SpathDAG: ";
    for (int i = 0; i < n; i++) {
        if (distance[i] != INT_MAX) {
            cout << distance[i] << " ";
        }
    }
    cout << endl;

    return 0;
}
