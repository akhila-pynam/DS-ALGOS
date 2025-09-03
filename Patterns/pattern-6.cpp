#include <bits/stdc++.h>
using namespace std;

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n;
	cin >> n;

	for(int i=0; i<n; i++){
		for(int j=1; j<=n-i; j++){
			cout << j;
		}
		cout << endl;
	}

	return 0;
	
}

// INPUT : 5

// OUTPUT :

// 12345
// 1234
// 123
// 12
// 1
