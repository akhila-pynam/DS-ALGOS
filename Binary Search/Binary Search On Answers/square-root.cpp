#include <bits/stdc++.h>
using namespace std;

int squareRoot(int n, int* nums){

// Brutal Solution
// 	int ans = 1;
//     for(int i=1; i<=n; i++){
//        if(i*i <= n){
//           ans = i;
//        }
//     }
//     return ans;


// Optimal Solution Using Binary Search

	int left = 1;
	int right = n;
	int ans = 1;

	while(left <= right){

		int mid = (left + right)/2;

		if(mid*mid == n){
			ans = mid;
			break;
		}

		if(mid*mid < n){
           ans = mid;
           left = mid + 1;
		}
		else{
			right = mid - 1;
		}
	}

	return ans;

}

int main(){

	#ifndef ONLINE_JUDGE	
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n;
	cin >> n;

	int nums[n];
	for(int i=1; i<=n; i++){
		nums[i] = i;
	}

	int result = squareRoot(n, nums);
	cout << result;

	return 0;
}