#include <bits/stdc++.h>
using namespace std;


int findPeak(int n, int* array){

// BRUTAL SOLUTION

    // int ans = -1;

    // for(int i=0; i<n; i++){

	//     if(array[i] > array[i-1] && array[i] > array[i+1]){
	//     	ans = array[i];
	//     }

    // }
    // return ans;

// OPTIMAL SOLUTION USING BINARY SEARCH
   
   int left = 0;
   int right = n-1;
   int ans = -1;

   while(left <= right){

   	  int mid = (left + right)/2;

      if((mid == 0 || array[mid] > array[mid - 1]) && (mid == n - 1 || array[mid] > array[mid + 1])){  
   	  	ans = mid;
   	  	left = mid + 1;
   	  }

    else if (mid < n - 1 && array[mid] < array[mid + 1]){
   	  	left = mid + 1;
   	}
   	else{
   	  	right = mid - 1;
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

	int array[n];
	for(int i=0; i<n; i++){
		cin >> array[i];
	}

	int result = findPeak(n, array);
	cout << result;

    return 0;

}