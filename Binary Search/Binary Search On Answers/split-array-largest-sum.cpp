#include <bits/stdc++.h>
using namespace std;

int numSum(int mid, int* nums, int n){
    
    int sum = 0;
    int count = 1;

    for(int i = 0; i < n; i++){

    	sum = sum + nums[i];
        
        if(sum > mid){
            count++;
            sum = nums[i];
        } 
    }
    return count;
}

int spiltLargsum(int n, int* nums, int k){
 
    int left = 0;

    for(int i = 0; i < n; i++){
        left = max(left, nums[i]);
    }

    int right = 0;

    for(int i = 0; i < n; i++){
        right = right + nums[i];
    }

    int ans = -1;

    while(left <= right){
        int mid = (left + right) / 2;
        int Lsum = numSum(mid, nums, n);

        if(Lsum <= k){
            ans = mid;
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    }
    return ans;
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

    int result = spiltLargsum(n, nums, k);
    cout << result;

    return 0;
}
