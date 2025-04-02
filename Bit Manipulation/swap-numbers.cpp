#include <bits/stdc++.h>
using namespace std;

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int x , y;
	cin >> x >> y;

    x = x ^ y; // 0 0 1 ^ 0 1 0 = 0 1 1 

    y = x ^ y; // 0 1 1 ^ 0 1 0 = 0 0 1 => ( x ^ y ) ^ y = x
    
    x = x ^ y; // 0 1 1 ^ 0 0 1 = 0 1 0 => ( x ^ y ) ^ x = y

    cout << x << " " << y;

    return 0;

}