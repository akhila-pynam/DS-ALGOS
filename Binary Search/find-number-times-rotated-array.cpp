#include <bits/stdc++.h>
using namespace std;

int findMin(int n, int* nums){
     
    int left = 0;
    int right = n-1;
    int ans = INT_MAX;

    while(left <= right){

    	int mid = (left+right)/2;


    	if(nums[left] <= nums[mid]){
           
           ans = min(ans, nums[left]);
           left = mid + 1;

    	}
    	else{

    		right = mid -1;
            ans = min(ans, nums[mid]);
            
    	}

    }

    for(int i=0; i<n; i++){
    	if(ans == nums[i]){
    	   ans = i;
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

	int result = findMin(n, nums);
	cout << result;

	return 0;

}