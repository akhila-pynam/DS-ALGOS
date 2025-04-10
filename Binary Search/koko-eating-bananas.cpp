#include <bits/stdc++.h>
using namespace std;

int koko(int mid , int* piles, int n){
    
    int count = 0;

    for(int i=0; i<n; i++){
    	count = count + (piles[i]/mid) + ((piles[i] % mid != 0));
    }
    return count;

}

int kokoEatbananas(int n, int* piles, int hours){
    
    int left = 1;
    int right = 0;

    for(int i=0; i<n; i++){
        right = max(right, piles[i]);
    }

    int ans = -1;
    
    while(left <= right){

    	int mid = (left+right)/2;
    	int time = koko(mid, piles, n);

    	if(time <= hours){
    		ans = mid;
    		right = mid - 1;
    	}
    	else{
    		left = mid + 1;
    	}
    }
    return ans;
}

int main(){
	
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n;
	cin >> n;

	int piles[n];
	for(int i=0; i<n; i++){
		cin >> piles[i];
	}

	int hours;
	cin >> hours;

	int result = kokoEatbananas(n, piles, hours);
	cout << result;

	return 0;

}

// INPUT : 

// 5
// 30 11 23 4 20
// 5

// OUTPUT : 30


// INPUT : 

// 4
// 3 6 7 11
// 8

// OUTPUT : 4