#include <bits/stdc++.h>
using namespace std;

string minimumWindow(int n, string& s, string& t, int m) {
    
    // int minLen = INT_MAX;
    // int sIndex = -1;

    // for (int i=0; i<n; i++) {
        
    //     int hash[256] = {0};

    //     for (int j=0; j<m; j++) {
    //         hash[t[j]]++;
    //     }

    //     int cnt = 0;

    //     for(int j=i; j<n; j++){

    //         if(hash[s[j]] > 0){
    //            cnt++;
    //         }

    //         hash[s[j]]--;

    //         if (cnt == m) {
                        
    //             if (j-i+1 < minLen) {
            
    //                 minLen = j-i+1;
    //                 sIndex = i;
            
    //             }
    //             break;
    //         }
    //     }
    // }

    // if (sIndex == -1) return "";
    // return s.substr(sIndex, minLen);


// Optimal Solution

	int left = 0;
    int right = 0;
    int minLen = INT_MAX;
    int cnt = 0;
    int sIndex = -1;
    int hash[256] = {0};

    for (int j = 0; j < m; j++) {
        hash[t[j]]++;
    }

    while(right < n){
        
        if (hash[s[right]] > 0) {
            cnt++;
        }

        hash[s[right]]--;
        right++;

        while(cnt == m){

            if(right-left+1 < minLen){
               
                minLen = right - left + 1;
                sIndex = left;

            }

            hash[s[left]]++;

            if(hash[s[left]] > 0){
                cnt--;
            }
            left++;
        }
    }

    if (sIndex == -1) return "";
    return s.substr(sIndex, minLen);
}

int main() {

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n;
    cin >> n;

    int m;
    cin >> m;

    string s;
    cin >> s;

    string t;
    cin >> t;

    string result = minimumWindow(n, s, t, m);
    cout << result;

    return 0;
}
