#include <bits/stdc++.h>
using namespace std;

int getBit(int n, int index){
    
    int output;

    int x = 1 << index;
    return ((n & x) != 0);
    
}
int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n;
	cin >> n;

	int index;
	cin >> index;

	getBit(n, index);
    cout << getBit;
}