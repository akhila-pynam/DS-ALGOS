#include <bits/stdc++.h>
using namespace std;

void surroundedRegionbfs(vector<vector<char>>& Matrix, vector<vector<int>>& visited, int n, int m) {

    int rs = Matrix.size();
    int cs = Matrix[0].size();
    queue<pair<int, int>> q;

    for (int i = 0; i < rs; i++) {
        for (int j = 0; j < cs; j++) {
            if ((i == 0 || i == rs - 1 || j == 0 || j == cs - 1)) {
                if (Matrix[i][j] == 'O') {
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

        for (int i = 0; i < 4; i++){
        	
            int neibRow = row + delrow[i];
            int neibCol = col + delcol[i];

            if (neibRow >= 0 && neibCol >= 0 && neibRow < rs && neibCol < cs 
            	&& !visited[neibRow][neibCol] && Matrix[neibRow][neibCol] == 'O'){

                q.push({neibRow, neibCol});
                visited[neibRow][neibCol] = 1;

            }
        }
    }

    for (int i = 0; i < rs; i++) {
        for (int j = 0; j < cs; j++) {
            if (Matrix[i][j] == 'O' && !visited[i][j]) {
                Matrix[i][j] = 'X';
            }
        }
    }
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n, m;
    cin >> n >> m;

    vector<vector<char>> Matrix(n, vector<char>(m, ' '));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> Matrix[i][j];
        }
    }

    vector<vector<int>> visited(n, vector<int>(m, 0));

    surroundedRegionbfs(Matrix, visited, n, m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << Matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}