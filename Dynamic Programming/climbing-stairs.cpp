#include <bits/stdc++.h>
using namespace std;

// int climbingStairs(int n, vector<int> dp){

//     if( n <= 1 ) return 1;
    
//     if(dp[n] != -1) return dp[n];

//     int oneStep = climbingStairs(n-1, dp);
//     int twoSteps = climbingStairs(n-2, dp);

//     return dp[n] = oneStep + twoSteps;

// }


// Leetcode Way : 

int helper(int n, vector<int>& dp){
    
   if(n <= 1) return 1;
   if(n <= 1) return 1;

   if(dp[n] != -1) return dp[n];

   int oneStep = helper(n-1, dp);
   int twoSteps = helper(n-2, dp);

   return dp[n] = oneStep + twoSteps;

}

int climbingStairs(int n){
   
   vector<int> dp(n+1, -1);
   return helper(n, dp);

}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n;
	cin >> n;

	int output = climbingStairs(n);

	cout << output;

	return 0;

}


// INPUT : 3
// OUTPUT : 3

// INPUT : 7 
// OUPUT : 21

// INPUT : 4
// OUTPUT : 5