#include <bits/stdc++.h>
using namespace std;

int houseRobber(int n, vector<int>& dp, vector<int>& nums){

	if(n<=0) return 0;

	if(dp[n] != -1) return dp[n];

	return dp[n] = max(houseRobber(n-1, dp, nums), nums[n-1] + houseRobber(n-2, dp, nums));
}
int main(){

	#ifndef ONLINE_JUDGE
	freopen("intput.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n;
	cin >> n;

	vector<int> nums(n);
	for(int i=0; i<n; i++){
		cin >> nums[i];
	}

	vector<int> dp(n+1, -1);

	int output = houseRobber(n, dp, nums);

	cout << output;

}

// INPUT : 

// 4
// 1 2 3 1 

// OUTPUT : 4
