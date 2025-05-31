#include <bits/stdc++.h>
using namespace std;

int majorityElement(int n, vector<int>& nums){

    int cnt = 0;
    map<int, int> mp;

    for(int i=0; i<n; i++){
        
        // I am Using Cnt  - To Use It We Need To Pre-Increment The Element
     	// cnt = ++mp[nums[i]];
        
        // if(cnt > n/2){
    	// 	return nums[i];
    	// }

     	mp[nums[i]]++;

    	if(mp[nums[i]] > n/2){
    		return nums[i];
    	}

    }

    return -1;

}

int main(){

	#ifndef	ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n;
    cin >> n;
    
    // Here I Found Issue - To Insert n Elements We Need To Initialize - vector<int> nums(n)
    // vector<int> nums;

    vector<int> nums(n);
    for(int i=0; i<n; i++){
    	cin >> nums[i];
    }

    int result = majorityElement(n, nums);

    if(result){
    	cout << result;
    }
    else{
    	cout << -1;
    }

    return 0;

}


// INPUT :

// 7 
// 2 2 1 1 1 2 2 

// OUTPUT : 2


// INPUT : 

// 3
// 3 2 3

// OUTPUT : 3