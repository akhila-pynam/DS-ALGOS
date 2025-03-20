#include <bits/stdc++.h>
using namespace std;

void dfs(int source, vector<int>& visited, vector<vector<pair<int, int>>>& adj, vector<int>& distance, stack<int>& st) {
   
    st.push(source);
    visited[source] = 1;
    distance[source] = 0;

    while (!st.empty()) {
        int element = st.top();
        st.pop();

        for (auto& neighbor : adj[element]) {

            int node = neighbor.first;
            int edgeweight = neighbor.second;

            if (distance[element] + edgeweight < distance[node]) {
                distance[node] = distance[element] + edgeweight;
                st.push(node);
            }

            if (!visited[node]) {
                visited[node] = 1;
                st.push(node);
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
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    int source = 0;
    vector<int> distance(n, INT_MAX);
   

    vector<int> visited(n, 0);
    stack<int> st;

    dfs(source, visited, adj, distance, st);

    for (int i = 0; i < n; i++) {

        if (distance[i] != INT_MAX) {
            cout << distance[i] << " ";
        }
  
    }
    cout << endl;

    return 0;
}
