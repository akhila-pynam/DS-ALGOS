#include <bits/stdc++.h>
using namespace std;

bool isomorphic(int n, int m, string s, string t, vector<char>& visited, bool output){

    for(int i=0; i<min(n, m); i++){
    	
    	if(!visited[s[i]]){
    		visited[s[i]] = t[i];
    	}

    	else{
           
           if(visited[s[i]] != t[i]){
           	return !output;
           }

    	}
        
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

	vector<char> visited(256);

	output = isomorphic(n, m, s, t, visited, output);

	cout << output;

	return 0;

}

// INPUT : 

// 3 
// 3 
// foo 
// bar

// OUTPUT : 0


// INPUT :

// 3 
// 3 
// egg
// add

// OUTPUT : 1