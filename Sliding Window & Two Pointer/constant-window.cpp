#include <bits/stdc++.h>
using namespace std;

int constantWindow(int n, int* nums, int k){
    
    int left = 0;
    int right = k;
    int maxSum = 0;

    while(right < n){
        
        int sum = 0;
        for(int i=left; i<right; i++){
            sum = sum + nums[i];   
        } 

        maxSum = max(maxSum, sum);
        
        left++;
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
    for(int i = 0; i < n; i++){
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