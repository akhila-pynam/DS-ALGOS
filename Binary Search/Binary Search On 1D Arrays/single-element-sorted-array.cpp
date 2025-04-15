#include <bits/stdc++.h>
using namespace std;

int singleElement(int n, int* nums){
    
    int left = 0;
    int right = n-1;
    
    while(left <= right){
        int mid = left + (right - left) / 2;
        
        if((mid == 0 || nums[mid] != nums[mid-1]) && (mid == n-1 || nums[mid] != nums[mid+1])){
            return mid;
        }

        if(mid % 2 == 0){
            if(nums[mid] == nums[mid + 1]){
                left = mid + 2;
            } 
            else{
                right = mid - 1;
            }
        } 

        else{
           
            if(nums[mid] == nums[mid - 1]){
                left = mid + 1;
            } 
            else{
                right = mid - 2;
            }
        }
    }
    
    return -1;
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

    int result = singleElement(n, nums);
    cout << result;

    return 0;
}
