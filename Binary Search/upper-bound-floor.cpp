#include <bits/stdc++.h>
using namespace std;

int upperBound(int n, int* nums, int target){
    
    int left = 0;
    int right = n - 1;
    int floor = -1;

    while(left <= right){

    	int mid = (left + right)/2;

    	if(nums[left] < target){
    	   floor = nums[mid];
           left = mid + 1; 
    	}
    	else{
    		right = mid - 1;
    	}

    }
    return floor;
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

	int result = upperBound(n, nums, target);
	cout << result;

	return 0;

}

// INPUT : 

// 8
// 5 5 5 6 6 6 8 9 
// 7

// OUTPUT : 6