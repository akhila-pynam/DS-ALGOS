#include <bits/stdc++.h>
using namespace std;

int kthLargest(int n, int* nums, int k){
   
    priority_queue<int, vector<int>, greater<int>> pq;

    for(int i=0; i<k; i++){
        pq.push(nums[i]);
    }

    for(int i=k; i<n; i++){
        if(nums[i] > pq.top()){
            pq.pop();
            pq.push(nums[i]);
        }
    }

    return pq.top();
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

    int k;
    cin >> k;

    int result = kthLargest(n, nums, k);
    cout << result;

    return 0;
}

// INPUT :
 
// 6
// 12 3 5 7 19 1
// 3

// OUTPUT : 7