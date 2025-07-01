#include <bits/stdc++.h>
using namespace std;

void func(int n, int cnt){
     
    if(cnt == 0) return;
    cout << cnt << " ";
    cnt--;
    func(n, cnt);

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

// INPUT : 5 
// OUTPUT : 5 4 3 2 1 

// INPUT : 3 
// OUTPUT : 3 2 1