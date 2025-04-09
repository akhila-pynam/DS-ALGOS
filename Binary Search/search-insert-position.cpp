#include <bits/stdc++.h>
using namespace std;

int searchInsert(int n, int* nums, int target){
    
    int left = 0;
    int right = n-1;
    int ans = -1;

    while(left <= right){

    	int mid = (left + right)/2;

    	if(nums[mid] == target){
    		ans = mid;
    	}

    	if(nums[mid] < target){
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
	for(int i=0; i<n; i++){
		cin >> nums[i];
	}

	int target;
	cin >> target;

	int result = searchInsert(n, nums, target);
	cout << result;

	return 0;

}

// INPUT : 

// 4 
// 1 3 5 6 
// 5

// OUTPUT : 2
