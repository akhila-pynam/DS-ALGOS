#include <bits/stdc++.h>
using namespace std;

int sum = 0;

// Parameterized 

// void funcSum(int n){

//    if(n < 1){
//       cout << sum;
//       return;
//    }

//    sum = sum + n;
//    n--;

//    funcSum(n);

// }


// Functional - No Need Any Parameter , Jus Returning The Value

int funcSum(int n){

   if(n == 0) return 0;

   return n + funcSum(n-1);

}  


int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n;
	cin >> n;

	int out = funcSum(n);
	cout << out;

	return 0;

}


// INPUT : 8
// OUTPUT : 36

// INPUT : 7 
// OUTPUT : 28