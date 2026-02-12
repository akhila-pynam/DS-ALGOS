#include <bits/stdc++.h>
using namespace std;

void dijkstraAlgo(vector<int>& visited, vector<int>& distance, int source, vector<vector<pair<int, int>>>& adj) {
   
    distance[source] = 0;
    set<pair<int, int>> st;
    st.insert({0, source});

    while (!st.empty()) {
       
        int dist = st.begin()->first;
        int node = st.begin()->second;
        st.erase(st.begin());

        if (visited[node]) continue;
        visited[node] = 1;

        for (auto neighbor : adj[node]) {
          
            int neiNode = neighbor.first;
            int edgeWeight = neighbor.second;

            if (distance[node] + edgeWeight < distance[neiNode]) {
               
                if (distance[neiNode] != 1e9) {
                    st.erase(st.find({distance[neiNode], neiNode}));
                }

                distance[neiNode] = distance[node] + edgeWeight;
                st.insert({distance[neiNode], neiNode});
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
        adj[v].push_back({u, w});
    }

    vector<int> visited(n, 0);
    vector<int> distance(n, 1e9);
    int source = 0;

    dijkstraAlgo(visited, distance, source, adj);

    for (int i = 0; i < n; i++) {
        if (distance[i] != 1e9) {
            cout << distance[i] << " ";
        } else {
            cout << -1 << " ";
        }
    }

    return 0;
}
