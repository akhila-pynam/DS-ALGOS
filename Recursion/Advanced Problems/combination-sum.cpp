#include <bits/stdc++.h>
using namespace std;

vector<int> dataStore;
vector<vector<int>> ans;

void combinations(vector<int>& arr, int target, int n, int ind){
   
    if(ind == n){
        if (target == 0) {
            ans.push_back(dataStore);
        }
        return;
    }

    if(arr[ind] <= target){
        dataStore.push_back(arr[ind]);
        combinations(arr, target - arr[ind], n, ind);
        dataStore.pop_back();
    }

    combinations(arr, target, n, ind + 1);

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

    int target;
    cin >> target;

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

// 3 
// 2 3 5 
// 8

// OUTPUT : 

// 2 2 2 2 
// 2 3 3 
// 3 5 

