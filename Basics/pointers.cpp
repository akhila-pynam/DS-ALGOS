#include <bits/stdc++.h>
using namespace std;

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int x;
	cin >> x;
    
    // * - Asterisk Is a Pointer That Holds The Address Of An Another Integer.
    // & - Ampesand/Address Is Used To Get The Memory Address Of The Variable.

	int* y = &x;

    cout << y;
    cout << endl;
	cout << *y;
    
    return 0;
}