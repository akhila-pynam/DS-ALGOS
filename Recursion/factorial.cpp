#include <bits/stdc++.h>
using namespace std;

int factorial(int n){

    if(n == 0) return 1;

    return n * factorial(n-1);

}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n;
	cin >> n;

	int result = factorial(n);

	if(result){
		cout << result << endl;
	}
	else{
		cout << n << endl;
	}

	return 0;

}


// INPUT : 5 
// OUTPUT : 120

// INPUT : 4
// OUTPUT :24

// INPUT : 3 
// OUPTUT : 9