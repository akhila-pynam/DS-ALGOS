#include <bits/stdc++.h>
using namespace std;

bool funcStrPalindrome(int i, int n, string s){

    if(i >= n/2) return true;
    if(s[i] != s[n-i-1]) return false;
 
    return funcStrPalindrome(i+1, n, s);

}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	string s;
	cin >> s;

	int n = s.size();

	bool out = funcStrPalindrome(0, n, s);

	if(out){
       cout << "true";
	} 
	else cout << "false";

	return 0;

}

// INPUT : madam 
// OUTPUT : true

// INPUT : roar 
// OUTPUT : false 

// INPUT : SOS 
// OUTPUT : true

// INPUT : RADAR 
// OUTPUT : true