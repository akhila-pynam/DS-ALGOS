#include <bits/stdc++.h>
using namespace std;

void powerRecursion(int n, int ind){
    
    int p = pow(3, ind);

    if(ind > n){
       cout << 0; 
       return;
    }  
    if(p == n){
       cout << ind;
       return;
    } 
    
    p = pow(3, ind);
    powerRecursion(n, ind+1);

}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n;
	cin >> n;

	powerRecursion(n, 1);

	return 0;

}

// INPUT : 27 
// OUTPUT : 3

// INPUT : 1
// OUTPUT : 0
 
// INPUT : 9
// OUTPUT : 2