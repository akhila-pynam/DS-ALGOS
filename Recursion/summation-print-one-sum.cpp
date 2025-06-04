#include <bits/stdc++.h>
using namespace std;

vector<int> output;

bool summation(vector<int>& nums, int n, int sum, int ind, int target) {
   
    if(ind >= n){

        if(sum == target) {
            for(int it : output) {
                cout << it << " ";
            }
            cout << endl;
            return true;
        }

        return false;
    }

    output.push_back(nums[ind]);
    if(summation(nums, n, sum + nums[ind], ind + 1, target)) return true;
    output.pop_back();
    if(summation(nums, n, sum, ind + 1, target)) return true;

    return false;
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n;
    cin >> n;

    vector<int> nums(n);
    for(int i=0; i<n; i++){
        cin >> nums[i];
    }

    int target;
    cin >> target;

    summation(nums, n, 0, 0, target);

    return 0;
}


// INPUT :

// 3
// 1 2 1 

// OUTPUT : 1 1 