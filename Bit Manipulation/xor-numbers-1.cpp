#include <bits/stdc++.h>
using namespace std;

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

    int n;
    cin >> n;

    int ans = 0;

    for(int i=1; i<=n; i++){
        
        ans = ans ^ i;

    }
    cout << ans; 

}