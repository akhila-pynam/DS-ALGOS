#include <bits/stdc++.h>
using namespace std;

bool prime(int i) {
    
    if (i < 2) return false;
    
    for (int j = 2; j * j <= i; j++) {
        if (i % j == 0) return false;
    }

    return true;
}

int main() {
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n;
    cin >> n;

    vector<int> primeFactors;

    for (int i = 2; i <= n; i++) {
       
        if (n % i == 0 && prime(i)) {
           
            primeFactors.push_back(i);
           
            while (n % i == 0) {
                n = n/i;
            }

        }

    }

    for (int factor : primeFactors) {
        cout << factor << " ";
    }
    cout << endl;

    return 0;
}
