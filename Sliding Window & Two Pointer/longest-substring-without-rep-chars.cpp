#include <bits/stdc++.h>
using namespace std;

int longSubstring(int n, string& s){
    
// Brute Force 

	// map<int, int> hash;
	// int maxLen = 0;

	// for(int i=0; i<n; i++){
	// 	hash.clear();
	// 	for(int j=i; j<n; j++){
    //         hash[s[j] - 'a']++;

    //         if(hash[s[j] - 'a'] > 1){
    //         	break;
    //         }

    //         maxLen = max(maxLen, (j - i + 1));
   	// 	}
	// 	return maxLen;
	// }



// Optimal Solution 

    int left = 0;
    int right = 0;
    int maxLen = 0;
    map<char, int> hash;
    // unordered_map<char, int> hash;
    // vector<int> hash(26,0);

    while(right < n){
        
        hash[s[right] - 'a']++;
        
        while(left <= right && hash[s[right] - 'a'] > 1){
        	hash[s[left] - 'a']--;
        	left++;
        }

        maxLen = max(maxLen, (right - left + 1));
        right++;

    }
    return maxLen;
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

	int result = longSubstring(n, s);
	cout << result;

	return 0;

}

// INPUT :

// 9
// abcddabac 

// OUTPUT : 4

// INPUT : 

// 9
// aaabbbccc 

// OUTPUT : 2