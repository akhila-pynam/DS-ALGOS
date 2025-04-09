#include <bits/stdc++.h>
using namespace  std;

int lowerBound(int n, int* nums, int target){
    
    int left = 0;
    int right = n-1;
    int ans = -1;

    while(left <= right){

    	int mid = (left + right)/2;

    	if(nums[mid] >= target){
           ans = mid;
           right = mid - 1;
    	}
    	else{
    		left = mid + 1;
    	}
    }
    return ans;
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n;
	cin >> n;

    int nums[n];
    for(int i=0; i<n; i++){
    	cin >> nums[i];
    }

    int target;
    cin >> target;

    int result = lowerBound(n, nums, target);
    cout << result;

    return 0;

}

// INPUT :

// 7
// 1 2 8 10 10 12 19
// 5

// OUTPUT : 2 (INDEX)