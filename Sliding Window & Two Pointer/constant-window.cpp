#include <bits/stdc++.h>
using namespace std;

int constantWindow(int n, int* nums, int k){
 
// Brutal Solution

    // int left = 0;
    // int right = k-1;
    // int maxLen = 0;

    // while(right < n){

    //     for(int i=left; i<=right; i++){
    //         int sum = 0;
    //         for(int j=i; j<=right; j++){
    //             sum = sum + nums[j];
    //         }
    //         maxLen = max(maxLen, sum);
    //     }
    //     left++;
    //     right++;
    // }

    // return maxLen;


// Optimal Solution

    int left = 0;
    int right = 0;
    int sum = 0;
    int maxSum = 0;

    while (right < n) {

        int length = right - left + 1;
        sum = sum + nums[right];

        if(length == k) {
            maxSum = max(maxSum, sum);
            sum = sum - nums[left];
            left++;
        } 
        else if(length > k) {
            sum = sum - nums[left];
            left++;
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

    int result = constantWindow(n, nums, k);
    cout << result;

    return 0;

}

// INPUT :

// 7
// -1 2 3 3 4 5 -1
// 4

// OUTPUT : 15