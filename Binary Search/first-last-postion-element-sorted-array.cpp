#include <bits/stdc++.h>
using namespace std;

pair<int, int> firstLast(int n, int* nums, int target) {
   
    int left = 0;
    int right = n - 1;
    pair<int, int> result = {-1, -1};

    while (left <= right) {

        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
          
            result.first = mid;
            right = mid - 1;

        } 

        else if (nums[mid] > target) {
            right = mid - 1;
        } 

        else {
            left = mid + 1;
        }

    }

    if (result.first == -1) return result;

    left = result.first;
    right = n - 1;

    while (left <= right) {
       
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
           
            result.second = mid;
            left = mid + 1;
            
        }

        else if (nums[mid] > target) {
            right = mid - 1;
        } 

        else {
            left = mid + 1;
        }

    }

    return result;
}

int main() {
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

    int target;
    cin >> target;

    pair<int, int> result = firstLast(n, nums, target);
    cout << "{" << result.first << " " << result.second << "}";
}

// INPUT :

// 6
// 5 7 7 8 8 10
// 8

// OUPUT : {3, 4}