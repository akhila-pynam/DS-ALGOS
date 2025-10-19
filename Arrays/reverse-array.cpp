#include <bits/stdc++.h>
using namespace std;

void swap(int& x, int& y){

   int temp = x;
   x = y;
   y = temp;

}

void reverse(int n, int arr[]){
    
   int left = 0;
   int right = n-1;
   int mid = (left+right)/2;

   while(left < right){
   	
   	swap(arr[left], arr[right]);
      
      left++;
      right--;

   }

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

	reverse(n , arr);
   
   for(int i=0; i<n; i++){
   	cout << arr[i];
   }


	return 0;

}


// INPUT : 5
//         5 4 3 2 0

// OUTPUT : 0 2 3 4 5 