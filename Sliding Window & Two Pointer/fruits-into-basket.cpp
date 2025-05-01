#include <bits/stdc++.h>
using namespace std;

int fruitsBaskets(int n, int* nums){

	// map<int, int> f;
    // int maxLen = 0;

    // for(int i=0; i<n; i++){
    //   for(int j=i; j<n; j++){
          
	//         f[nums[j]]++;

	//         if(f.size() > 2){
	//            break;
	//         }

	//         if(f.size() <= 2){
	//            int len = j-i+1;
	//            maxLen = max(maxLen, len);
	//         }

    //    }
    //    f.clear();
    // }
    // return maxLen;


// Optimal Solution 

	int left = 0;
	int right = 0;
	int maxLen = 0;
	map<int, int> f;

	while(right < n){
      
        f[nums[right]]++;

        if(f.size() > 2){
        	f[nums[left]]--;

        	if(f[nums[left]] == 0){
               f.erase(nums[left]);
        	}
        	left++;
        }
        maxLen = max(maxLen, (right - left + 1));
        right++;
	}
	return maxLen;
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

	int result = fruitsBaskets(n, nums);
	cout << result;

	return 0;

}
// INPUT :

// 5 
// 1 2 3 2 2 

// OUTPUT : 4

// INPUT : 

// 3 
// 1 2 1 

// OUTPUT : 3 
