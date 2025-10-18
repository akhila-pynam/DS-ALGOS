#include <bits/stdc++.h>
using namespace std;

bool reverseString(string s, int i, int n){

	if(i >= n/2) return true;

	while(s[i] != s[n-i-1]){
		return false;
	}

	reverseString(s, i+1, n-1);

}
int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n;
	cin >> n;

    string s;
    cin >> s;


    if(reverseString(s, 0, n)){
    	cout << "Yes, I'm a Palindrome :)";
    }
    else{
    	cout << "Nah!, I'm Not a Palindrome :(";
    }

    return 0;

}

// INPUT :

// 6
// AKHILA 

// OUTPUT : Nah!, I'm Not a Palindrome :(


// INPUT :

// 3
// AKA 

// OUTPUT : Yes, I'm a Palindrome :)


// INPUT : 

// 6
// HannaH

// OUTPUT : Yes, I'm a Palindrome :)

// INPUT : 

// 3
// BOB

// OUTPUT : Yes, I'm a Palindrome :)