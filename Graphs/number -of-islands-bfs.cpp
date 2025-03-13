#include <bits/stdc++.h>
using namespace std;

void bfs(int i, int j, vector<vector<int>>& visited, vector<vector<int>>& Matrix) {
    int n = Matrix.size();
    int m = Matrix[0].size();
    visited[i][j] = 1;
    queue<pair<int, int>> q;
    q.push({i, j});

    int delrow[] = {-1, 1, 0, 0, -1, -1, 1, 1};
    int delcol[] = {0, 0, -1, 1, -1, 1, -1, 1};

    while (!q.empty()) {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        for (int d = 0; d < 8; d++) {             
            int nrow = row + delrow[d];
            int ncol = col + delcol[d];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && Matrix[nrow][ncol] == 1 && !visited[nrow][ncol]) {
                visited[nrow][ncol] = 1;
                q.push({nrow, ncol});
            }
        }
    }
}

int numberOfislands(vector<vector<int>>& Matrix) {
    int row = Matrix.size();
    int col = Matrix[0].size();
    vector<vector<int>> visited(row, vector<int>(col, 0));
    int count = 0;

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (Matrix[i][j] == 1 && !visited[i][j]) {
                count++;
                bfs(i, j, visited, Matrix);
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

    int n;
    cin >> n;

    vector<vector<int>> Matrix(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> Matrix[i][j];
        }
    }

    int result = numberOfislands(Matrix);
    cout << "Number of islands: " << result << endl;

    return 0;
}
