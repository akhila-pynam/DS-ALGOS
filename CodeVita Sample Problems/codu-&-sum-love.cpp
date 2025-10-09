#include <bits/stdc++.h>
using namespace std;

int main(){

	#ifndef ONLINE_JUDGE 
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n;
	cin >> n;

	long long sum = 0;

	for(int i=0; i<n; i++){
       long long x;
       cin >> x;

       long long val = pow((1 << 1), x); 

       string str = to_string(val);

       if(str.size() > 2)

       	  str = str.substr(str.length() - 2);

       sum = stoi(str) + sum;
	} 

	cout << (sum % 100) << endl;

	return 0;

}

// INPUT : 4 
//         8 6 7 4 

// OUTPUT : 64