#include <bits/stdc++.h>
using namespace std;

int helper(int n, vector<int>& nums){

    int curr = nums[0];
    int maxx = nums[0];

    for(int i=1; i<n; i++){

        curr = max(nums[i], curr + nums[i]);
        maxx = max(maxx, curr);

    }

    return maxx;

}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
     
    int n; cin >> n;
    vector<int> nums(n);
    for(int i=0; i<n; i++){
        cin >> nums[i];
    }

    cout << helper(n, nums);

    return 0;

}

// INPUT : 5
//         5 4 -1 7 8

// OUTPUT : 23 