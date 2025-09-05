#include <bits/stdc++.h>
using namespace std;

int closest(int x, int y, int z){

	int small1 = abs(x - z);
	int small2 = abs(y - z);

	if(small1 < small2) return 1;
	if(small2 < small1) return 2;
	else return 0;

}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int x,y,z;
	cin >> x >> y >> z;

	int output = closest(x, y, z);

	cout << output;

	return 0;

}

// INPUT : 2 5 6 
// OUTPUT : 2

// INPUT : 2 7 4 
// OUTPUT : 1