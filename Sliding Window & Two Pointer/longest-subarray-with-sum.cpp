#include <bits/stdc++.h>
using namespace std;

int longestSubarray(int n, int* nums, int k){

// BRUTAL SOLUTION / BRUTE FORCE 

    // TC -> O(N^2)
    // SC -> O(1)

    // int maxLen = 0;

    // for(int i=0; i<n; i++){
    // 	int sum = 0;
    // 	for(int j=i; j<n; j++){
    // 		sum = sum + nums[j];
    //         if(sum <= k){
    //           maxLen = max(maxLen, j-i+1);
    //         }
    // 	}
    // }
    // return maxLen;


// BETTER SOLUTION

    // TC -> O(N + N)
    // SC -> O(1)

// Expand - Left
// Shrink - Right 

   // int left = 0;
   // int right = k-1;
   // int sum = 0;
   // int maxLen = 0;

   // while(right < n){
        
   //      for(int i=0; i<k; i++){
   //         for(int j=i; j<k; j++){ 
               
   //              sum = sum + nums[j];

   //              while(sum > k){
   //                sum = sum - nums[left];
   //                left++;
   //              }
   //              if(sum < k){
   //                  maxLen = max(maxLen, j-i+1);
   //                  right++;
   //              }
   //          }
   //      }
   //  }


// OPTIMAL SOLUTION 
   
   // TC -> O(N)
   // SC -> O(1)

   int left = 0;
   int right = 0;
   int sum = 0;
   int maxSum = 0;

   while(right < n){
        
        sum = sum + nums[right];

        if(sum > k){
            sum = sum - nums[left];
            left++;
        }   
        
        if (sum <= k) {
            maxSum = max(maxSum, sum);
        } 
        right++;
    }
    return maxSum;
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

    int k;
    cin >> k;

    int result = longestSubarray(n, nums, k);
    cout << result;

    return 0;

}



// INPUT :

// 6
// 1 2 3 4 5 6
// 10

// OUTPUT : 4 ( BRUTAL SOLUTION )
// OUTPUT : 9 ( BETTER AND OPTIMAL SOLUTION )

// INPUT :

// 7
// -1 2 3 3 4 5 -1
// 15

// OUTPUT : 7 ( BRUTAL SOLUTION )
// OUTPUT : 14 ( BETTER AND OPTIMAL SOLUTION )