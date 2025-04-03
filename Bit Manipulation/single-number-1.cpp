#include <bits/stdc++.h>
using namespace std;

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n;
	cin >> n;

	int array[n];
	for(int i=0; i<n; i++){
		cin >> array[i];
	}
    
    map<int, int> m;
       
    for(int i = 0; i < n; i++) {
        m[array[i]]++;
    }

    for(auto it : m) {
        if(it.second == 1) {
            cout << it.first << endl;
        }
    }    

    return 0;
}