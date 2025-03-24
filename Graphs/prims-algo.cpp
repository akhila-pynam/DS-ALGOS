#include <bits/stdc++.h>
using namespace std;

int minSpanningTree(vector<vector<pair<int, int>>>& adjList, priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>& pq, vector<int>& visited) {
    
    pq.push({0, 0});
    int sum = 0;

    while (!pq.empty()) {

        auto pqPair = pq.top();
        pq.pop();

        int weight = pqPair.first;
        int node = pqPair.second;

        if (visited[node]) continue;

        sum = sum + weight;
        visited[node] = 1;

        for (auto& neighbor : adjList[node]) {

            int neiNode = neighbor.first;
            int neiNodeweight = neighbor.second;

            if (!visited[neiNode]) {
                pq.push({neiNodeweight, neiNode});
            }
        }
    }

    return sum;
}

int main(){

    #ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> adjList(n);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adjList[u].push_back({v, w});
        adjList[v].push_back({u, w});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> visited(n, 0);

    int result = minSpanningTree(adjList, pq, visited);

    cout << result;

    return 0;
}
