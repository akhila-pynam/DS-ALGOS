#include <bits/stdc++.h>
using namespace std;

void funcRev(int i, int arr[], int n){
    
    if(i >= n/2) return;

    swap(arr[i], arr[n-i-1]);
    funcRev(i+1, arr, n); 

}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n;
	cin >> n;

	int arr[n];
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}

	funcRev(0, arr, n);

	for(int i=0; i<n; i++){
		cout << arr[i] << " ";
	}

	return 0;

}

// INPUT : 5
//         5 4 3 2 0
// OUTPUT : 0 2 3 4 5