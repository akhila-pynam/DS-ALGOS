#include <bits/stdc++.h>
using namespace std;

void primeFacsieve(int n) {
	
    vector<int> prime(n + 1, 0);
    vector<int> primeFactors;

    for (int i = 2; i * i <= n; i++) {
        if (prime[i] == 0) {
            for (int j = i * i; j <= n; j += i) {
                prime[j] = 1;
            }
        }
    }

    for (int i = 2; i <= n; i++) {
        if (prime[i] == 0 && n % i == 0) {
            primeFactors.push_back(i);
            while (n % i == 0) {
                n /= i;
            }
        }
    }

    for (int i : primeFactors) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

    int n; 
    cin >> n;

    primeFacsieve(n);

    return 0;
}

