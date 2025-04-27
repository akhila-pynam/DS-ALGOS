#include <bits/stdc++.h>
using namespace std;

int maxPoints(int n, int* Cscore, int k){
   
// Brutal Solution 

// 	TC-> O(n + k)
// 	SC-> O(1)

    int lsum = 0;
    int rsum = 0;
    int sum = 0;

	    for(int i=0; i<k; i++){

	        lsum = lsum + Cscore[i];
	    }    

        sum = lsum;

        int rightIndex = n-1;

        for(int j=k-1; j>=0; j--){

        	lsum = lsum - Cscore[j];

        	rsum = rsum + Cscore[rightIndex];

        	rightIndex = rightIndex - 1;

        	sum = max(sum, lsum + rsum);
        }
    
    return sum;

}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n;
	cin >> n;

	int Cscore[n];
	for(int i=0; i<n; i++){
		cin >> Cscore[i];
	}

	int k;
	cin >> k;

	int result = maxPoints(n, Cscore, k);
	cout << result;

	return 0;

}

// INPUT :

// 7
// 1 2 3 4 5 6 1
// 3

// OUTPUT : 12

// INPUT : 

// 3 
// 2 2 2 
// 2

// OUTPUT : 4

