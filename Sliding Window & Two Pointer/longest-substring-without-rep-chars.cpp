#include <bits/stdc++.h>
using namespace std;

int longestSubstring(int n, string& s){
    
    int left = 0;
    int right = n-1;
    int maxLen = 0;
    int length = 0;
   
     for(int i=left; i<=right; i++){
       
        int hash[256] = {0};
       
        for(int j=i; j<=right; j++){
          
          if(hash[s[j]] == 1){
            break; 
          } 

          hash[s[j]] = 1;
          length = j-i+1;
          maxLen = max(maxLen, length);   
          
        }             
         
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

    int result = longestSubstring(n, s);
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