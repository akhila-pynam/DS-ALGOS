#include <bits/stdc++.h>
using namespace std;

int main(){
	
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n;
	cin >> n;

	int output = ((n | n+1));

	if(n != output){
       cout << output;
	}
	else{
		cout << -1;
	}
}

// INPUT : 15 
// OUTPUT : 31 

// INPUT : 6 
// OUTPUT : 7