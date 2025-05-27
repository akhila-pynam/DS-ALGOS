#include <bits/stdc++.h>
using namespace std;

int cnt = 0;
void printNums(){

    cout << cnt << endl;
    cnt++;
    printNums();

}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	printNums();

	return 0;

}

// OUTPUT : 

// 0 1 2 3 4 5 6 7 8 9 10 11 ..... Uptill Infinite 