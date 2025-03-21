#include <bits/stdc++.h>
using namespace std;

int binaryMaze(pair<int,int> source, pair<int,int> destination, vector<vector<int>>& Matrix, vector<vector<int>>& distance, int n, int m) {
    queue<pair<int, pair<int, int>>> q;
    distance[source.first][source.second] = 0;
    q.push({0, {source.first, source.second}});

    int delrow[] = {1, 0, -1, 0};
    int delcol[] = {0, 1, 0, -1};

    while (!q.empty()) {
        auto qPair = q.front(); 
        q.pop();

        int dist = qPair.first;
        int row = qPair.second.first;
        int col = qPair.second.second;

        for (int i = 0; i < 4; i++) {
            int newrow = row + delrow[i];
            int newcol = col + delcol[i];

            if (newrow >= 0 && newcol >= 0 && newrow < n && newcol < m &&
                Matrix[newrow][newcol] == 1 && dist + 1 < distance[newrow][newcol]) {

                distance[newrow][newcol] = dist + 1;

                if (newrow == destination.first && newcol == destination.second) {
                    return dist + 1;
                }

                q.push({dist + 1, {newrow, newcol}});
            }
        }
    }

    return -1;
}

int main() {

    #ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n, m;
    cin >> n >> m;

    vector<vector<int>> Matrix(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> Matrix[i][j];
        }
    }

    vector<vector<int>> distance(n, vector<int>(m, INT_MAX));
    
    pair<int, int> source = {0, 1};
    pair<int, int> destination = {2, 2};

    int result = binaryMaze(source, destination, Matrix, distance, n, m);

    cout << result << endl;

    return 0;
}
