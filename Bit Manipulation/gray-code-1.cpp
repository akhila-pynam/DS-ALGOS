#include <bits/stdc++.h>
using namespace std;

vector<int> grayCode2(int n){

    vector<int> output;
    for(int i=0; i<(1 << n); i++){
       output.push_back(i ^ (i >> 1));
    }

    return output;
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n;
	cin >> n;

	vector<int> result = grayCode2(n);

	for(int i=0; i<(1 << n); i++){
        cout << result[i] << " ";
	}

	return 0;
}