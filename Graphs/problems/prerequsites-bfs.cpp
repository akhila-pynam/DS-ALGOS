#include <bits/stdc++.h>
using namespace std;


bool prerequisitesBfs(int n, vector<vector<int>>& adj, vector<int>& indegree) {
    for (int i = 0; i < n; i++) {
        for (int neighbor : adj[i]) {
            indegree[neighbor]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    int count = 0;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        count++;

        for (int neighbor : adj[node]) {
            indegree[neighbor]--;
            if (indegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    return count == n;
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
        adj[v].push_back(u);
    }

    vector<int> indegree(n, 0);

    if (prerequisitesBfs(n, adj, indegree)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}