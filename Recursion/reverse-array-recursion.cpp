#include <bits/stdc++.h>
using namespace std;

void swap(int& lft, int& ryt){

    int temp = lft;
    lft = ryt;
    ryt = temp;

}

// void reverse(int arr[], int lft, int ryt){
    
//     if(lft >= ryt) return;

//     swap(arr[lft], arr[ryt]);

//     reverse(arr, lft+1, ryt-1);

// }

void reverse(int arr[], int i, int n){

	if(i >= (n/2)) return;

	swap(arr[i], arr[n-i-1]);

	reverse(arr, i+1, n);

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

	reverse(arr, 0, n);

	for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

	return 0;

}

// INPUT :

// 5 
// 2 3 6 5 4

// OUTPUT : 4 5 6 3 2 