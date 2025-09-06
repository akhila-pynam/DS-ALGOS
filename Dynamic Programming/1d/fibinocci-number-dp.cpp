#include <bits/stdc++.h>
using namespace std;

int fibinocci(int n, vector<int>& dp){

    if(n <= 1) return n;
    
    if(dp[n] != -1) return dp[n];

    return fibinocci(n-1, dp) + fibinocci(n-2, dp);

}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n;
    cin >> n;

    vector<int> dp(n+1, -1);

    int output = fibinocci(n, dp);

    cout << output;

    return 0;

}


// INPUT : 7
// OUTPUT : 13

// INPUT : 2
// OUTPUT : 1