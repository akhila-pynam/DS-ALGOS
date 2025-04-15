#include <bits/stdc++.h>
using namespace std;

int nd(int mid, int* Days, int n, int nf) {
  
    int count = 0;
    int nbInitially = 0;

    for (int i = 0; i < n; i++) {
        
        if (Days[i] <= mid) {
            count++;
        } 
        else {
            count = 0;
        }
        if(count == nf){
            nbInitially++;
            count = 0;
        }

    }

    return nbInitially;

}

int minNumdays(int n, int* Days, int nb, int nf) {
    
    int left = 1;
    int right = 0;

    for (int i = 0; i < n; i++) {
        right = max(right, Days[i]);
    }

    int ans = -1;

    while (left <= right) {
        
        int mid = (left + right) / 2;
        int numDays = nd(mid, Days, n, nf);

        if(numDays >= nb){
            ans = mid;
            right = mid - 1;
        } 
        else {
            left = mid + 1;
        }
    }
    return ans;
}

int main() {

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n;
    cin >> n;

    int Days[n];
    for (int i = 0; i < n; i++) {
        cin >> Days[i];
    }

    int nb;
    cin >> nb;

    int nf;
    cin >> nf;

    int result = minNumdays(n, Days, nb, nf);
    cout << result;

    return 0;
}
