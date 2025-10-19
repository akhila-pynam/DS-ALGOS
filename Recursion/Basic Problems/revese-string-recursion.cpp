#include <bits/stdc++.h>
using namespace std;

string funcStrReverse(int n, string s, int i){

	if(i >= n/2) return s;

	swap(s[i], s[n-i-1]);

	return funcStrReverse(n, s, i+1);

}
int main(){

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    string s;
    cin >> s;

    int n = s.size();

    string out = funcStrReverse(n, s, 0);

    cout << out;

    return 0;

}

// INPUT : hello 
// OUTPUT : olleh

// INPUT : Hannah 
// OUTPUT : hannaH

