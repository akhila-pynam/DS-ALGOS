#include <bits/stdc++.h>
using namespace std;

// Brute Force Solution

// TC : O(n)
// SC : O(1)

// int largestElement(int arr[], int n){

//     int largest = arr[0];
//     for(int i=0; i<n; i++){
//         if(arr[i] > largest){
//         	largest = arr[i];
//         }
//     }

//     return largest;

// }


// Another Solution I Came Up With By Usinng Priority Queue
// ( But Brute For Is Better Than this Solution )

// TC : O(n*log n)
// SC : O(1)

int largestElement(int arr[], int n){

	priority_queue<int> pq;
	int largest = 0;

    for(int i=0; i<n; i++){
    	pq.push(arr[i]);
    }

    if(pq.size() != 0){
    	largest = pq.top();
    }

    return largest;

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

	int result = largestElement(arr, n);
    
    cout << result;

    return 0;

}

// INPUT : 

// 7
// 56 4 7 8 9 41 2

// OUTPUT : 56