// #include <bits/stdc++.h>
// using namespace std;

// vector<vector<int>> out;
// vector<int> ans;

// void allPermutations(vector<int>& freq, int n, vector<int>& arr){

//     if(ans.size() == n){
//     	out.push_back(ans);
//     	return;
//     }
    
//     for(int i=0; i<n; i++){

//     	if(freq[i] == 0){
//     		ans.push_back(arr[i]);
//     		freq[i] = 1;
//     		allPermutations(freq, n, arr);
//     		freq[i] = 0;
//     		ans.pop_back();
//     	}

//     }
// }

// int main(){

// 	#ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
//     #endif

//     int n;
//     cin >> n;

//     vector<int> arr(n);
//     for(int i=0; i<n; i++){
//     	cin >> arr[i];
//     }

//     vector<int> freq(n, 0);

//     allPermutations(freq, n, arr);
    
//     for (auto& nums : out){
//         for (auto it : nums){
//             cout << it << " ";
//         }
//         cout << endl;
//     }   

//     return 0;

// }


// OPTIMAL SOLUTION

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> ans;
void allPermutations(int ind, vector<int>& arr, int n){

    if(ind == n){
    	ans.push_back(arr);
    	return;
    }

    for(int i=ind; i<n; i++){
    	swap(arr[ind], arr[i]);
    	allPermutations(ind+1, arr, n);
    	swap(arr[ind], arr[i]);
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

	allPermutations(0, arr, n);

    for(auto perm : ans){
	    for(auto it : perm){
	    	cout << it << " ";
	    }
	    cout << endl;
	}    

	return 0;

}

// INPUT : 

// 3 
// 1 2 3

// OUTPUT :

// 1 2 3 
// 1 3 2 
// 2 1 3 
// 2 3 1 
// 3 2 1 
// 3 1 2 
