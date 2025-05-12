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

// INPUT : 4

// OUTPUT : 0x61ff08 ( Undefined Memory Address Not a Specific - The Memory Asdress Can Change Each Time The Program Runs. )
//          4