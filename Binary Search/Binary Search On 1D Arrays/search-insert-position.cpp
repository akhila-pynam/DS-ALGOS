#include <bits/stdc++.h>
using namespace std;

int SearchPosition(int n, int* nums, int insert){
    
    int left = 0;
    int right = n-1;

    while(left <= right){
    	
    	int mid = (left+right)/2;

    	if(nums[mid] < insert){
    		left = mid + 1;
    	}
    	else{
    		right = mid - 1;
    	}

    }

    return left;

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

	int insert;
	cin >> insert;

	int result = SearchPosition(n, nums, insert);
	cout << result;

	return 0;
}