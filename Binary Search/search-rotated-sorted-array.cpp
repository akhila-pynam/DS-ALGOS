#include <bits/stdc++.h>
using namespace std;

int searchRotated(int n, int* nums, int target){
    
    int left = 0;
    int right = n-1;
    int ans = -1;

    while(left <= right){

    	int mid = (left + right)/2;

    	if(nums[mid] == target){
    		return mid;
    	}

    	if(nums[left] <= nums[mid]){

            if (nums[left] <= target && target < nums[mid]) {
                right = mid - 1;
            } 
            else{
                left = mid + 1;
            }

        }

        else{

            if(nums[mid] < target && target <= nums[right]){
                left = mid + 1;
            } 
            else{
                right = mid - 1;
            }
            
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
    
    int result = searchRotated(n, nums, target);
    cout << result;

    return 0;
}

// INPUT :

// 7
// 4 5 6 7 0 1 2 
// 0

// OUTPUT : 4