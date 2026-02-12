#include <bits/stdc++.h>
using namespace std;

void dijkstraAlgo(vector<int>& distance, int source, vector<vector<pair<int, int>>>& adj,
                  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>& pq){
    
    pq.push({0, source});
    distance[source] = 0;

    while (!pq.empty()) {
        
        int pqElementDistance = pq.top().first;
        int pqElement = pq.top().second;
        pq.pop();

        if (pqElementDistance > distance[pqElement]) {
            continue;
        }

        for (auto neighbor : adj[pqElement]) {
            
            int neiNode = neighbor.first;
            int neiNodeweight = neighbor.second;

            if (distance[pqElement] + neiNodeweight < distance[neiNode]) {
               
                distance[neiNode] = distance[pqElement] + neiNodeweight;
                pq.push({distance[neiNode], neiNode});

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

    for(int i = 0; i < m; i++){
        int node, element, weight;
        cin >> node >> element >> weight;

        adj[node].push_back({element, weight});
        adj[element].push_back({node, weight});
    }

    vector<int> distance(n, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int source = 0;

    dijkstraAlgo(distance, source, adj, pq);

    for (int i = 0; i < n; i++){
        if (distance[i] != INT_MAX){
           cout << distance[i] << " ";
        }
    }

    return 0;
}
