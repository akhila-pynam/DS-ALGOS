#include <bits/stdc++.h>
using namespace std;

vector<int> output;
void printAll(vector<int>& nums, int n, int ind){

    if( ind >= n ){
    	
    	for(int it : output){
    		cout << it << " ";
    	}

    	if(output.size() == 0){
    		cout << "{ }";
    	}

    	cout << endl;

    	return;

    }
    output.push_back(nums[ind]);
    printAll(nums, n, ind+1);
    output.pop_back();
    printAll(nums, n, ind+1);

}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n;
	cin >> n;

	vector<int> nums(n);
	for(int i=0; i<n; i++){
		cin >> nums[i];
	}

	printAll(nums, n, 0);

	return 0;

}


// INPUT : 

// 3
// 3 1 2

// OUTPUT : 

// 3 1 2 
// 3 1 
// 3 2 
// 3 
// 1 2 
// 1 
// 2 
// { }
