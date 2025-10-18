#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> out;
vector<int> temp;

void subsets(int ind, int n, vector<int>& arr) {
    
    if (ind == n){
        out.push_back(temp);
        sort(out.begin(), out.end());
        return;
    }
    
    if(ind < n){
	    temp.push_back(arr[ind]);
	    subsets(ind + 1, n, arr);
	    temp.pop_back();
    } 

    while(ind + 1 <= n && arr[ind] == arr[ind + 1]){
        ind++;
    }

    subsets(ind + 1, n, arr);

}

int main() {

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

    subsets(0, n, arr);

    for (auto& nums : out){
        for (auto it : nums){
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

// []
// 1 
// 1 2 
// 1 2 3 
// 1 3 
// 2 
// 2 3 
// 3 
