#include <bits/stdc++.h>
using namespace std;

int lowerBound(int n, int target, int* nums) {
    
    int left = 0;
    int right = n - 1;
    int ans = n;

    while (left <= right) {
        
        int mid = (left + right) / 2;

        if (nums[mid] > target) {
            ans = mid;
            right = mid - 1;
        } 

        else {
            left = mid + 1;
        }
    }

    return ans;
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

    int result = lowerBound(n, target, nums);
    cout << result << endl;

    return 0;
}
