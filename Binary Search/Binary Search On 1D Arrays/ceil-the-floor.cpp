#include <bits/stdc++.h>
using namespace std;

pair<int, int> ceilThefloor(int n, int* nums, int target){
    
   
    int left = 0;
	int right = n-1;
	int floor = -1;
	int ceil = -1;

	while(left <= right){
		
		int mid = (left + right)/2;

        if(nums[mid] == target){
            floor = ceil = nums[mid];
			break;
		}
		if(nums[mid] > target){
		    ceil = nums[mid];
			right = mid - 1;
		}
		else{
			floor = nums[mid];
			left = mid + 1;
		}
	}

    return {floor, ceil};

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

	pair<int, int> result = ceilThefloor(n, nums, target);
	cout << "{" << result.first << " " << result.second << "}";

	return 0;

}