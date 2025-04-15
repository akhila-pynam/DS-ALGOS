#include <bits/stdc++.h>
using namespace std;

int findPeak(int n, int* nums){

    if(n == 0) return 0;
    if(nums[0] > nums[1]) return 0;
    if(nums[n-1] > nums[n-2]) return n-1;

    int left = 1;
    int right = n-2;

    while(left <= right){

    	int mid = (left + right)/2;

    	if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]){
    		return mid;
    	}

    	else if((nums[mid] > nums[mid - 1])){
    		left = mid + 1;
    	}
    	else{
    		right = mid - 1;
    	}
    }
   
   return -1;

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
    
    int result = findPeak(n, nums);
    cout << result;

    return 0;

}