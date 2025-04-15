#include <bits/stdc++.h>
using namespace std;

int distBgastations(int n, double* stations, int k){
    
    int left = 0;
    int right = n-1;
    int ans = -1;

    while(left <= right){

    	int mid = (left + right)/2;
         

    }


}

int main(){
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n;
    cin >> n;

    double stations[n];
    for(double i=0; i<n; i++){
    	cin >> stations[i];
    }

    int k;
    cin >> k;

    double result = distBgastations(n, stations, k);
    cout << result;

    return 0;
}