#include <bits/stdc++.h>
using namespace	 std;

int sumDigits(int n, int sum){
    
    while(n){

        sum = sum + n%10;
        n = n/10;

    }

    return sum;

}
int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n;
	cin >> n;

	int sum = 0;

	int summation = sumDigits(n, sum);

	cout << summation;

	return 0;

}

// INPUT : 156307
// OUTPUT : 22

// INPUT : 13 
// OUTPUT : 4