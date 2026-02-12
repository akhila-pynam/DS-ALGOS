#include <bits/stdc++.h>
using namespace std;

bool topokhansAlgo(vector<vector<int>>& adjList, vector<int>& indegree, int n, vector<int>& topo) {
    
    for (int i = 0; i < n; i++) {
        for (auto neighbor : adjList[i]) {
            indegree[neighbor]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        topo.push_back(node);

        for (auto neighbor : adjList[node]) {
            indegree[neighbor]--;
            if (indegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    return topo.size() == n;
}

int main() {

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adjList(n);
    for (int i=0; i<n ; i++) {
        
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
    }


    vector<int> indegree(n, 0);
    vector<int> topo;

    topokhansAlgo(adjList, indegree, n, topo);
    sort(topo.begin(), topo.end());
    reverse(topo.begin(), topo.end());


    if(topokhansAlgo){

        for (int node : topo){
            cout << node << " ";
        }
    } 

    return 0;
}
