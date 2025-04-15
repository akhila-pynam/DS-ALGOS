#include <bits/stdc++.h>
using namespace std;

int numberOccurances(int n, int* nums, int target){
    
    int left = 0;
    int right = n-1;
    int count = 0;

    while(left <= right){
    	
    	int mid = (left + right)/2;

    	
        if(nums[mid] == target) {
            
            count++;
            int leftIndex = mid - 1;

            while(leftIndex >= left && nums[leftIndex] == target) {
              
                count++;
                leftIndex--;

            }

            int rightIndex = mid + 1;
            
            while(rightIndex <= right && nums[rightIndex] == target) {
              
                count++;
                rightIndex++;

            }

            break;
        }

    	else if(nums[mid] < target) {
            left = mid+1;
        }

        else {
            right = mid-1;
        }

    }

    return count;

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

	int result = numberOccurances(n, nums, target);
	cout << result;

	return 0;

}