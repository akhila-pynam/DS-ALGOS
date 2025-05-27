#include <bits/stdc++.h>
using namespace std;

void printNums(int i, int n){
    
    if(i < 1) return;
    
    i--;
    printNums(i, n);
    cout << i << endl;
    
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n;
	cin >> n;

	printNums(n, n);

	return 0;

}

// INPUT : 5
// OUTPUT : 0 1 2 3 4 