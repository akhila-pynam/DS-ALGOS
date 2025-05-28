#include <bits/stdc++.h>
using namespace std;

void printNums(int i, int n){
    
    if(i < 1) return;
    
    cout << i << endl;
    i--;
    printNums(i, n);
    
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
// OUTPUT : 5 4 3 2 1 