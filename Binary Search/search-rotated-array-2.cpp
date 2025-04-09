#include <bits/stdc++.h>
using namespace std;

bool searchRotated(int n, int* nums, int target){
    
    int left = 0;
    int right = n-1;
    bool ans = false;

    while(left <= right){

    	int mid = (left + right)/2;

    	if(nums[mid] == target){
    		ans = true;
            break;
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
    
    bool result = searchRotated(n, nums, target);
    if(result){
        cout << "true";
    }
    else{
        cout << "false";
    }

    return 0;
}

// INPUT : 

// 7
// 2 5 6 0 0 1 2
// 9

// OUTPUT : false 

// INPUT : 

// 7
// 2 5 6 0 0 1 2
// 6

// OUTPUT : true