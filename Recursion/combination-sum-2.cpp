#include <bits/stdc++.h>
using namespace std;

vector<int> dataStore;
set<vector<int>> ans;

void combinations(vector<int>& arr, int target, int n, int ind) {
   
    if(ind == n){
        if (target == 0) {
            ans.insert(dataStore);
        }
        return;
    }    
    

  
    if (arr[ind] <= target) {
        dataStore.push_back(arr[ind]);
        combinations(arr, target - arr[ind], n, ind + 1);
        dataStore.pop_back();
    }

    combinations(arr, target, n, ind + 1);
    
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

    int target;
    cin >> target;

    sort(arr.begin(), arr.end());

    combinations(arr, target, n, 0);

    for (auto& it : ans) {
        for (int num : it) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}


// INPUT : 

// 7
// 10 1 2 7 6 1 5 
// 8

// OUTPUT : 

// 1 1 6 
// 1 2 5 
// 1 7 
// 2 6 


// INPUT : 

// 5
// 2 5 2 1 2
// 5

// OUTPUT : 

// 1 2 2 
// 5 