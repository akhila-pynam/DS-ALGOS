#include <bits/stdc++.h>
using namespace std;

vector<int> helper(int n, vector<int>& nums, vector<int>& vis, vector<int>& out){

     
    for(int i=0; i<n; i++){
        vis[nums[i]] = 1;
    }

    for(int i=1; i<=n; i++){
        if(vis[i] == 0) out.push_back(i);
    }

    return out;

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
    
    vector<int> out;
    vector<int> vis(n+1, 0);
    
    vector<int> ans = helper(n, nums, vis, out);
    for(auto x : ans){
        cout << x << " ";
    }

    return 0;

}

// INPUT : 2
//         1 1

// OUTPUT : 2

// INPUT : 7
//         4 3 2 7 8 2 3 1

// OUTPUT : 5 6 