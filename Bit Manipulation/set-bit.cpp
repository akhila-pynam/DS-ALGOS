#include <bits/stdc++.h>
using namespace std;

int setBit(int n, int index){

	int x = 1 << index;
	return (n | x);
	
}
int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n, index;
	cin >> n >> index;

	int result = setBit(n, index);
	cout << result;

}