#include <bits/stdc++.h>
using namespace std;

int deleteEarn(int n, vector<int>& nums, vector<int>& values){
 
    int take = 0, skip = 0;

    for(int i=0; i<n; i++){

       int takei = skip + values[i];
       int skipi = max(skip, take);

       take = takei;
       skip = skipi;

    }

    return max(take, skip);

}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n;
	cin >> n;

	vector<int> nums(n);
	for(int i=0; i<n; i++){
		cin >> nums[i];
	}


	vector<int> values(n+1, 0);
	for(int i=0; i<n; i++){
		values[nums[i]] = values[nums[i]] + nums[i];
	}

	int out = deleteEarn(n+1, nums, values);

	cout << out;

	return 0;

}