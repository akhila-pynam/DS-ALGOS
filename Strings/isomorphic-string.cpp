#include <bits/stdc++.h>
using namespace std;

bool isomorphic(int n, int m, string s, string t, vector<char>& visited, vector<char>& reverse, bool output){

    for(int i=0; i<min(n, m); i++){
    	
    	if(!visited[s[i]] && !reverse[t[i]]){
    		visited[s[i]] = t[i];
    		reverse[t[i]] = s[i];
    	}

    	else{
           
            if(visited[s[i]] != t[i] && reverse[t[i]] != s[i]){
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
	vector<char> reverse(256);

	output = isomorphic(n, m, s, t, visited, reverse, output);

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