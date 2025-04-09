#include <bits/stdc++.h>
using namespace std;

pair<int, int> firstLast(int n, int* nums, int target) {
    
    int left = 0;
    int right = n - 1;
    int first = -1;
    int last = -1;

    while(left <= right){
        int mid = (left + right)/2;

        if(nums[mid] == target){
            first = mid;
            right = mid - 1;
        } 
        else if(nums[mid] < target){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }

    left = 0; 
    right = n-1;

    while(left <= right) {
        int mid = (left + right)/2;

        if(nums[mid] == target){
            last = mid;
            left = mid + 1;
        } 
        else if(nums[mid] < target){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }

    return {first, last};
}

int main() {

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n;
    cin >> n;

    int nums[n];
    for (int i = 0; i<n; i++) {
        cin >> nums[i];
    }

    int target;
    cin >> target;

    pair<int, int> result = firstLast(n, nums, target);
    cout << "{" << result.first << " " << result.second << "}";

    return 0;
}

// INPUT : 

// 6
// 5 7 7 8 8 10
// 8

// OUTPUT : {3, 4}