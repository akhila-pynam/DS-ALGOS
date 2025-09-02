#include <bits/stdc++.h>
using namespace std;

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n;
	cin >> n;

	for(int i=1; i<=n; i++){
		for(int j=1; j<=i; j++){
			cout << i;
		}
		cout << endl;
	}

	return 0;

}

// INPUT : 5

// OUTPUT : 

// 1
// 22
// 333
// 4444
// 55555


