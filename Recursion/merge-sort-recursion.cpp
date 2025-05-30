#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int low, int mid, int high){

    vector<int> temp;
    int lft = low;
    int ryt = mid+1;

    while(lft <= mid && ryt <= high){

    	if(arr[lft] <= arr[ryt]){
    		temp.push_back(arr[lft]);
    		lft++;
    	}
    	else{
    		temp.push_back(arr[ryt]);
    		ryt++;
    	}
    }

    while(lft <= mid){
    	temp.push_back(arr[lft]);
    	lft++;
    }
    while(ryt <= high){
    	temp.push_back(arr[ryt]);
    	ryt++;
    }

    for(int i=low; i<=high; i++){
       arr[i] = temp[i - low];
	}

}

void mergeSort(int arr[], int low, int high){
     
    if(low >= high) return;

    int mid = (low + high)/2;

    mergeSort(arr, low, mid);
    mergeSort(arr, mid+1, high);
    merge(arr, low, mid, high);
 
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

	int low = 0;
	int high = n-1;

	mergeSort(arr, low, high);

	for(int i=0; i<n; i++){
		cout << arr[i] << " ";
	}

	return 0;

}

// INPUT :

// 5
// 7 4 1 5 3

// OUTPUT : 1 3 4 5 7