#include <bits/stdc++.h>
using namespace std;

int nameCnt = 0;
void name(){

	if(nameCnt == 5) return;
	cout << "Akhila Pynam" << endl;
	nameCnt++;
	
	name();

}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	name();

	return 0;

}

// OUTPUT : 

// Akhila Pynam
// Akhila Pynam
// Akhila Pynam
// Akhila Pynam
// Akhila Pynam
