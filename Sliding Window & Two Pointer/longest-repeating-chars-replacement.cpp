#include <bits/stdc++.h>
using namespace std;

int longestSubarray(int n, string& s, int k) {

// Brutal Solution

    // int maxLen = 0;
    // int maxfreq = 0;

    // for(int i=0; i<n; i++){

    //     int hashFreq[26] = {0};

    //     for(int j=i; j<n; j++){

    //         hashFreq[s[j] - 'A']++;

    //         for(int left=0; left<26; left++){
    //             maxfreq = max(maxfreq, hashFreq[left]);
    //         }

    //         int length = j-i+1;

    //         int changes = length - maxfreq;

    //         if(changes <= k){
    //             maxLen = max(maxLen, length);
    //         }
    //    }

    // }
    // return maxLen;


// Optimal Solution

    int left = 0;
    int right = 0;
    int maxLen = 0;
    int maxfreq = 0;
    int hashFreq[26] = {0};

    while (right < n) {

        hashFreq[s[right] - 'A']++;

        maxfreq = max(maxfreq, hashFreq[s[right] - 'A']);
        
        int length = right - left + 1;
        int changes = length - maxfreq;

        if (changes > k) {
            hashFreq[s[left] - 'A']--;
            left++;
        }

        maxLen = max(maxLen, right - left + 1);
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

    int result = longestSubarray(n, s, k);
    cout << result << endl;

    return 0;
}

// INPUT :

// 9
// AABAAABAC
// 2

// OUTPUT : 8

// INPUT :

// 6
// ABCDEF
// 1

// OUTPUT : 2


// INPUT :

// 4
// ABAB 
// 2

// OUTPUT : 4

