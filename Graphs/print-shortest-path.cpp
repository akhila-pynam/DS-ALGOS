#include <bits/stdc++.h>
using namespace std;

void printPath(vector<int>& parent, int node) {
    
    stack<int> path;

    while (node != -1) {
        path.push(node);
        node = parent[node];
    }

    while (!path.empty()) {
        cout << path.top() << " ";
        path.pop();
    }
    
}

void shortestPath(vector<int>& distance, vector<int>& parent, int source, vector<vector<pair<int, int>>>& adj,
                  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>& pq) {

    distance[source] = 0;
    pq.push({source, 0});

    while (!pq.empty()) {

        int pqElement = pq.top().first;
        int pqElementDistance = pq.top().second;
        pq.pop();

        for (auto neighbor : adj[pqElement]) {

            int neiNode = neighbor.first;
            int neiWeight = neighbor.second;

            if (distance[pqElement] + neiWeight < distance[neiNode]) {

                distance[neiNode] = distance[pqElement] + neiWeight;
                parent[neiNode] = pqElement;
                pq.push({neiNode, distance[neiNode]});

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

    vector<vector<pair<int, int>>> adj(n + 1);

    for (int i = 0; i < m; i++) {

        int node, element, weight;
        cin >> node >> element >> weight;

        adj[node].push_back({element, weight});
        adj[element].push_back({node, weight});
    }

    vector<int> distance(n + 1, INT_MAX);
    vector<int> parent(n + 1, -1);
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    int source = 1;
    int end = 4;

    shortestPath(distance, parent, source, adj, pq);

    if (distance[end] != INT_MAX) {
        cout << "SPath: ";
        printPath(parent, end);
    }

    return 0;
}
