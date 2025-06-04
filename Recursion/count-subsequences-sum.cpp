#include <bits/stdc++.h>
using namespace std;

int countSubsequence(vector<int>& arr, int n, int target, int sum, int ind){

    if(ind == n){

    	if(target == sum){ return 1; }

    	else { return 0; }
    }

    int l = countSubsequence(arr, n, target, sum + arr[ind], ind+1);

    int r = countSubsequence(arr, n, target, sum, ind+1);

    return l + r;

}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n;
	cin >> n;

	vector<int> arr(n);
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}

	int target;
	cin >> target;

	int result = countSubsequence(arr, n, target, 0, 0);
	cout << result;

	return 0;

}


// INPUT : 

// 3
// 1 2 1 

// OUPUT : 2