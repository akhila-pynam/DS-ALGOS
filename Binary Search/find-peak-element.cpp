#include <bits/stdc++.h>
using namespace std;

int findPeak(int n, int* nums){
    
    int left = 0;
    int right = n - 1;
    int ans = -1;

    while(left <= right){
        
        int mid = (left + right)/2;

        if(nums[mid-1] < nums[mid] && nums[mid] > nums[mid+1]){
            ans = mid;
            break;
        }

        if(nums[left] < nums[mid]){
            left = mid + 1;
        }
        else{
            right = mid - 1;
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
    for(int i=0; i<n; i++){
        cin >> nums[i];
    }
    
    int result = findPeak(n, nums);
    cout << result;

    return 0;

}