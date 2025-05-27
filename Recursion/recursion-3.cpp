#include <bits/stdc++.h>
using namespace std;

int cnt = 0;
void printNums(){
     
    if(cnt == 5) return;

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

// 1
// 2
// 3
// 4
