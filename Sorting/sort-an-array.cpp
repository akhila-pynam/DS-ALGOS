#include <bits/stdc++.h>
using namespace std;

void swap(int& x, int& y){

	int temp = x;
	x = y;
	y = temp;

}

int sortArray(int n, vector<int>& nums){

    int lft = 0;
    int ryt = n-1;
    int mid = (lft + ryt)/2;

    while(lft < ryt){

        if(nums[lft] > nums[ryt]){
        	swap(nums[lft], nums[ryt]);
        }

        lft++;
        ryt--;

    }
    
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n;
	cin >> n;

	vector<int> nums(n);
	for(int i=0; i<n; i++){
		cin >> nums[i];
	}

	int out = sortArray(n, nums);

	for(int it : nums){
		cout << it << " ";
	}

	return 0;

}

// INPUT :

// 4
// 5 2 3 1 

// OUTPUT : 1 2 3 5 
