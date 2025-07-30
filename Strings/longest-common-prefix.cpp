#include <bits/stdc++.h>
using namespace std;

string longCommon(int n, vector<string>& str){

    sort(str.begin(), str.end());

    string first = str[0];
    string last = str[n-1];
    string output = " ";

    for(int i=0; i<min(first.length(), last.length()); i++){

       if(first[i] != last[i]) break;
       output = output + first[i];

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

	vector<string> str;
	for(int i=0; i<n; i++){
	   string s;
	   cin >> s;
	   str.push_back(s);
	}

	vector<string> store;

	string result = longCommon(n, str);

	cout << result << endl;

	return 0;

}


// INPUT :

// 4
// flower 
// flow
// fly
// flight

// OUTPUT : fl