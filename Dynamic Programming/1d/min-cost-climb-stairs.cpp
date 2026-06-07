#include <bits/stdc++.h>
using namespace std;

int minCost(int n, vector<int>& cost, vector<int>& dp){

    if(n <= 1) return 0;

    if(dp[n] != -1) return -1;

    for(int i=0; i<=n; i++){
        dp[i] = min(minCost(n-1, cost, dp) + cost[n-1], minCost(n-2, cost, dp) + cost[n-2]);
    }

    return dp[n];

}

int main(){

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n;
    cin >> n;

    vector<int> cost(n);

    for(int i=0; i<n; i++){
       
       int value;
       cin >> value;

       cost[i] = value;

    }

    vector<int> dp(n+1, -1);

    cout << minCost(n, cost, dp);

    return 0;

}

INPUT :

3
10 15 20

OUTPUT : 15


INPUT : 

10
1 100 1 1 1 100 1 1 100 1

OUTPUT : 6