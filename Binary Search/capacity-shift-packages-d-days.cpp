#include <bits/stdc++.h>
using namespace std;

int pack(int mid, int n, int* weights){
    
    int sum = 0;
    int count = 1;
        for(int i=0; i<n; i++){
            sum = sum + weights[i];
            if(sum > mid){
            	count++;
            	sum = weights[i];
            }
        }
    return count;
}

int capacityShift(int n, int* weights, int days){
    
    int left = 0;
    for(int i=0; i<n; i++){
    	left = max(left, weights[i]);
    }    

    int right = 0;

    for(int i=0; i<n; i++){
    	right = right + weights[i];
    }

    int ans = -1;
    
    while(left <= right){

    	int mid = (left + right)/2;

    	int packages = pack(mid, n, weights);

    	if(packages <= days){
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

	int weights[n];
	for(int i=0; i<n; i++){
		cin >> weights[i];
	}

	int days;
	cin >> days;

	int result = capacityShift(n, weights, days);
	cout << result;

	return 0;

}