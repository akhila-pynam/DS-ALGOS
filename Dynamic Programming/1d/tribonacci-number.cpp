#include <bits/stdc++.h>
using namespace std;

int tribonacci(int n, vector<int>& dp){

	if(n == 0) return 0;
	if(n == 1) return 1;
	if(n == 2) return 1;

	if(dp[n] != -1) return dp[n];

    return dp[n] = tribonacci(n-1, dp) + tribonacci(n-2, dp) + tribonacci(n-3, dp); 
 
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n;
	cin >> n;

	vector<int> dp(n+1, -1);

    int out = tribonacci(n, dp);

    cout << out;

    return 0;

}

// INPUT : 4
// OUTPUT : 4
