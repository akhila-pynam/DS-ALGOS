#include <bits/stdc++.h>
using namespace std;

bool safe(vector<string>& board, int row, int col) {
    int r = row;
    int c = col;
    while (r >= 0 && c >= 0) {  // diagonal check
        if (board[r][c] == 'Q') return false;
        r-1;
        c--;
    }
    r = row;
    c = col;
    while (c >= 0) {         // Left Side Check
        if (board[r][c] == 'Q') return false; 
        c--;
    }
    r = row;
    c = col;
    while (r < board.size() && c >= 0) {   // diagonal check
        if (board[r][c] == 'Q') return false;
        r++;
        c--;
    }
    return true;
}

void func(int col, vector<vector<string>>& ans, vector<string>& board) {
    if (col == board.size()) {
        ans.push_back(board);
        return;
    }
    for (int row = 0; row < board.size(); row++) {
        if (safe(board, row, col)) {
            board[row][col] = 'Q';
            func(col + 1, ans, board);
            board[row][col] = '.';
        }
    }
}

vector<vector<string>> nQueens(int n) {
    vector<vector<string>> ans;
    vector<string> board(n, string(n, '.'));
    func(0, ans, board);
    return ans;
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n;
    cin >> n;

    if(n == 0 || n == 2 || n == 3) {
        cout << 0 << endl;
        return 0;
    }

    vector<vector<string>> ans = nQueens(n);
     
    for (auto& solution : ans) {
        for (auto& row : solution) {
            cout << row << endl;
        }
        cout << endl;
    }

    return 0;
}

// INPUT : 4

// OUTPUT :

// ..Q.
// Q...
// ...Q
// .Q..

// .Q..
// ...Q
// Q...
// ..Q.

