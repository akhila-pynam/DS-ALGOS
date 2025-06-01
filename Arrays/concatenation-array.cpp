#include <bits/stdc++.h>
using namespace std;

int concatenation(vector<int>& arr, int n){

    // TC : 2 for Loops O(2n)+ Printing Loop O(n) -> O(n)
    // SC : O(1)

    vector<int> output;

    for(int i=0; i<n; i++){
       output.push_back(arr[i]);
    }
    for(int i=0; i<n; i++){
       output.push_back(arr[i]);
    }

    for(int nums : output){
    	cout << nums << " ";
    }

}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n;
	cin >> n;

    vector<int> arr(n);
    for(int i=0; i<n; i++){
    	cin >> arr[i];
    }

    concatenation(arr, n);

    return 0;

}


// INPUT : 

// 5
// 2 3 6 4 7

// OUTPUT : 2 3 6 4 7 2 3 6 4 7 