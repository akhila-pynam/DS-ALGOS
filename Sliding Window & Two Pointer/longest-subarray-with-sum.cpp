#include <bits/stdc++.h>
using namespace std;

int longestSubarray(int n, int* nums, int k){
    
    int maxSum = 0;

    for(int i=0; i<n; i++){
    	int sum = 0;
    	for(int j=i; j<n; j++){
    		sum = sum + nums[j];
    		maxSum = max(maxSum, sum);
    	}
    	if(sum < k){
    	   return sum;
        }
    }
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n;
	cin >> n;
    
    int nums[n];
    for(int i=0; i<n; i++){
    	cin >> nums[i];
    }

    int k;
    cin >> k;

    int result = longestSubarray(n, nums, k);
    cout << result;

    return 0;

}

// INPUT :

// 6
// 1 2 3 4 5 6
// 10

// OUTPUT : 6

// INPUT :

// 7
// -1 2 3 3 4 5 -1
// 15

// OUTPUT : 14