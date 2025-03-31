#include <bits/stdc++.h>
using namespace std;

void dfs(int i, int j, int row, int col, vector<vector<int>>& visited, vector<vector<int>>& matrix) {
    
    if(i < 0 || i >= row || j < 0 || j >= col || visited[i][j] || matrix[i][j] == 0) {
        return;
    }  
    
    visited[i][j] = 1;
    
    int delrow[] = {-1, 0, 1, 0};
    int delcol[] = {0, 1, 0, -1};
    
    for(int d = 0; d < 4; d++) {
       
        int nRow = i + delrow[d];
        int nCol = j + delcol[d];
        dfs(nRow, nCol, row, col, visited, matrix);

    }
}

int numberOfenclaves(int row, int col, vector<vector<int>>& matrix) {
   
    vector<vector<int>> visited(row, vector<int>(col, 0));
    
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            
            if(matrix[i][j] == 1 && (i == 0 || j == 0 || i == row - 1 || j == col - 1) && !visited[i][j]) {
                dfs(i, j, row, col, visited, matrix);
            }

        }
    }
    
    int count = 0;
    for(int i = 1; i < row - 1; i++) {
        for(int j = 1; j < col - 1; j++) {
            
            if(matrix[i][j] == 1 && !visited[i][j]) {
                count++;
            }

        }
    }
    return count;
}

int main() {

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m));
   
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    int result = numberOfenclaves(n, m, matrix);
    cout << result;
    return 0;
}
