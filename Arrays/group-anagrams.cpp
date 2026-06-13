#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> helper(int n, vector<string>& strs){
    
    unordered_map<string, vector<string>> mp;

    for(string& word : strs){

        vector<int> freq(26, 0);

        for(int ch : word){
           freq[ch - 'a']++; 
        }
        
        string key;
        
        for(int x : freq){
        	key = key + to_string(x) + "#";
        }

        mp[key].push_back(word);

    }

    vector<vector<string>> ans;

    for(auto &p : mp){
        ans.push_back(p.second);
    }

    return ans;

}


int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

    int n;
    cin >> n;

    vector<string> strs(n);

    for(int i=0; i<n; i++){
    	cin >> strs[i];
    }

    vector<vector<string>> ans = helper(n, strs);

	for(int i = 0; i < ans.size(); i++) {
	    for(int j = 0; j < ans[i].size(); j++) {
	        cout << ans[i][j] << " ";
	    }
	    cout << endl;
	}


	return 0;

}

// INPUT : 

// 6
// eat ate tan nat bat tea


// OUTPUT : 

// bat 
// tan nat 
// eat ate tea 
