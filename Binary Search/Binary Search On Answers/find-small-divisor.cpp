#include <bits/stdc++.h>
using namespace std;

int d(int mid, int n, int* nums) {
    
    int sum = 0;
   
    for(int i = 0; i < n; i++) {
        sum = sum + (nums[i]/mid) + ((nums[i] % mid != 0));
    }
    return sum;
}

int smallDivisor(int n, int* nums, int threshold) {
   
    int left = 1;
    int right = 0;
   
    for(int i = 0; i < n; i++) {
        right = max(right, nums[i]);
    }

    int ans = -1;
    while(left <= right) {
      
        int mid = (left + right) / 2;

        int divisor = d(mid, n, nums);
        
        if(divisor <= threshold){
            ans = mid;
            right = mid - 1;
        } 
        else{
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
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int threshold;
    cin >> threshold;

    int result = smallDivisor(n, nums, threshold);
    cout << result;

    return 0;
}
