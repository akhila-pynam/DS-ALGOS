#include <bits/stdc++.h>
using namespace std;

int sqrtBs(int n){

// Brutal Solution
// 	int ans = 1;
//     for(int i=1; i<=n; i++){
//        if(i*i <= n){
//           ans = i;
//        }
//     }
//     return ans;


// Optimal Solution Using Binary Search

	long long left = 1;
	long long right = n/2;
	long long ans = 1;

	if(n == 0 || n == 1) return n;

	while(left <= right){

		long long mid = (left + right)/2;

		if(mid*mid <= n) {
			ans = mid;
			low = mid + 1;
		}
		else{
			high = mid - 1;
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

	cout << sqrtBs(n);

	return 0;

}