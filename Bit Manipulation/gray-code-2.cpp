#include <bits/stdc++.h>
using namespace std;

// This Code I Designed Only For 2 

vector<int> grayCode1(int n){

	vector<int> output;

	    int a = (n & 1);
        int k = !!n;
        int h = (n | 1);
        int i = (n & ~1);

        output.push_back(a);
        output.push_back(k);
        output.push_back(h);
        output.push_back(i);

        return output;

}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);;
	#endif

	int n;
	cin >> n;

	vector<int> result = grayCode1(n);

	for(int i=0; i<result.size(); i++){
	    cout << result[i] << " ";
    }

}