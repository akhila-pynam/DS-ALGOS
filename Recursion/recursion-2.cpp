#include <bits/stdc++.h>
using namespace std;

// int cnt = 0;
// void printCnt(){

//     cout << cnt << endl;
//     cnt++;
//     printCnt();

// }

// Included Base-Condition

int cnt = 0;
int printCnt(){

    if(cnt == 7) return cnt;
    cout << cnt << endl;
    cnt++;
    printCnt();

}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	printCnt();

	return 0;

}

// INPUT : 7 

// OUTPUT : 

// 0
// 1
// 2
// 3
// 4
// 5
// 6

