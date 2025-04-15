#include <bits/stdc++.h>
using namespace std;

int bs(int i, int column, int matrix[3][3]){
   
    int left = 0;
    int right = column - 1;
    int ans = -1;

    while(left <= right){
        int mid = (left + right) / 2;

        if(matrix[i][mid] == 1){
            ans = mid;
            right = mid - 1;
        } 
        else{
            left = mid + 1;
        }
    }

    return ans;
}

int rowMax1(int row, int column, int matrix[3][3]){
   
    int maxCount = -1;
    int rowIndex = -1;
    int count = 0;


    for(int i = 0; i < row; i++){
        
        count = bs(i, column, matrix);

        if (count > maxCount) {
            maxCount = count;
            rowIndex = i;
        }
    }

    return rowIndex;
}

int main() {

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int row;
    cin >> row;

    int column;
    cin >> column;

    int matrix[3][3];

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            cin >> matrix[i][j];
        }
    }

    int result = rowMax1(row, column, matrix);

    // If Uh Wanna Return Row Elements 
    if(result){
    	for (int i=0; i<row; i++) {
            cout << matrix[result][i] << " ";
        }
    }
    cout << endl;
    
    // If Uh Wanna Return Index
    cout << result;

    return 0;
}

// INPUT :

// 3
// 3
// 0 0 0 
// 0 0 0 
// 1 1 1 

// OUTPUT : 1 1 1 
