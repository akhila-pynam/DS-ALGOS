#include <bits/stdc++.h>
using namespace std;

void subsetSum(int ind, int n, int sum, vector<int>& arr, vector<int>& sS){

     
    if( ind == n ){
    	sS.push_back(sum);
    	return;
    }

    subsetSum(ind+1, n, sum + arr[ind], arr, sS);

    subsetSum(ind+1, n, sum, arr, sS);
    
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

    vector<int> sS;
	subsetSum(0, n, 0, arr, sS);

    sort(sS.begin(), sS.end());

	for(int it : sS) {
        cout << it << " "; 
    }
    cout << endl;

	return 0;

}


// INPUT : 

// 3 
// 1 2 1 

// OUTPUT : 0 1 1 2 2 3 3 4 
