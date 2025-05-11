#include <bits/stdc++.h>
using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;
int k_global;

void kthLargest(int k, vector<int>& nums) {
   
    k_global = k;
   
    for(int val : nums){
        
        pq.push(val);
        
        if (pq.size() > k_global) {
            pq.pop();
        }

    }
}

int add(int val) {
  
    pq.push(val);

    if (pq.size() > k_global) {
        pq.pop();
    }
    
    return pq.top();
}

void kthLargeststream(int n, vector<int>& nums, int k) {
   
    kthLargest(k, nums);
    cout << "null ";

}

int main() {

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int k;
    cin >> k;
    
    k_global = k;

    kthLargeststream(n, nums, k);

    int val;
    while (cin >> val) {
        cout << add(val) << " ";
    }
    cout << endl;

    return 0;
}

// INPUT : 

// 6
// 7 7 7 7 8 3 
// 4
// 2 
// 10
// 9
// 9

// OUTPUT : null 7 7 7 8 

