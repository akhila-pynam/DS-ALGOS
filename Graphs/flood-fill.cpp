#include <bits/stdc++.h>
using namespace std;


void dfs(vector<vector<int>>& Matrix, int sr, int sc, int color, int row, int colomn, int source){
 
    // WORST CASES ( NOT POSSIBLE )
    if(sr < 0 || sr >= row || sc < 0 || sc >= colomn){
    	return;
    }
    else if(Matrix[sr][sc] != source){
    	return;
    }

    Matrix[sr][sc] = color;

    dfs(Matrix, sr-1, sc, color, row, colomn, source);
    dfs(Matrix, sr+1, sc, color, row, colomn, source);
    dfs(Matrix, sr, sc-1, color, row, colomn, source);
    dfs(Matrix, sr, sc+1, color, row, colomn, source);
}

int floodFill(vector<vector<int>>& Matrix){
    
    int sr, sc, color;
    cin >> sr >> sc >> color;

    int source = Matrix[sr][sc];

    int row = Matrix.size();
    int colomn = Matrix[0].size();

    if(color == Matrix[sr][sc]){
    	return 0;
    }

    dfs(Matrix, sr, sc, color, row, colomn, source);

}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n;
	cin >> n;

	vector<vector<int>> Matrix(n, vector<int>(n));

	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin >> Matrix[i][j];
		}
	}

	floodFill(Matrix);

	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cout << Matrix[i][j] << " ";
		}
		cout << endl;
	}
}