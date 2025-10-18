#include <bits/stdc++.h>
using namespace std;

void name(int n, int cnt){
	
	if(cnt == n){
		return;
	}
	cout << "Akhila Pynam" << endl;
	cnt++;
	name(n, cnt);

}
int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n;
	cin >> n;

	name(n, 0);

	return 0;

}

// OUTPUT :

// Akhila Pynam
// Akhila Pynam
// Akhila Pynam
// Akhila Pynam
// Akhila Pynam