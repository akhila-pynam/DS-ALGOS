#include <bits/stdc++.h>
using namespace std;

int power(double x, int n){

    double pwr = 1;

    if(n < 0){
    	n = -n;
    	x = 1/x;
    }

    for(int i=1; i<=n; i++){

    	pwr = pwr*x;

    }
    cout << pwr;

}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	double x;
	cin >> x;

	int n;
	cin >> n;

    power(x, n);

    return 0;

}


// INPUT : 

// 2.00000
// -2

// OUTPUT : 0.25


// INPUT : 

// 2.00000
// 10

// OUTPUT : 1024