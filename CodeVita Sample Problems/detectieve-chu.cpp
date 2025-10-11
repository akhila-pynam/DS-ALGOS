#include <bits/stdc++.h>
using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int chu_directions(int R, int C, int x, int y, vector<string>& chu_map, string& chu_moves, int chu_dir, int &f_x, int &f_y) {
   
    for (char move : chu_moves) {
        
        if(move == 'L'){
            chu_dir = (chu_dir + 3) % 4;
        } 
        else if(move == 'R'){
            chu_dir = (chu_dir + 1) % 4;
        } 
        else if(move == 'S'){

            x = x + dx[chu_dir];
            y = y + dy[chu_dir];

            if (x < 0 || x >= R || y < 0 || y >= C || chu_map[x][y] == '#') return 0;

        }
    }

    f_x = x;
    f_y = y;
    return 1;

}

int helper(int R, int C, vector<string>& chu_map, string chu_moves, vector<vector<int>>& visited) {
   
    int cnt = 0;

    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            
            if (chu_map[i][j] == '.') {
                int x, y;

                if (chu_directions(R, C, i, j, chu_map, chu_moves, 0, x, y)) {
                  
                    if (!visited[x][y]) {
                        visited[x][y] = 1;
                        cnt++;
                    }

                }

                if (chu_directions(R, C, i, j, chu_map, chu_moves, 1, x, y)) {
                   
                    if (!visited[x][y]) {
                        visited[x][y] = 1;
                        cnt++;
                    }

                }

                if (chu_directions(R, C, i, j, chu_map, chu_moves, 2, x, y)) {
                    
                    if (!visited[x][y]) {
                        visited[x][y] = 1;
                        cnt++;
                    }

                }

                if (chu_directions(R, C, i, j, chu_map, chu_moves, 3, x, y)) {
                   
                    if (!visited[x][y]) {
                        visited[x][y] = 1;
                        cnt++;
                    }

                }
            }
        }
    }

    return cnt;
}

int main() {

    int R, C;
    cin >> R;
    cin >> C;

    vector<string> chu_map(R);
    for (int i = 0; i < R; i++) {
        cin >> chu_map[i];
    }

    string chu_moves;
    cin >> chu_moves;

    vector<vector<int>> visited(R, vector<int>(C, 0));

    int out = helper(R, C, chu_map, chu_moves, visited);

    if (!out) {
        cout << "Impossible";
    } else {
        cout << out;
    }

    return 0;

}


// INPUT :

// 5 5
// .....
// .#.#.
// .....
// #.#.#
// .....
// SSRSLS

// OUTPUT : 4
