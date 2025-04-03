#include <bits/stdc++.h>
using namespace std;

int solve(int n){

	if(n % 4 == 0) return n;
	if(n % 4 == 1) return 1;
	if(n % 4 == 2) return 2;
	return 0;
}
int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n;
	cin >> n;

	cout << solve(n);

}