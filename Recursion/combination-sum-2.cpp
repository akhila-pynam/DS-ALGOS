#include <bits/stdc++.h>
using namespace std;

// BRUTE FORCE SOLUTION

// vector<int> dataStore;
// set<vector<int>> ans;

// void combinations(vector<int>& arr, int target, int n, int ind) {
   
//     if(ind == n){
//         if (target == 0) {
//             ans.insert(dataStore);
//         }
//         return;
//     }    
    
//     if (arr[ind] <= target) {
//         dataStore.push_back(arr[ind]);
//         combinations(arr, target - arr[ind], n, ind + 1);
//         dataStore.pop_back();
//     }

//     combinations(arr, target, n, ind + 1);

// }


// OPTIMAL SOLUTION : ( Hard For Me So I Choose Above & Down Solution Not Optimal )

// vector<int> dataStore;
// vector<vector<int>> ans;

// void combinations(vector<int>& arr, int target, int n, int ind){
     
//     if(target == 0){
//         ans.push_back(dataStore);
//         return;
//     }


//     for(int i=ind; i<n; i++){

//         if(i > ind && arr[i] == arr[i-1]) continue;
//         if(arr[ind] > target) break;

//         dataStore.push_back(arr[i]);
//         combinations(arr, target - arr[i], n, i+1);
//         dataStore.pop_back();

//     }
 

// }


// BETTER SOLUTION

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
        combinations(arr, target - arr[ind], n, ind+1);
        dataStore.pop_back();
    }
    
    while(ind + 1 < n && arr[ind] == arr[ind + 1]){
        ind++;
    }  

    combinations(arr, target, n, ind+1); 

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