#include <bits/stdc++.h>
using namespace std;

long long transportCost(int n, int m, int k){

    long len1;
    long len2;

    long tCst;
    long x;

    if(n <= k && m <= k){
        return 0;
    }

    if(n > k){
      
	    len1 = n - k;
	    len2 = n - len1;

	    tCst = len1*len2;
	    x = len1 + len2;

        if(x == k){
          cout << tCst;
        }

    }
    else{

    	len1 = m - k;
    	len2 = m - len1;

    	tCst = len1*len2;
        x = len1 + len2;

    	if(x == k){
    		cout << tCst;
    	}

    }

    return tCst;

}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n;
	cin >> n;

	int m;
	cin >> m;

	int k;
	cin >> k;

	transportCost(m, n, k);

	cout << transportCost(m, n, k);

	return 0;

}


// INPUT : 

// 4 
// 4
// 6

// OUTPUT : 0


// INPUT :
// 6 
// 5 
// 5

// OUTPUT : 5