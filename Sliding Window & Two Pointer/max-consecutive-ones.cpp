#include <bits/stdc++.h>
using namespace std;

int maxConsecutiveones(int n, int* nums, int k){
    
// BRUTAL SOLUTION

    // int left = 0;
    // int right = k-1;
    // int maxLen = 0;
 

    // for(int i=left; i<n; i++){
    //  int zeroCount = 0;
    //  for(int j=i; j<n; j++){
    //         if(nums[j] == 0){
    //          zeroCount++;
    //         }

    //         if(zeroCount <= k){
    //          int length = j-i+1;
    //          maxLen = max(maxLen, length);
    //      }
    //  }
    //  return maxLen;
    // }


// BETTER SOLUTION 
   
    // int left = 0;
    // int maxLen = 0;
    // int zeroCnt = 0;
        
    // for(int right = 0; right < n; right++){
    //     if (nums[right] == 0) {
    //         zeroCnt++;
    //     }
            
    // while (zeroCnt > k) {
    //     if (nums[left] == 0) {
    //         zeroCnt--;
    //     }
    //    left++;
    // }
    // length = right - left + 1;       
    // maxLen = max(maxLen, length);
    // }
        
    // return maxLen;


// Optimal Solution 

   int left = 0;
   int right = 0;
   int maxLen = 0;
   int length = 0;
   int zeroCnt = 0;

    while(right < n){
       
        if(nums[right] == 0){
          zeroCnt++;
        }

        while(zeroCnt > k){
          if(nums[left] == 0){
            zeroCnt--;
          }
          left++;
        }

        if(zeroCnt <= k){
           length = right - left + 1;
           maxLen = max(length, maxLen);
        }

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

    int k;
    cin >> k;  

    int result = maxConsecutiveones(n, nums, k);
    cout << result;

    return 0;

}

// INPUT : 

// 11
// 1 1 1 0 0 0 1 1 1 1 0
// 2

// OUTPUT : 6

// INPUT :
// 19
// 0 0 1 1 0 0 1 1 1 0 1 1 0 0 0 1 1 1 1
// 3

// OUTPUT : 10
 