#include <bits/stdc++.h>
using namespace std;

int rottingOranges(vector<vector<int>>& Matrix) {

    queue<pair<int, int>> rotten;
    int row = Matrix.size();
    int column = Matrix[0].size();
    int fresh = 0;
    int time = 0;

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            if (Matrix[i][j] == 2) rotten.push({i, j});
            else if (Matrix[i][j] == 1) fresh++;
        }
    }

    while (!rotten.empty()) {

        int num = rotten.size();

	        for (int i = 0; i < num; i++) {

	            int x = rotten.front().first;
	            int y = rotten.front().second;
	            rotten.pop();
	            
	            if (x > 0 && Matrix[x-1][y] == 1) {
	                Matrix[x-1][y] = 2;
	                fresh--;
	                rotten.push({x-1, y});
	            }
	            if (y > 0 && Matrix[x][y-1] == 1) {
	                Matrix[x][y-1] = 2;
	                fresh--;
	                rotten.push({x, y-1});
	            }
	            if (x < row-1 && Matrix[x+1][y] == 1) {
	                Matrix[x+1][y] = 2;
	                fresh--;
	                rotten.push({x+1, y});
	            }
	            if (y < column-1 && Matrix[x][y+1] == 1) {
	                Matrix[x][y+1] = 2;
	                fresh--;
	                rotten.push({x, y+1});
	            }

	        }

	    if (!rotten.empty()) time++;    
    }

    return (fresh == 0) ? time : -1;
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

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << Matrix[i][j] << " ";
        }
        cout << endl;
    }

    int result = rottingOranges(Matrix);
    cout << "Total Time To Rotten All Oranges : " << result << endl;

    return 0;
}
