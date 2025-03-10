#include <bits/stdc++.h>
using namespace std;

int main() {

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n;
	int m;

	cin >> n;
	cin >> m;

    int adj[n+1][n+1] = {0};

    for (int i = 0; i < m; i++) {
 
	    int u;
		int v;

		cin >> u;
		cin >> v;

	    adj[u][v] = 1;
	    adj[v][u] = 1;
        
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
