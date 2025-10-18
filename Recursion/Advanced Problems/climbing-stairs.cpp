#include <bits/stdc++.h>
using namespace std;

// It Is O(n^2) Solution , So I Got TLE

int climbingStairs(int n){

    if( n <= 1 ) return 1;
    
    int left = climbingStairs(n-1);
    int right = climbingStairs(n-2);

    return left + right;
    
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n;
    cin >> n;

    int output = climbingStairs(n);
    cout << output;

    return 0;

}

// INPUT : 3 
// OUTPUT : 3

// INPUT : 4
// OUTPUT : 5

// INPUT : 2
// OUTPUT : 2