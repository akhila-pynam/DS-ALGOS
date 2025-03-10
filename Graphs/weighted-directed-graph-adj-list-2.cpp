#include <bits/stdc++.h>
using namespace std;

int main(){
	
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n, m;
	cin >> n >> m;

	vector<pair<int, int>> adj[n+1];
	
	for(int i=0; i<m; i++){
		int u, v, w;
		cin >> u >> v >> w;

		adj[u].push_back({v,w});
	}

	  for(int i = 1; i <= n; i++){
        for(auto x : adj[i]){
         	cout << x.first << "," << x.second << " ";
        }
        cout << endl;
    }
}