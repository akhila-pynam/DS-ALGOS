#include <bits/stdc++.h>
using namespace std;

int power(int n, int p){

    for(int i=0; i<n; i++){
      
        p = pow(3, i);

        if(n == p){
       	   return i;
       	   break;
        }

    }

    return 0;
   
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n; cin >> n;

	int p;

	int out = power(n, p);

	cout << out;

	return 0;

}

// INPUT : 27
// OUTPUT : 3

// INPUT : 9
// OUTPUT : 2

// INPUT : 1
// OUTPUT : 0