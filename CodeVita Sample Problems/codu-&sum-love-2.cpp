#include <bits/stdc++.h>
using namespace std;

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int N;
    cin >> N;

    long long sum = 0;

    for(int i=0; i<N; i++){

        long long x;
        cin >> x;

        int val = pow((1 << 2), x);

        string str = to_string(val);

        if (str.size() > 2) str = str.substr(str.size() - 2);
        sum = sum + stoi(str);

    }

    cout << (sum % 100) << endl;
    return 0;

}