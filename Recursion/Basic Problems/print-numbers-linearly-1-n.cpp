#include <bits/stdc++.h>
using namespace std;

// void func(int n, int cnt){
     
//     if(cnt > n){
//     	return;
//     }
//     cout << cnt << " ";
//     cnt++;
//     func(n, cnt);

// }

// Back - Tracking Method

void func(int n, int cnt){

	if(cnt == 1) return;
    
	cnt--;
	func(n, cnt);
	cout << cnt << " ";

}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n;
	cin >> n;

	func(n, 100);

	return 0;

}

// INPUT : 2 
// OUTPUT : 1 2 

// INPUT : 5
// OUTPUT : 1 2 3 4 5
