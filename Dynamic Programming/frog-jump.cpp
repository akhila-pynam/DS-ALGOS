#include <bits/stdc++.h>
using namespace std;


int helper(int n, vector<int>& heights, vector<int>& dp, int ind){
    
    if(ind == 0) return 0;

    if(dp[ind] != -1) return dp[ind];

    int singleJump = helper(n, heights, dp, ind-1) + abs(heights[ind] - heights[ind-1]);

    int doubleJump = INT_MAX;

    if(ind > 1){
       doubleJump = helper(n, heights, dp, ind-2) + abs(heights[ind] - heights[ind-2]); 
    }

    return dp[ind] = min(singleJump, doubleJump);

}

int frogJump(int n, vector<int>& heights){

    vector<int> dp(n+1, -1);

    return helper(n, heights, dp, n-1);

}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n;
	cin >> n;

	vector<int> heights(n);

	for(int i=0; i<n; i++){
	  cin >> heights[i];
    }

	int output = frogJump(n, heights);

	cout << output;

	return 0;

}


// INPUT : 

// 5
// 7 5 1 2 6 

// OUTPUT : 15


// INPUT :

// 5
// 2 1 3 5 4 

// OUTPUT : 2