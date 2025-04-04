#include <bits/stdc++.h>
using namespace std;

//  This Code Works For Single Elements 

int grayCode(int n){

	int leftShift = n >> 1;
	int output = (n ^ leftShift);
	return output;

}
int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n;
	cin >> n;

	int result = grayCode(n);
	cout << result;
}