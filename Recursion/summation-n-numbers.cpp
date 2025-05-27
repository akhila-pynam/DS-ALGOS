#include <bits/stdc++.h>
using namespace std;

void summation(int i, int sum){

    if(i < 1) {
	    cout << sum;
	    return;
    }
    
    summation(i-1, sum + i);

}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n;
	cin >> n;

	int sum = 0;

	summation(n, sum);

	return 0;

}


// INPUT : 3
// OUTPUT : 6

// INPUT : 2
// OUTPUT : 3

// INPUT : 5 
// OUTPUT : 15