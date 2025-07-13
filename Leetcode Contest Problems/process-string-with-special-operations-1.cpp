#include <bits/stdc++.h>
using namespace std;

string result;

void processString(int n, string s){
    
    for(int i=0; i<n; i++){

    	if(s[i] != '*' && s[i] != '#' && s[i] != '%' && s[i] != ' ') {
            result.push_back(s[i]);
        }

    	if(s[i] == '*' && result != "" && s[i] != ' '){
            result.pop_back(); 
        }
        else if(s[i] == '#' && result != "" && s[i] != ' '){
            result = result + result;
        }
        else if(s[i] == '%' && result != "" && s[i] != ' '){
            reverse(result.begin(), result.end());
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

    for(auto it : result){
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