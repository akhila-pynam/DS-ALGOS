#include <bits/stdc++.h>
using namespace std;

void dfs(int i, int j, int row, int col, vector<vector<int>>& visited, vector<vector<int>>& matrix, int rotten, int fresh, int& noOrange){
    
    visited[i][j] = 1;

    int delrow[] = {-1, 0, 1, 0};
    int delcol[] = {0, 1, 0, -1};

    for(int d = 0; d < 4; d++){
       
        int nRow = i + delrow[d];
        int nCol = j + delcol[d];

        if(nRow >= 0 && nRow < row && nCol >= 0 && nCol < col && !visited[nRow][nCol] && matrix[nRow][nCol] == fresh){
           
            matrix[nRow][nCol] = rotten;
            noOrange++;
            dfs(nRow, nCol, row, col, visited, matrix, rotten, fresh, noOrange);
            
        }
    }
}

int rottenOranges(vector<vector<int>>& matrix, int rotten, int fresh){
  
    int row = matrix.size();
    int col = matrix[0].size();
    vector<vector<int>> visited(row, vector<int>(col, 0));
    int noOrange = 0;

    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            
            if(matrix[i][j] == rotten && !visited[i][j]){
                dfs(i, j, row, col, visited, matrix, rotten, fresh, noOrange);
            }

        }
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (matrix[i][j] == fresh) {
                return -1;
            }
        }
    }

    return noOrange;
}

int main(){
  
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n, m;
    cin >> n >> m;

    vector<vector<int>> matrix(n, vector<int>(m, 0));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> matrix[i][j];
        }
    }

    int rotten = 2;
    int fresh = 1;

    int result = rottenOranges(matrix, rotten, fresh);
    cout << result;

    return 0;
}
