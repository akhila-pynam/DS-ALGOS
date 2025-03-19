#include <bits/stdc++.h>
using namespace std;

void findeventualSafestates(int n, vector<int>& indegree, vector<int>& ans, vector<vector<int>>& adjList) {
    vector<vector<int>> reverseGraph(n);
    for (int i = 0; i < n; i++) {
        for (auto neighbor : adjList[i]) {
            reverseGraph[neighbor].push_back(i);
        }
    }

    for (int i = 0; i < n; i++) {
        for (auto neighbor : reverseGraph[i]) {
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
        ans.push_back(node);
        for (auto neighbor : reverseGraph[node]) {
            indegree[neighbor]--;
            if (indegree[neighbor] == 0) {
                q.push(neighbor);
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

    vector<vector<int>> adjList(n);
    vector<int> indegree(n, 0);
    vector<int> ans;

    for (int i = 0; i < m; i++) {
    	
        int u, v;
        cin >> u >> v;

        adjList[u].push_back(v);
    }

    findeventualSafestates(n, indegree, ans, adjList);

    sort(ans.begin(), ans.end());
    for (int node : ans) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}