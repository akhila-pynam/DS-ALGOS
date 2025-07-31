#include <bits/stdc++.h>
using namespace std;

bool validAnagram(int n, int m, string s, string t, vector<int>& vis1, vector<int>& vis2, bool output){

    for(int i=0; i<n; i++){

		vis1[s[i]]++;
		vis2[t[i]]++;

    }

    for(int i=0; i<256; i++){
    	if(vis1[i] != vis2[i]) return !output;
    }

    return output;

}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n, m;
	cin >> n >> m;

	string s, t;
	cin >> s >> t;

	bool output = true;

	if(n != m) return !output;

	vector<int> vis1(256, 0);
	vector<int> vis2(256, 0);

	output = validAnagram(n, m, s, t, vis1, vis2, output);

	cout << output;

	return 0;

}

// INPUT :
 
// 3
// 3
// rat 
// cat

// OUTPUT : 0


// INPUT :

// 7
// 7
// anagram 
// nagaram

// OUTPUT : 1