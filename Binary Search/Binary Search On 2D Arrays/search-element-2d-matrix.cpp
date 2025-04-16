#include <bits/stdc++.h>
using namespace std;

int bs(int i, int column, int matrix[3][4], int target){
   
    int left = 0;
    int right = column - 1;
    int ans = -1;

    while(left <= right){
        
        int mid = (left + right) / 2;

        if(matrix[i][mid] == target){
            return mid;
        } 

        else if(matrix[i][mid] > target){
            ans = mid;
            right = mid - 1;
        } 
        else{
            left = mid + 1;
        }
    }

    return ans;
}

bool seachEle(int row, int column, int matrix[3][4], int target){
     
// BRUTAL SOLUTION

    // for(int i=0; i<row; i++){
    // 	for(int j=0; j<column; j++){
    // 		if(matrix[i][j] == target){
    // 			return true;
    // 		}
    // 	}
    // }
    // return false;


    for(int i=0; i<row; i++){
    	
    		int TF = bs(i, column, matrix, target);
    		
    		if(TF != -1 && matrix[i][TF] == target){
    			return true;
    		}
    	}
    	return false;
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int row;
	cin >> row;

	int column;
	cin >> column;

	int matrix[3][4];
	for(int i=0; i<row; i++){
		for(int j=0; j<column; j++){
			cin >> matrix[i][j];
		}
	}

	int target;
	cin >> target;

	bool result = seachEle(row, column, matrix, target);
	if(result){
		cout << "true";
	}
	else{
		cout << "false";
	}

	return 0;

}

// INPUT : 

// 3 4
// 1 3 5 7 
// 10 11 16 20
// 23 30 34 60
// 10

// OUTPUT : true

// INPUT : 

// 3 4
// 1 3 5 7 
// 10 11 16 20
// 23 30 34 60
// 12

// OUTPUT : false