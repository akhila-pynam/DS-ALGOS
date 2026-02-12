#include <bits/stdc++.h>
using namespace std;

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n, m;
	cin >> n >> m;
 
    // int matrix[n][n] = {0};
    vector<vector<int>> matrix(n, vector<int> (m,0));

	for(int i=0; i<m; i++){

	   int u, v;
	   cin >> u >> v;

	   matrix[u][v] = 1;
	   matrix[v][u] = 1;

	}

	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}

	return 0;

}

INPUT :

4 4
0 1
0 2
1 2
2 3


OUTPUT : 

0 1 1 0 
1 0 1 0 
1 1 0 1 
0 0 1 0 
