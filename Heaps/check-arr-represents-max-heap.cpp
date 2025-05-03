#include <bits/stdc++.h>
using namespace std;

bool checkMaxheap(int n, int* nums){
    
    for(int i=0; i<n; i++){

    	int left  = 2*i+1;
    	int right = 2*i+2;

    	if(left < n && nums[left] > nums[i]){
    		return false;
    	}

    	if(right < n && nums[right] > nums[i]){
    		return false;
    	} 

    }
    return true;
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

   int n;
   cin >> n;

   int nums[n];
   for(int i=0; i<n; i++){
   	cin >> nums[i];
   }

   bool check = checkMaxheap(n, nums);

   if(check){
   	cout << "true";
   }
   else{
   	cout << "false";
   }

   return 0;

}

// INPUT : 

// 3
// 10 20 5 

// OUTPUT : false


// INPUT :

// 6
// 20 10 15 8 9 12

// OUTPUT : true