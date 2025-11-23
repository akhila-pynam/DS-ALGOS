#include <bits/stdc++.h>
using namespace std;

bool isSubsequence(string a, string p, vector<char>& out){

    int i = 0;
    int j = 0;

    while(i < a.size() && j < p.size()){
         
        if(a[i] == p[j]){
    	   i++;
        }
        j++;

    }

    if(i == a.size()) return true;

    return false;

}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	string a;
	cin >> a;

    string p;
    cin >> p;

	vector<char> out;

	bool output = isSubsequence(a, p, out);

	if(output){
		cout << "true";
	}
	else cout << "false";

	return 0;

}

// INPUT : 

// abc 
// ahbgdc

// OUTPUT : true