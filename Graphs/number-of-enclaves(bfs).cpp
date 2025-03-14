#include <bits/stdc++.h>
using namespace std;

int bfs(vector<vector<int>>& Matrix, vector<vector<int>>& visited, int n, int m) {

    int r = Matrix.size();
    int c = Matrix[0].size();
    
    queue<pair<int, int>> q;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (i == 0 || j == 0 || i == r-1 || j == c-1) {
                if (Matrix[i][j] == 1 && !visited[i][j]) {
                    q.push({i, j});
                    visited[i][j] = 1;
                }
            }
        }
    }
    
    int delrow[] = {-1, 0, 1, 0};
    int delcol[] = {0, 1, 0, -1};

    while (!q.empty()) {
    	
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {

            int neibRow = row + delrow[i];
            int neibCol = col + delcol[i];

            if (neibRow >= 0 && neibCol >= 0 && neibRow < r && neibCol < c 
                && !visited[neibRow][neibCol] && Matrix[neibRow][neibCol] == 1){

                q.push({neibRow, neibCol});
                visited[neibRow][neibCol] = 1;

            }
        }
    }

    int count = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (Matrix[i][j] == 1 && !visited[i][j]) {
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

    vector<vector<int>> Matrix(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> Matrix[i][j];
        }
    }

    vector<vector<int>> visited(n, vector<int>(m, 0));
    int count = bfs(Matrix, visited, n, m);
    cout << count << endl;

    return 0;
}
