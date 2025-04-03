#include <bits/stdc++.h>
using namespace std;

vector<int> allDivisors(int n) {
    
    vector<int> divisors;
    
    for (int i = 1; i * i <= n; i++) {
       
        if (n % i == 0) {
           
            divisors.push_back(i);
           
            if (i != n / i) {
                divisors.push_back(n / i);
            }

        }
    }
    
    sort(divisors.begin(), divisors.end());

    return divisors;
}

int main() {
   
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n;
    cin >> n;

    vector<int> divisors = allDivisors(n);

    for (int divisor : divisors) {
        cout << divisor << " ";
    }
    cout << endl;

    return 0;
}
