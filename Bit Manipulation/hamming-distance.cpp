#include <bits/stdc++.h>
using namespace std;

int hammingDistance(int a, int p){

    int answer = 0;
    int output = a ^ p;

    while(output != 0){
         
        answer = answer + (output & 1);
        output = output >> 1;
    }

    return answer;

}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r",stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int a, p;
	cin >> a >> p;

	int result = hammingDistance(a, p);
	cout << result;

}