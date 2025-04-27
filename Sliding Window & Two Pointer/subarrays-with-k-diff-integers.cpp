#include <bits/stdc++.h>
using namespace std;

int subarrays(int n, int* nums, int k){
   
    int left = 0;
    int right = 0;
    int distCnt = 0;
    int hash[100001] = {0};
    int subCnt = 0;

    while (right < n) {

        if (hash[nums[right]] == 0) {
            distCnt++;
        }

        hash[nums[right]]++;

        while (distCnt > k) {

            hash[nums[left]]--;

            if (hash[nums[left]] == 0) {
                distCnt--;
            }

            left++;
        }
        
        int length = right - left + 1;
        subCnt = subCnt + length;
        right++;
    }

    return subCnt;
}

int numSubarray(int n ,int* nums, int k) {
    return subarrays(n, nums, k) - subarrays(n, nums, k - 1);
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n;
    cin >> n;

    int nums[n];
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int k;
    cin >> k;

    int result = numSubarray(n, nums, k);
    cout << result;

    return 0;
}

// INPUT :

// 5
// 1 2 1 3 4
// 3

// OUTPUT : 3