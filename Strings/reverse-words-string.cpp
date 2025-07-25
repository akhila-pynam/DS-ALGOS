#include <bits/stdc++.h>
using namespace std;

void swap(char &lft, char &ryt) {
    char temp = lft;
    lft = ryt;
    ryt = temp;
}

void reverseString(string &s) {
    int lft = 0;
    int ryt = s.size() - 1;

    while (lft < ryt) {
        swap(s[lft], s[ryt]);
        lft++;
        ryt--;
    }
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    string s;
    cin >> s;

    reverseString(s);

    for (int i = 0; i < s.size(); i++) {
        cout << s[i] << endl;  
    }

    return 0;
}
