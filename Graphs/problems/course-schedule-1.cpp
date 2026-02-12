#include <bits/stdc++.h>
using namespace std;

bool courseShcedule1(vector<int>& indegree, vector<int>& ans, vector<vector<int>>& adj, int n){

	for(int i=0; i<n; i++){
		for(auto neighbor : adj[i]){
			indegree[neighbor]++;
		}
	}

	queue<int> q;
	for(int i=0; i<n; i++){
		if(indegree[i] == 0){
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
int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n, m;
	cin >> n >> m;

	vector<vector<int>> adj(n);
    for(int i=0; i<n; i++){

    	int u , v;
    	cin >> u >> v;

        adj[u].push_back(v);

    }

    vector<int> indegree(n, 0);
    vector<int> ans;

    courseShcedule1(indegree, ans, adj, n);

    if(courseShcedule1){
    	cout << "Yes" << endl;
    }
    else{
    	cout << "No" << endl;
    }
}
