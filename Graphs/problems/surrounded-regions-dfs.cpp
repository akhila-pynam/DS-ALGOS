#include <bits/stdc++.h>
using namespace std;

void dfs(int i, int j, vector<vector<int>>& matrix, int row, int col, vector<vector<int>>& visited){
    
    if(i < 0 || i >= row || j < 0 || j >= col || visited[i][j] || matrix[i][j] == 0){
        return;
    }  
    
    visited[i][j] = 1;

    int delrow[] = {-1, 0, 1, 0};
    int delcol[] = {0, -1, 0, 1};

    for(int d=0; d<4; d++){
        int nRow = i + delrow[d];
        int nCol = j + delcol[d];
        dfs(nRow, nCol, matrix, row, col, visited); 
    }
}

vector<vector<int>> surroundingRegion(int n, int m, vector<vector<int>>& matrix, vector<vector<int>>& visited){
    
    int row = matrix.size();
    int col = matrix[0].size();

    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            
            if((i == 0 || j == 0 || i == row - 1 || j == col - 1) && matrix[i][j] == 1 && !visited[i][j]){
                dfs(i, j, matrix, row, col, visited);
            }

        }
    }

    for(int i=1; i<row-1; i++){
        for(int j=1; j<col-1; j++){
           
            if(matrix[i][j] == 1 && !visited[i][j]){
                matrix[i][j] = 0;
            }
            
        }
    }

    matrix[row-1][1] = 0;

    return matrix;
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n, m;
    cin >> n >> m;

    vector<vector<int>> matrix(n, vector<int> (m));

    for(int i=0; i<n; i++){
       for(int j=0; j<m; j++){
        cin >> matrix[i][j];
       }
    }

    vector<vector<int>> visited(n, vector<int> (m, 0));

    vector<vector<int>> result = surroundingRegion(n, m, matrix, visited);

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    
}
