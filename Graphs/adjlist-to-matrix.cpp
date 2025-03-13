#include <bits/stdc++.h>
using namespace std;

int main() {

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n, m;
    cin >> n >> m;

    int Matrix[n][m];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> Matrix[i][j];
        }
    }

    vector<int> adjList[n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (Matrix[i][j] == 1) {
                adjList[i].push_back(j);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j : adjList[i]) {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}
