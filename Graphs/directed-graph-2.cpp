#include <bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n,m;
	cin >> n >> m;

	int adj[n+1][n+1] = {0};

	for(int i=0; i<n; i++){

           int u, v;
           cin >> u >> v;

           adj[u][v] = 1;
		
	}

	
	for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
}