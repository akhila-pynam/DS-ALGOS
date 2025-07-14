#include <bits/stdc++.h>
using namespace std;

string output;

void processString(int n, string s){
    
    for(int i=0; i<n; i++){

    	if(s[i] != '*' && s[i] != '#' && s[i] != '%' && s[i] != ' ') {
            output.push_back(s[i]);
        }

    	if(s[i] == '*' && output != "" && s[i] != ' '){
            output.pop_back(); 
        }
        else if(s[i] == '#' && output != "" && s[i] != ' '){
            output = output + output;
        }
        else if(s[i] == '%' && output != "" && s[i] != ' '){
            reverse(output.begin(), output.end());
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

	string s;
	cin >> s;

    processString(n, s);

    for(auto it : output){
    	cout << it;
    }

    return 0;

}

// INPUT : 

// 3
// z*#

// OUTPUT : " "


// INPUT : 

// 5
// a#b%*

// OUTPUT : ba

// INPUT :

// 4
// ab#c

// OUTPUT : 

