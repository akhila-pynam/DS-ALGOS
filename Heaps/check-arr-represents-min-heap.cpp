#include <bits/stdc++.h>
using namespace std;

bool checkMinheap(int n, int* nums){

    for (int i = 0; i < n; i++) {

        int left = 2*i + 1;
        int right = 2*i + 2;

          if(left < n && nums[i] > nums[left]){
           
            return false;

          }
          if(right < n && nums[i] > nums[right]){
            
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

	bool check = checkMinheap(n, nums);
	
	if(check){
		cout << "true";
	}
	else{
		cout << "false";
	}

	return 0;

}

// INPUT : 

// 5
// 10 20 30 25 15 

// OUTPUT : false


// INPUT :
 
// 5
// 10 20 30 21 23

// OUTPUT : true
