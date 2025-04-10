#include <bits/stdc++.h>
using namespace std;

int nthRootm(int n, int m){
    
    int left = 1;
    int right = m;
    int ans = -1;

    while(left <= right){
       
        int mid = (left + right) / 2;

        ans = pow(mid, n);

        if(ans == m){
           return mid;
           break;
        } 
        else if(ans > m){
            right = mid - 1;
        }
        else if(ans < m){
            left = mid + 1;
        }
    }
    return -1;
}

int main(){
    #ifndef ONLINE_JUDGE    
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n, m;
    cin >> n >> m;

    int result = nthRootm(n, m);
    cout << result;

    return 0;
}

// INPUT : 2 9
// OUTPUT : 3

// INPUT : 3 9
// OUPUT : -1

// INPUT : 1 14
// OUPUT : 14