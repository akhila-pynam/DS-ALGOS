#include <bits/stdc++.h>
using namespace std;

int longSubstring(int n, string& s, int k) {
  
// Brutal Solution 

	// TC -> O(n^2)
	// SC -> O(1)

    // int length = 0;
    // int maxLen = 0;

    // for(int i = 0; i < n; i++){

    //     int hash[26] = {0};
    //     int distCnt = 0;

    //     for(int j = i; j < n; j++){

    //         if (hash[s[j] - 'a'] == 0) {
    //             distCnt++;
    //         }

    //         if(distCnt > k){
    //             break;
    //         }

    //         hash[s[j] - 'a']++;

    //         length = j - i + 1;
    //         maxLen = max(maxLen, length);
    //     }
    // }

    // return maxLen;


// Optimal Solution

	// TC -> O(N)
	// SC -> O(1)

	int left = 0;
	int right = 0;
	int distCnt = 0;
	int maxLen = 0;

	while(right < n){

		int hash[26] = {0};

		if(hash[s[right]] == 0){
			distCnt++;
		}

        hash[s[right] - 'a']++;

		if(distCnt > k){

			hash[s[left] - 'a']--;

            if (hash[s[left] - 'a'] == 0){
                distCnt--;
            }

            left++;
		}

		int length = right - left + 1;
		maxLen = max(maxLen, length);
		right++;

	}
	return maxLen;

}

int main() {

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n;
    cin >> n;

    string s;
    cin >> s;

    int k;
    cin >> k;

    int result = longSubstring(n, s, k);
    cout << result;

    return 0;
}

// INPUT :

// 11
// aababbcaacc
// 2

// OUTPUT : 6