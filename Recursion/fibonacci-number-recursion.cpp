#include <bits/stdc++.h>
using namespace std;

// Common Method  

// void fibinocci(int n){
    
//     if(n == 0){ cout << n; return; }  
//     if(n == 1){ cout << n; return; }

//     int f[n + 1];

// 	f[0] = 0;
// 	f[1] = 1;

// 	for(int i=2; i<=n; i++){
// 		f[i] = f[i-1] + f[i-2];
// 	}

// 	cout << f[n];

// }


// Recursion Method 

int fibinocci(int n){

    if(n <= 1) return n;

    return fibinocci(n-1) + fibinocci(n-2);

}


int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n;
	cin >> n;

    fibinocci(n);

	return 0;

}

// INPUT : 4
// OUTPUT : 3

// INPUT : 6
// OUTPUT : 8