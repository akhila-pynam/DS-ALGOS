#include <bits/stdc++.h>
using namespace std;

int numSubstrings(int n, string& s){

// Brutal Solution 

    //  TC -> O(n^2)
    //  SC -> O(1)

	// int cnt = 0;

	//  for(int i=0; i<n; i++){

	// 	int hash[3] = {0};

	// 		for(int j=i; j<n; j++){
	          
	//            hash[s[j] - 'a']++;

	//            if(hash[0] > 0 && hash[1] > 0 && hash[2] > 0){
	//            	  cnt++;
	//            }
	// 		}

	// }
	// return cnt;

// Optimal Solution 

	// TC -> O(n)
	// SC -> O(1)

	int left = 0;
	int right = 0;
	int cnt = 0;
	int hash[3] = {0};

	while (right < n) {

        hash[s[right] - 'a']++;

        while (hash[0] > 0 && hash[1] > 0 && hash[2] > 0) {
            cnt = cnt + n - right;
            hash[s[left] - 'a']--;
            left++;
        }

        right++;
    }

    return cnt;

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
    
    int result = numSubstrings(n, s);
    cout << result;

    return 0;

}
// INPUT :
 
// 5
// aaacb      

// OUTPUT : 3

// INPUT :

// 6
// abcabc

// OUTPUT : 10