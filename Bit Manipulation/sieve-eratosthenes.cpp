#include <bits/stdc++.h>
using namespace std;

void primeSieve(int n){

    vector<int> prime(n+1, 0);

	for(int i=2; i*i<=n; i++){
		if(prime[i] == 0){
			for(int j=i*i; j<=n; j = j+i){
               prime[j] = 1;
			}
		}
	}

	for(int i=2; i<=n; i++){
		if(prime[i] == 0){
			cout << i << " ";
		}
	}
}
int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n;
	cin >> n;

	primeSieve(n);
}