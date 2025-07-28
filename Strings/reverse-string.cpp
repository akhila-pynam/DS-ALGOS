#include <bits/stdc++.h>
using namespace std;

void reverseString(int n, string s, vector<string>& output){
    
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            while (j < n) {
                while (j < n && s[j] == ' ') j++;
                
                if (j >= n) break;

                j = i;
                while (j < n && s[j] == ' ') j++;

                j = i - 1;
                output.push_back(string(1, s[j]));
                
            }
        }
    }
}

int main() {
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n;
    cin >> n;

    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
    }

    vector<string> output;

    reverseString(n, s, output);

    for (auto it : output) {
        cout << it << " ";
    }

    return 0;
}
